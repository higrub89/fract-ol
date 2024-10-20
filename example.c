/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:38:53 by rhiguita          #+#    #+#             */
/*   Updated: 2024/10/20 18:14:04 by rhiguita         ###   ########.fr       */
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

void    render_background(t_data *data, int color)
{
    int i;
    int j;

    if (data->win_ptr == NULL)
        return ;
    i = 0;
    while (i > WINDOW_HEIGTH)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
        ++i;
    }  
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
        j = rect.x;
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
    render_background(data, ORANGE_PIXEL);
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