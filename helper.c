/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 07:55:27 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/21 18:05:45 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_more(char **dir, t_game *g, int n[1][2], int k)
{
	if (!ft_strncmp(dir[0], "WE", 3))
	{
		g->tex.w_bak = get_anim(mlx_load_img(g->mlx_ptr, dir[1]), &g->tex.w, n);
		g->pathtex[k] = ft_strdup(dir[1]);
		return (1);
	}
	else if ((!ft_strncmp(dir[0], "F", 2) && g->tex.floor == -1) || \
				(!ft_strncmp(dir[0], "C", 2) && g->tex.ceiling == -1))
	{
		cf_color(dir, g);
		return (1);
	}
	return (0);
}

void	check_texture2(char **dir, t_game *g, int n[1][2], int k)
{
	if (!ft_strncmp(dir[0], "NO", 3))
	{
		g->tex.n_bak = get_anim(mlx_load_img(g->mlx_ptr, dir[1]), &g->tex.n, n);
		g->pathtex[k] = ft_strdup(dir[1]);
	}
	else if (!ft_strncmp(dir[0], "SO", 3))
	{
		g->tex.s_bak = get_anim(mlx_load_img(g->mlx_ptr, dir[1]), &g->tex.s, n);
		g->pathtex[k] = ft_strdup(dir[1]);
	}
	else if (!ft_strncmp(dir[0], "EA", 3))
	{
		g->tex.e_bak = get_anim(mlx_load_img(g->mlx_ptr, dir[1]), &g->tex.e, n);
		g->pathtex[k] = ft_strdup(dir[1]);
	}
	else if (!(check_more(dir, g, n, k)))
	{
		ft_free_matrix(&dir);
		cube_error(inv_map, g, NULL, 1);
	}
}

void	init_map(char *line[2], t_game *g, int n[1][2], int k)
{
	while (1)
	{
		line[0] = get_next_line(g->fd);
		if (!line[0])
			break ;
		line[1] = ft_strtrim(line[0], "\n");
		if (n[0][0] < 4)
			trimspaces(line[1]);
		free(line[0]);
		if (line[1] && line[1][0] && ++n[0][0] < 6)
		{
			check_textures(line[1], g, n, k);
			k++;
		}
		else if ((line[1] && line[1][0]) || n[0][0] >= 6)
			g->map = extand_matrix(g->map, line[1]);
		if ((int)ft_strlen(line[1]) > g->width)
			g->width = ft_strlen(line[1]);
		free(line[1]);
	}
}
