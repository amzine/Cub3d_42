/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:10:52 by aachaq            #+#    #+#             */
/*   Updated: 2023/05/22 09:44:58 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	loop_main(t_game *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	loop_main_2(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->data.img, 0, 0);
	return (0);
}

void	player_position(t_game *g)
{
	if (g->pl.dir == 'N')
		g->pl.angle_player = 0;
	else if (g->pl.dir == 'E')
		g->pl.angle_player = 90;
	else if (g->pl.dir == 'W')
		g->pl.angle_player = -90;
	else if (g->pl.dir == 'S')
		g->pl.angle_player = 180;
}

int	on_mouse_move(int x, int y, t_game *g)
{
	(void)y;
	if (x - g->memoire > 4)
		g->pl.angle_player += 200 * M_PI / 180;
	else if (x - g->memoire < -4)
		g->pl.angle_player -= 200 * M_PI / 180;
	g->memoire = x;
	return (0);
}

void	init_texters(t_game *g)
{
	g->win_ptr = mlx_new_window(g->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3d");
	g->data.img = mlx_new_image(g->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	g->data.addr = mlx_get_data_addr(g->data.img, &(g->data.bits_per_pixel),
			&(g->data.line_length), &(g->data.endian));
	g->tex1.img = mlx_xpm_file_to_image(g->mlx_ptr, g->pathtex[0],
			&g->tex1.width, &g->tex1.height);
	g->tex1.addr = mlx_get_data_addr(g->tex1.img, &(g->tex1.bits_per_pixel),
			&(g->tex1.line_length), &(g->tex1.endian));
	g->tex2.img = mlx_xpm_file_to_image(g->mlx_ptr, g->pathtex[1],
			&(g->tex2.width), &(g->tex2.height));
	g->tex2.addr = mlx_get_data_addr(g->tex2.img, &(g->tex2.bits_per_pixel),
			&(g->tex2.line_length), &(g->tex2.endian));
	g->tex3.img = mlx_xpm_file_to_image(g->mlx_ptr, g->pathtex[2],
			&(g->tex3.width), &(g->tex3.height));
	g->tex3.addr = mlx_get_data_addr(g->tex3.img, &(g->tex3.bits_per_pixel),
			&(g->tex3.line_length), &(g->tex3.endian));
	g->tex4.img = mlx_xpm_file_to_image(g->mlx_ptr, g->pathtex[3],
			&(g->tex4.width), &(g->tex4.height));
	g->tex4.addr = mlx_get_data_addr(g->tex4.img, &(g->tex4.bits_per_pixel),
			&(g->tex4.line_length), &(g->tex4.endian));
}

void	raycast(t_game *g)
{
	g->pl.x = g->pl.x * SIZE_WALL;
	g->pl.y = g->pl.y * SIZE_WALL;
	player_position(g);
	init_texters(g);
	mlx_hook(g->win_ptr, 2, 0, function_event, g);
	mlx_hook(g->win_ptr, 6, 0, on_mouse_move, g);
	mlx_hook(g->win_ptr, 17, 0, exit_program, g);
	mlx_loop_hook(g->mlx_ptr, loop_main, g);
	mlx_loop(g->mlx_ptr);
}
