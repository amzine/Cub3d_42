/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:18:51 by aachaq            #+#    #+#             */
/*   Updated: 2023/05/22 21:59:49 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ws_event(int keycode, t_game *g)
{
	if (keycode == 13)
	{
		g->pl.x = g->pl.x + cos(g->pl.angle_player * M_PI / 180) * 5;
		g->pl.y = g->pl.y + sin(g->pl.angle_player * M_PI / 180) * 5;
	}
	else if (keycode == 1)
	{
		g->pl.x = g->pl.x - cos(g->pl.angle_player * M_PI / 180) * 5;
		g->pl.y = g->pl.y - sin(g->pl.angle_player * M_PI / 180) * 5;
	}
}

void	ad_event(int keycode, t_game *g)
{
	if (keycode == 0)
	{
		g->pl.x = g->pl.x + sin((g->pl.angle_player) * M_PI / 180) * 5;
		g->pl.y = g->pl.y - cos((g->pl.angle_player) * M_PI / 180) * 5;
	}
	else if (keycode == 2)
	{
		g->pl.x = g->pl.x - sin((g->pl.angle_player) * M_PI / 180) * 5;
		g->pl.y = g->pl.y + cos((g->pl.angle_player) * M_PI / 180) * 5;
	}
}

void	adws_events(int keyCode, t_game *g)
{
	if (keyCode == 13 && g->map[(int)(g->pl.y + sin(g->pl.angle_player * M_PI
				/ 180) * 5) / SIZE_WALL][(int)(g->pl.x + cos(g->pl.angle_player
				* M_PI / 180) * 5) / SIZE_WALL] != '1' && g->map[(int)(g->pl.y
			+ sin((g->pl.angle_player + (1000 * M_PI / 180) * 3) * M_PI / 180)
			* 5) / SIZE_WALL][(int)(g->pl.x + cos((g->pl.angle_player + (1000
						* M_PI / 180) * 3) * M_PI / 180) * 5)
		/ SIZE_WALL] != '1')
		ws_event(keyCode, g);
	else if (keyCode == 1 && g->map[(int)(g->pl.y - sin(g->pl.angle_player
				* M_PI / 180) * 5) / SIZE_WALL][(int)(g->pl.x
				- cos(g->pl.angle_player * M_PI / 180) * 5) / SIZE_WALL] != '1')
		ws_event(keyCode, g);
	else if (keyCode == 0 && g->map[(int)(g->pl.y - cos((g->pl.angle_player
					- M_PI) * M_PI / 180) * 5) / SIZE_WALL][(int)(g->pl.x
				+ sin((g->pl.angle_player - M_PI) * M_PI / 180) * 5)
			/ SIZE_WALL] != '1')
		ad_event(keyCode, g);
	else if (keyCode == 2 && g->map[(int)(g->pl.y + cos((g->pl.angle_player
					+ M_PI) * M_PI / 180) * 5) / SIZE_WALL][(int)(g->pl.x
				- sin((g->pl.angle_player + M_PI) * M_PI / 180) * 5)
			/ SIZE_WALL] != '1')
		ad_event(keyCode, g);
}

int	function_event(int keyCode, t_game *g)
{
	if (keyCode == 123)
		g->pl.angle_player -= 150 * M_PI / 180;
	else if (keyCode == 124)
		g->pl.angle_player += 150 * M_PI / 180;
	else if (keyCode == 13 || keyCode == 1 || keyCode == 0 || keyCode == 2)
		adws_events(keyCode, g);
	else if (keyCode == 53)
		exit(0);
	return (0);
}
