/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:51:13 by amimouni          #+#    #+#             */
/*   Updated: 2021/11/10 16:51:22 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *destination, const char *source)
{
	char	*ptr;

	ptr = destination;
	if (destination == NULL)
	{
		return (NULL);
	}
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	if (!s1)
		return (NULL);
	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(s1) + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_strcpy(new_str, s1));
}
