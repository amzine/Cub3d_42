/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:08:07 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/23 00:11:49 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_file(int arc, char **argv)
{
	int	fd;

	cube_error(inv_argc, NULL, NULL, arc != 2);
	if (ft_strrncmp(".cub", argv[1], 4))
		cube_error(inv_ext, NULL, NULL, 1);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	cube_error(inv_file, NULL, argv[1], fd < 0);
}

void	init_sprites(t_game *g)
{
	g->win_img.i = NULL;
	g->win_g.i = NULL;
	g->win_r.i = NULL;
	g->tex.n = NULL;
	g->tex.n_bak = NULL;
	g->tex.s = NULL;
	g->tex.s_bak = NULL;
	g->tex.e = NULL;
	g->tex.e_bak = NULL;
	g->tex.w = NULL;
	g->tex.w_bak = NULL;
}

static t_game	init_cub(void)
{
	t_game	g;

	g.pathtex = (char **)malloc(sizeof(char *) * 5);
	g.width = 0;
	g.fd = -1;
	g.height = 0;
	g.map = NULL;
	g.pl.dir = 0;
	g.pl.angle_player = 0;
	g.mlx_ptr = NULL;
	g.win_ptr = NULL;
	g.mlx_ptr = mlx_init();
	init_sprites(&g);
	g.tex.floor = -1;
	g.tex.ceiling = -1;
	g.pl.x = -1;
	g.pl.y = -1;
	return (g);
}

void	fill_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == ' ')
				g->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	t_game	g;

	check_file(ac, av);
	g = init_cub();
	read_map(av[1], &g);
	cube_error(inv_tex, &g, NULL, !g.tex.s || !g.tex.e || !g.tex.w || !g.tex.n);
	cube_error(inv_color, &g, NULL, g.tex.ceiling == -1 || g.tex.floor == -1);
	tab = map_squared(&g);
	ft_free_matrix(&g.map);
	g.map = tab;
	check_map(&g);
	fill_map(&g);
	raycast(&g);
	return (0);
}
