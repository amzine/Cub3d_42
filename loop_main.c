/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:18:00 by aachaq            #+#    #+#             */
/*   Updated: 2023/05/21 10:55:50 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_pixel_to_image(t_data *data1, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1200 || y >= WINDOW_HEIGHT)
		return ;
	dst = data1->addr + (y * data1->line_length + x * (data1->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	getcolor(float ray_x, float ray_y, t_data *tex, int *arg)
{
	int		color;
	int		texture_x;
	int		texture_y;
	char	*dst;

	texture_x = ((int)(ray_x + ray_y) % SIZE_WALL) * tex->width / SIZE_WALL;
	texture_y = ((((int)arg[2] - arg[1]) * tex->height) / arg[0]);
	color = 0;
	if (texture_x >= 0 && texture_y >= 0 && texture_x < tex->width
		&& texture_y < tex->height)
	{
		dst = tex->addr + (texture_y * tex->line_length + texture_x
				* (tex->bits_per_pixel / 8));
		color = *(unsigned int *)dst;
	}
	free(arg);
	return (color);
}

void	partie1(t_game *g, t_loop *loop)
{
	loop->ray_x = g->pl.x;
	loop->ray_y = g->pl.y;
	while (1)
	{
		if (g->map[(int)(loop->ray_y / SIZE_WALL)][(int)(loop->ray_x
				/ SIZE_WALL)] == '1')
			break ;
		loop->ray_x += cos(loop->ray_angle * M_PI / 180) / 9;
		loop->ray_y += sin(loop->ray_angle * M_PI / 180) / 9;
	}
	loop->distance = sqrt(pow(loop->ray_y - g->pl.y, 2) + pow(loop->ray_x
				- g->pl.x, 2));
	loop->distance = loop->distance * cos((loop->ray_angle - g->pl.angle_player)
			* M_PI / 180);
	loop->wall_hight = (1 / loop->distance) * 30000;
	loop->start = WINDOW_HEIGHT / 2 - loop->wall_hight / 2;
	loop->end = loop->start + loop->wall_hight;
	loop->start_ciel = -1;
	loop->start_2 = loop->start;
}

void	partie2(t_game *g, t_loop *loop)
{
	while (loop->y < loop->end_2)
	{
		if (g->map[(int)((loop->ray_y - 1) / SIZE_WALL)][(int)(loop->ray_x
				/ SIZE_WALL)] == '1' && g->map[(int)((loop->ray_y + 1)
				/ SIZE_WALL)][(int)(loop->ray_x / SIZE_WALL)] == '0')
			loop->color = getcolor(loop->ray_x, loop->ray_y, &(g->tex1),
					arg(loop->y, loop->wall_hight, loop->start));
		else if (g->map[(int)((loop->ray_y) / SIZE_WALL)][(int)((loop->ray_x
						+ 1) / SIZE_WALL)] == '1' && g->map[(int)((loop->ray_y)
					/ SIZE_WALL)][(int)((loop->ray_x - 1) / SIZE_WALL)] == '0')
			loop->color = getcolor(loop->ray_x, loop->ray_y, &(g->tex2),
					arg(loop->y, loop->wall_hight, loop->start));
		else if (g->map[(int)((loop->ray_y) / SIZE_WALL)][(int)((loop->ray_x
						+ 1) / SIZE_WALL)] == '0' &&
					g->map[(int)((loop->ray_y) / SIZE_WALL)][(int)((loop->ray_x
								- 1) / SIZE_WALL)] == '1')
			loop->color = getcolor(loop->ray_x, loop->ray_y, &(g->tex3),
					arg(loop->y, loop->wall_hight, loop->start));
		else
			loop->color = getcolor(loop->ray_x, loop->ray_y, &(g->tex4),
					arg(loop->y, loop->wall_hight, loop->start));
		put_pixel_to_image(&(g->data), loop->i, loop->y, loop->color);
		loop->y++;
	}
}

void	loop_main_2(t_game *g)
{
	t_loop	loop;

	loop.i = 0;
	loop.ray_angle = g->pl.angle_player - (CHAMP_DE_VISION / 2);
	while (loop.i < WINDOW_WIDTH)
	{
		partie1(g, &loop);
		if (loop.start < 0)
			loop.start_2 = 0;
		loop.end_2 = loop.end;
		if (loop.end >= WINDOW_HEIGHT)
			loop.end_2 = WINDOW_HEIGHT;
		while (++loop.start_ciel < loop.start)
			put_pixel_to_image(&(g->data), loop.i, loop.start_ciel,
				g->tex.ceiling);
		loop.y = loop.start_2;
		partie2(g, &loop);
		loop.end = loop.end - 1;
		while (++loop.end < WINDOW_HEIGHT)
			put_pixel_to_image(&(g->data), loop.i, loop.end, g->tex.floor);
		loop.ray_angle += (float)CHAMP_DE_VISION / WINDOW_WIDTH;
		loop.i++;
	}
}
