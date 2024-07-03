/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:31:50 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/22 23:26:57 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	create_rgb(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

int	count_deli(char *dir, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (dir[i])
	{
		if (dir[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	cf_color(char **dir, t_game *g)
{
	char	**fc;
	int		str[2];
	int		c[3];
	t_color	aux;

	str[0] = !ft_strncmp(dir[0], "F", 2);
	str[1] = !ft_strncmp(dir[0], "C", 2);
	if (count_deli(dir[1], ',') >= 3)
		return ;
	fc = ft_split(dir[1], ',');
	if ((!fc || !fc[1] || !fc[2]) || matrix_len(fc) != 3)
	{
		ft_free_matrix(&fc);
		return ;
	}
	c[0] = cub_atoi(fc[0], &aux.r);
	c[1] = cub_atoi(fc[1], &aux.g);
	c[2] = cub_atoi(fc[2], &aux.b);
	ft_free_matrix(&fc);
	if (c[0] || c[1] || c[2])
		return ;
	if (str[0])
		g->tex.floor = create_rgb(aux);
	else if (str[1])
		g->tex.ceiling = create_rgb(aux);
}
