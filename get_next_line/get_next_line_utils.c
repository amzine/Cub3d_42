/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:57 by amimouni          #+#    #+#             */
/*   Updated: 2023/04/30 17:31:48 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlene(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoine(char *s1, char *s2)
{
	char	*p;
	int		len2;
	int		i;
	int		len1;

	len1 = ft_strlene(s1);
	len2 = ft_strlene(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		p[i - 1] = s1[i - 1];
	while (i++ < len1 + len2 + 1)
		p[i - 2] = s2[i - len1 - 2];
	p[len1 + len2] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdupe(char *s)
{
	int		i;
	int		len;
	char	*buff;

	i = 0;
	len = ft_strlene(s);
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (0);
	while (s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	free(s);
	return (buff);
}

char	*ft_substre(char	*s, int start, int len)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = len;
	if (!s)
		return (NULL);
	if (start > ft_strlene((char *)s) || s[0] == '\0')
		return (ft_strdupe(""));
	if (len > ft_strlene(s))
		size = ft_strlene(s) - start + 1;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
