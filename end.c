/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachaq <aachaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:11:32 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/15 05:28:17 by aachaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_animation(t_game *g, t_list *start)
{
	t_list	*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (g && ((t_img *)temp->content)->i)
			mlx_destroy_image(g->mlx_ptr, ((t_img *)temp->content)->i);
		free(temp->content);
		free(temp);
	}
}

void	destroy_images(t_game *g)
{
	free_animation(g, g->tex.n_bak);
	free_animation(g, g->tex.s_bak);
	free_animation(g, g->tex.e_bak);
	free_animation(g, g->tex.w_bak);
	if (g->win_ptr)
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
}

void	end_cube(t_game *g)
{
	if (!g)
		return ;
	ft_free_matrix(&g->map);
	if (g->fd > 0)
		close(g->fd);
	destroy_images(g);
}
