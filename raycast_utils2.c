/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:03:38 by aachaq            #+#    #+#             */
/*   Updated: 2023/05/21 10:39:43 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	exit_program(t_game *g)
{
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	exit(0);
}

int	*arg(int y, int wall_hei, int start)
{
	int	*arg;

	arg = (int *)malloc(sizeof(char) * 3);
	arg[0] = wall_hei;
	arg[1] = start;
	arg[2] = y;
	return (arg);
}
