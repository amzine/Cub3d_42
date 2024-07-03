/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:08:50 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/22 23:55:20 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_error(t_cub_err err)
{
	if (err == inv_map)
		printf("invalid map\n");
	else if (err == inv_wall)
		printf("map not surrounded by walls\n");
	else if (err == inv_file)
		printf("error opening file\n");
	else if (err == inv_ext)
		printf("must end with .cub\n");
	else if (err == inv_tex)
		printf("invalid texture\n");
	else if (err == inv_color)
		printf("invalid color\n");
	else if (err == inv_player)
		printf("invalid number of players\n");
	else if (err == empty_file)
		printf("empty file\n");
}

int	cube_error(t_cub_err err, t_game *g, char *param, int c)
{
	if (!c)
		return (0);
	end_cube(g);
	if (err != end)
		write(2, "cub3d: ", 7);
	if (err == inv_argc)
		printf("invalid number of arguments\n");
	else if (err == inv_pwd)
		printf("cub3d must be in root of the project\n");
	else if (err == inv_charc)
		printf("invalid character\n");
	check_error(err);
	ft_putendl_fd(param, 2);
	if (err == end)
		exit(0);
	exit(1);
	return (1);
}
