/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:30:03 by amimouni          #+#    #+#             */
/*   Updated: 2023/05/19 07:17:31 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*s1;

	s1 = (t_list *)malloc(sizeof(t_list));
	if (!s1)
		return (NULL);
	s1->content = content;
	s1->next = NULL;
	return (s1);
}

int	matrix_len(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
	{
		i++;
	}
	return (i);
}

void	trimspaces(char *str)
{
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	trimmedlen;

	len = strlen(str);
	start = 0;
	end = len - 1;
	while (str[start] == ' ' || str[start] == '\t')
	{
		start++;
	}
	while (end > start && (str[end] == ' ' || str[end] == '\t'))
	{
		end--;
	}
	trimmedlen = end - start + 1;
	ft_memmove(str, str + start, trimmedlen);
	str[trimmedlen] = '\0';
}
