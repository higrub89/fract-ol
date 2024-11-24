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

static void    handle_pixel(int x, int y, t_data *data)
{
    t_complex   Z;
    t_complex   C;
    int         i;
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
            color = scale(i, BLACK, WHITE, 0, data->itera);
            my_pixel_put(x, y, &data->img, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &data->img, WHITE);
}

void    fractal_render(t_data *data)
{
    int x;
    int y;

    y = -1;
    while (++y < WINDOW_HEIGTH)
    {
        x = -1;
        while (++x < WINDOW_WIDTH)
        {
            handle_pixel(x, y, data);
        }   
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
