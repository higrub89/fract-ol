#include "fractol.h"
static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

static void data_init(t_data *data)
{
    data->escape_value = 4; // 2² my hypotenuse;
    data->itera = 40;
    data->change_x = 0.0;
    data->change_y = 0.0;
    data->zoom = 1.0;
}

static int  fractal_render_hook(void *param)
{
    fractal_render((t_data *) param);
    return (0);
}

static void events_init(t_data *data)
{
    mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
    mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_handler, data);
    mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_handler, data);
    mlx_hook(data->win, MotionNotify, PointerMotionMask, julia, data);
    mlx_expose_hook(data->win, fractal_render_hook, data);
}
/*
INIT
-mlx
-listening events
-hooks data
*/
void    fractal_init(t_data *data)
{
    data->mlx = mlx_init();
    if (NULL == data->mlx)
        malloc_error();
    data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGTH, data->name);
    if (NULL == data->win)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        malloc_error();
    }
    data->img.img_ptr = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
    if (NULL == data->img.img_ptr)
    {
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        malloc_error();
    }
    data->img.pixel = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.line_len, &data->img.endian);
    events_init(data);
    data_init(data);
    fractal_render(data);
}