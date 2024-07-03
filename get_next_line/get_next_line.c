/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:24 by amimouni          #+#    #+#             */
/*   Updated: 2023/04/30 17:31:55 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchre(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*current_line(char *rest)
{
	int	i;

	i = 0;
	if (!rest[0])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	return (ft_substre(rest, 0, i + 1));
}

char	*next_line(char *rest)
{
	int		i;
	char	*s;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			s = ft_substre(rest, i + 1, ft_strlene(rest) - i);
			free(rest);
			return (s);
		}
		i++;
	}
	free(rest);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest;
	char			*line;
	int				c;

	c = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (c && ft_strchre(rest))
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c == -1)
			return (line);
		buff[c] = '\0';
		rest = ft_strjoine(rest, buff);
	}
	line = current_line(rest);
	rest = next_line(rest);
	return (line);
}
/*int main(void)
{
	int fd;
	char *line;
	int i;

	line = " ";
	fd = open("file.txt",O_RDONLY);
	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("line %d : %s\n",i,line); 
		i++;
	}
	
}*/
