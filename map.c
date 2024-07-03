/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:08:19 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/22 23:03:07 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	*mlx_load_img(void *ptr, char *path)
{
	int		fd;
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->i = NULL;
	if (!path || ft_strrncmp(path, ".xpm", 4))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	close(fd);
	i->i = mlx_xpm_file_to_image(ptr, path, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line_len, &i->endi);
	return (i);
}

t_list	*get_anim(t_img *img, t_list **anim, int n[1][2])
{
	if (n && anim && *anim && img)
		(*n)[0]--;
	if (!img)
		return (*anim);
	if (!img->i)
	{
		free(img);
		(*n)[1] = 0;
		return (*anim);
	}
	list_add_back(anim, ft_lstnew(img));
	return (*anim);
}

void	check_textures(char *trim, t_game *g, int n[0][2], int k)
{
	char	**dir;

	dir = ft_split(trim, ' ');
	if (!dir)
	{
		free(trim);
		exit(0);
	}
	check_texture2(dir, g, n, k);
	ft_free_matrix(&dir);
}

void	read_map(char *file, t_game *g)
{
	char	*line[2];
	int		n[1][2];
	int		k;

	n[0][0] = -1;
	n[0][1] = -1;
	k = 0;
	g->fd = open(file, O_RDONLY);
	cube_error(inv_file, g, file, g->fd < 0);
	init_map(line, g, n, k);
	cube_error(empty_file, g, NULL, n[0][0] == -1);
	cube_error(inv_tex, g, NULL, !n[0][1]);
	g->height = matrix_len(g->map);
}

void	check_map(t_game *g)
{
	int	j;
	int	i;
	int	w;

	j = -1;
	while (++j < g->height)
	{
		w = ft_strlen(g->map[j]) - 1;
		i = 0;
		while (g->map[j][i] == ' ' && i <= w)
			i++;
		while (g->map[j][w] == ' ' && w > 0)
			w--;
		if (ft_strncmp(g->map[j], "", 1) == 0)
			cube_error(inv_map, g, NULL, 1);
		if ((j == 0 || j == g->height - 1) && ft_strlen(g->map[j])
			- ft_countchar(g->map[j], ' ') - ft_countchar(g->map[j], '1'))
			cube_error(inv_wall, g, NULL, 1);
		else if (w > i && (g->map[j][i] != '1' || g->map[j][w] != '1'))
			cube_error(inv_wall, g, NULL, 1);
	}
	check_elements(g);
	cube_error(inv_map, g, NULL, !j);
}
