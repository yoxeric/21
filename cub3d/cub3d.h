/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:07:33 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/04 17:18:33 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "utils/get_next_line.h"
# include <string.h>
# define BPP sizeof(int32_t)

# define WIDTH 1920
# define HEIGHT 1080
# define DEFAULT_COLOR "0xFFFFFFFF"
# define PI 3.14159265359
# define P2 1.57079632679
# define P3 4.71238898038
# define DR 0.0174533
# define TR 57.2957795131

typedef struct s_rgb {
		int		r;
		int		g;
		int		b;
		int		a;
}       t_rgb;

typedef struct s_v3c {
        int		x;
        int		y;
        int		z;
        t_rgb   c;
}       t_vector3color;

typedef struct s_v3i {
        int   x;
        int   y;
        int   z;
}       t_vector3i;

typedef struct s_v3 {
        float   x;
        float   y;
        float   z;
}       t_vector3f;

typedef struct s_v2i {
        int     x;
        int     y;
}       t_vector2i;

typedef struct s_v2 {
        float     x;
        float     y;
}       t_vector2f;

typedef struct s_plot {
        t_vector2i	v;
        t_vector2i	d;
        t_vector2i	s;
        int			err;
        int			e2;
}       t_plot;

typedef struct	s_map {
	mlx_image_t		*img;
	t_vector2i		size;
	float			scale;
	char			**map;
	unsigned int	col[2];
	mlx_texture_t	*tex[4];
	mlx_image_t		*tex_img[4];
}		t_map;

typedef	struct	s_player {
	t_vector2f		pos;
	t_vector2f		img_pos;
	t_vector2f		img_mult;
	float			rot;
	mlx_texture_t	*tex;
	mlx_image_t 	*img;
}		t_player;

typedef	struct	s_ray {
	t_vector2f	ray;
	t_vector2f	step;
	t_vector2i	tile;
	t_vector2f	pos_in_tile;
	float		angel_step;
	float		dst;
	float		wall_height;
	float		angel;
	int			dof;
}		t_ray;

typedef struct s_game {
	t_map			map;
	t_player		player;
	int				width;
	int				height;
	int				tile_size;
	int				column_size;
	int				fov;
	mlx_texture_t	*tex;
	mlx_image_t		*img;
	mlx_t			*mlx;
}               t_game;

char	*get_next_line(int fd);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
void	draw_lineDDA(mlx_image_t *img, t_vector3color p1, t_vector3color p2);
t_rgb	int2rgb(long long int mono);
int		rgb2int(t_rgb c);
void	*ft_memmove(void *dst, void *src, size_t len);
int		parsing_main(t_game *game, char *map);
int 	map_check(int fd, t_game *game);
char	*ft_strdup( char *s1);
void    ft_bzero(void *s, size_t n);
void	free_arr(char **ar);
int		rgb2int(t_rgb c);
int     ft_strncmp( char *s1, char *s2, size_t n);

float	circle(float fish);
float	pythagoras(float a, float b);

void	move_up(t_game *game, t_vector2f pd);
void	move_down(t_game *game, t_vector2f pd);
void	move_right(t_game *game, t_vector2f pd);
void	move_left(t_game *game, t_vector2f pd);

float	scale(t_game *game);
void	resize(int width, int height, void *param);
void	draw_circle(mlx_image_t *img, t_vector2i center, int r, int clr);
void	draw_rays(t_game *game, t_vector2f ray);
void	draw_cube(mlx_image_t *img, t_vector2i start, t_vector2i end, int color);
void    draw_line(mlx_image_t *img, t_vector2f p0, t_vector2f p1, int clr);
void	draw_texture(t_game *game, t_ray ray, t_vector2i a);
void	player_to_image(t_game *game, t_vector2i img_pos, float sx, float sy);
void	draw_player(t_game *game);
void	draw_colum(t_game *game, int x, t_ray ray);
void	draw_walls(t_game *game);
void	draw_game(t_game *game);
void	draw_map(t_game *game);
void	rycasting(t_game *game);

int		space_tabe(char c);
int     ft_isdigit(int c);
int		rgb_check(char *rgb);
int		space_tabe(char c);
int		finished_that_check(int *result);
void	fill_int_arry_with_zero(int *result);
int		colors(char *line, int indx, int *result, t_game *game);
void	free_arr(char **ar);
int		tallest_line_length(char **map);
char	**arrjoin(char **ar, char *line, int size);
int		check_line(char *line);
void	calloc_the_array(char ***ar, char *rgb, char **pntr);

#endif
