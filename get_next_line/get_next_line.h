/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:39 by amimouni          #+#    #+#             */
/*   Updated: 2023/04/30 17:34:08 by amimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substre(char *s, int start, int len);
char	*ft_strjoine(char *s1, char *s2);
int		ft_strlene(char *str);
char	*ft_strdupe(char *s);
char	*next_line(char *rest);
char	*current_line(char *rest);
int		ft_strchre(char *s);

#endif
