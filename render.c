#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixel + offset) = color;
}

static void madelbrot_or_julia(t_complex *Z, t_complex *C, t_data *data)
{
    if (!ft_strncmp(data->name, "julia", 5))
    {
        C->x = data->jul_x;
        C->y = data->jul_y;
    }
    else
    {
        C->x = Z->x;
        C->y = Z->y;
    }
}

static int interpolate_color(int color1, int color2, double factor)
{
    int red;
    int green;
    int blue;

    red = ((color1 >> 16) & 0xFF) + factor * (((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF));
    green = ((color1 >> 8) & 0xFF) + factor * (((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF));
    blue = (color1 & 0xFF) + factor * ((color2 & 0xFF) - (color1 & 0xFF));
    return ((red << 16) | (green << 8) | blue);
}

static void    handle_pixel(int x, int y, t_data *data)
{
    t_complex   Z;
    t_complex   C;
    int         i;
    double      factor;
    int         color;

    i = 0;
    //1 iteration:
    Z.x = (scale(x, -2, +2, 0, WINDOW_WIDTH) * data->zoom) + data->change_x;
    Z.y = (scale(y, -2, +2, 0, WINDOW_HEIGTH) * data->zoom) + data->change_y;

    madelbrot_or_julia(&Z, &C, data);

    while (i < data->itera)
    {
        // actual Z² + C;
        // Z = Z² + C;
        Z = sum_complex(square_complex(Z), C);

        // Is the value escaped;??
        if ((Z.x * Z.x) + (Z.y * Z.y) > data->escape_value)
        {
            factor = (double)i / data->itera;
            if (factor < 0.33)
                color = interpolate_color(0xFFFF66, 0xFF4500, factor / 0.33);
            else if (factor < 0.66)
                color = interpolate_color(0xFF00FF, 0x4B0082, (factor / 0.33) / 0.33);
            else 
                color = interpolate_color(0x00FFFF, 0x39FF14, (factor / 0.66) / 0.34);

            my_pixel_put(x, y, &data->img, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &data->img, 0x0B0C10);
}

void    fractal_render(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (++y < WINDOW_HEIGTH)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            handle_pixel(x, y, data);
            ++x;
        }
        ++y;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
