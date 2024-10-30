/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:38:53 by rhiguita          #+#    #+#             */
/*   Updated: 2024/10/27 18:29:23 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGTH 300

#define MLX_ERROR 1
#define BLUE_PIXEL 0x1A1A40
#define ORANGE_PIXEL 0xFF0000
#define GREEN_PIXEL 0x88FF5E
#define YELLOW_PIXEL 0xFFC300

typedef struct  s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_data;

typedef struct  s_rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
    int plus;
    int minus;
}   t_rect;

void	render_background(t_data *data, int color)
{
    int	i;
    int	j;

    if (data->win_ptr == NULL)
        return ;
    i = 0;
    while (i < 450)
    {
        j = 0;
        while (j < 700)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
        ++i;
    }
}

// void    render_background(t_data *data, int color)
// {
//     int i;
//     int j;

//     if (data->win_ptr == NULL)
//         return ;
//     i = 0;
//     while (i > WINDOW_HEIGTH)
//     {
//         j = 0;
//         while (j < WINDOW_WIDTH)
//             mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x1A1A40);
//         ++i;
//     }  
// }

int render_background2(t_data *data, t_rect rect)
{
    int i;
    int j;
    printf("hola");
    if (data->win_ptr == NULL)
        return (1);
    i = 10;
    while (i < WINDOW_HEIGTH + 300)
    {
        j = 10;
        while (j < WINDOW_WIDTH + 300)
        {
             mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        }
        ++i;
    }
    return (0);
}

int render_rectangule(t_data *data, t_rect rect)
{
    int i;
    int j;
    
    if (data->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;data->win_ptr, j++, i, rect.color;
        while (j < rect.x + rect.width * 2)
        {
             mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        }
        ++i;
    }
    return (0);
}

int render(t_data *data, int size, int i, int j)
{
    render_background(data, 0xFAAFFDD);
    //render_background2(data, (t_rect){WINDOW_WIDTH -100, WINDOW_HEIGTH -100, 200, 200, 0x1A1A40});
    render_rectangule(data, (t_rect){WINDOW_WIDTH -100, WINDOW_HEIGTH -100, 200, 200, YELLOW_PIXEL});
    return (0);
}

int main()
{
    t_data data;
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, 700, 450, "Tutorial");
    
    data.mlx_ptr = mlx;
    data.win_ptr = win;

    render(&data, 0, 0, 0);
    mlx_loop(mlx);
}

int	handle_keypress(int keysym, struct s_windows *fract)
{
	if (keysym == XK_Escape)
		close_handler(fract);
	if (keysym == XK_Left)
		fract->move_x += 0.05 * (1 / fract->zoom);
	if (keysym == XK_Up)
		fract->move_y -= 0.05 * (1 / fract->zoom);
	if (keysym == XK_Right)
		fract->move_x -= 0.05 * (1 / fract->zoom);
	if (keysym == XK_Down)
		fract->move_y += 0.05 * (1 / fract->zoom);
	if (keysym == 65451)
		fract->iterations += 1;
	if (keysym == 65453)
		fract->iterations -= 1;
	printf("Keypress: %i\n", keysym);
	printf("zoom: %f\n", fract->zoom);
	render(fract);
	return (0);
}