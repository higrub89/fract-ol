#include "fractol.h"

int close(t_data *d)
{
    mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_image(d->mlx, d->win);
}