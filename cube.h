/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:05:35 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/22 23:01:46 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SIZE 7
# define WIN_H 480
# define WIN_W 640
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1200
# define SIZE_WALL 50
# define CHAMP_DE_VISION 60

typedef enum e_cub_err
{
	end,
	inv_argc,
	inv_ext,
	inv_file,
	empty_file,
	no_memory,
	inv_wall,
	inv_map,
	inv_charc,
	inv_player,
	inv_tex,
	inv_pwd,
	inv_color
}					t_cub_err;

typedef struct s_img
{
	int				height;
	int				width;
	void			*i;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endi;
}					t_img;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

typedef struct s_color
{
	long			t;
	long			r;
	long			g;
	long			b;
}					t_color;

typedef struct s_rex
{
	t_list			*n;
	t_list			*n_bak;
	t_list			*s;
	t_list			*s_bak;
	t_list			*w;
	t_list			*w_bak;
	t_list			*e;
	t_list			*e_bak;
	t_img			*b;
	int				floor;
	int				ceiling;
}					t_rex;

typedef struct s_player
{
	float			x;
	float			y;
	char			dir;
	float			speed;
	float			angle_player;
	int				door_cooldown;
}					t_player;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct s_loop
{
	int				i;
	float			ray_angle;
	float			ray_x;
	float			ray_y;
	float			distance;
	float			wall_hight;
	int				start;
	int				end;
	int				start_ciel;
	int				start_2;
	int				end_2;
	int				color;
	int				y;
}					t_loop;

typedef struct s_game
{
	char			**pathtex;
	int				fd;
	char			**map;
	int				height;
	int				width;
	void			*mlx_ptr;
	void			*win_ptr;
	float			x;
	float			y;
	t_img			win_img;
	t_img			win_g;
	t_img			win_r;
	t_img			*scope;
	t_rex			tex;
	t_player		pl;
	int				memoire;
	int				c_comma;
	t_data			data;
	t_data			tex1;
	t_data			tex2;
	t_data			tex3;
	t_data			tex4;
}					t_game;

void				ft_free_matrix(char ***m);

void				end_cube(t_game *g);
void				cf_color(char **dir, t_game *g);
int					cub_atoi(const char *nptr, long *nbr);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *newnode);
t_img				*mlx_load_img(void *ptr, char *path);
int					cube_error(t_cub_err err, t_game *g, char *param, int c);
void				read_map(char *file, t_game *g);
void				ft_free_matrix(char ***m);
int					matrix_len(char **m);
void				ft_lstadd_back(t_list **lst, t_list *newnode);
char				**extand_matrix(char **in, char *newstr);
void				list_add_back(t_list **list, t_list *newnode);
t_list				*ft_lstnew(void *content);
void				check_elements(t_game *g);
char				**map_squared(t_game *g);
void				check_map(t_game *g);
void				raycast(t_game *g);
void				loop_main_2(t_game *g);
void				ws_event(int keycode, t_game *g);
void				ad_event(int keycode, t_game *g);
int					function_event(int keyCode, t_game *g);
int					exit_program(t_game *g);
int					*arg(int y, int wall_hei, int start);
void				check_texture2(char **dir, t_game *g, int n[1][2], int k);
void				init_map(char *line[2], t_game *g, int n[1][2], int k);
void				check_textures(char *trim, t_game *g, int n[0][2], int k);
void				trimspaces(char *str);
t_list				*get_anim(t_img *img, t_list **anim, int n[1][2]);
#endif