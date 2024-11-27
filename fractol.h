/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:52:11 by rhiguita          #+#    #+#             */
/*   Updated: 2024/11/27 22:02:21 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>


# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGTH 800
// COLORS..
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0x00FF00
# define GREEN 0x00FF00
# define BLUE 0x0000FF
//  PSYCHEDELIC COLORS...
# define MAGENTA 0xFF00FF
# define NEON_GREEN 0x39FF14
# define ELECTRIC_BLUE 0x0000FF
# define NEON_YELLOW 0xFFFF00
# define BRIGHT_ORANGE 0xFFA500
# define NEON_PINK 0xFF1493
# define BRIGHT_CYAN 0x00FFFF
# define CRIMSON_RED 0xDC143C
/*
# define DEEP_VIOLET 0x8A2BE2
# define LIME 0xBFFF00
# define ELECTRIC_TURQUOISE 0x30D5C8
# define ACID_GREEN 0xA7FC00
# define FLUORESCENT_PINK 0xFF66CC
# define PSYCHEDELIC_ORANGE 0xFF4500
# define VIBRANT_PURPLE 0x9B30FF
# define BRIGHT_INDIGO 0x4B0082
# define MINT_GREEN 0x98FF98
# define ELECTRIC_YELLOW 0xEEDD82
# define HOT_PINK 0xFF69B4
# define NEON_EMERALD 0x50C878
*/

typedef struct s_complex
{
    //      real;
    double  x;
    //      imaginary
    double  y;
}   t_complex;

typedef struct s_img
{
    void    *img_ptr;
    char    *pixel;
    int     bpp;
    int     endian;
    int     line_len;
}   t_img;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    t_img   img;
    char    *name;
    double  escape_value;
    double  zoom;
    int     itera;
    double  change_x;
    double  change_y;
    double  jul_x;
    double  jul_y;
}   t_data;



//main..
int ft_strncmp(char *s1, char *s2, size_t n);
void    ft_putstr_fd(char *s, int fd);
//init..
void    fractal_init(t_data *data);
//render..
void    fractal_render(t_data *data);
//math..
double  scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex Z1, t_complex Z2);
t_complex   square_complex(t_complex Z);
//hook events..
int    key_handler(int keysym, t_data *data);
// clean_up
int close_handler(t_data *data);
int mouse_handler(int button, int x, int y, t_data *data);
int julia(int x, int y, t_data *data);
double  atodbl(char *s);

#endif
