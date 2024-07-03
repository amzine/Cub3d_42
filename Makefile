# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amimouni <amimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 07:51:17 by amimouni          #+#    #+#              #
#    Updated: 2023/05/21 16:46:12 by amimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


 SRCS			= main.c color.c end.c error.c map.c parsing.c util.c helper.c \
					utils2.c raycast.c raycast_utils.c raycast_utils2.c loop_main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
					libft/ft_strncmp.c libft/ft_split.c libft/ft_strlen.c \
					libft/ft_countchar.c libft/ft_strchr.c libft/ft_strtrim.c libft/ft_strdup.c \
					libft/ft_isdigit.c libft/ft_strlcpy.c libft/ft_substr.c libft/ft_strrncmp.c \
					libft/ft_putendl_fd.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_memmove.c libft/ft_memcpy.c

OBJS			= $(SRCS:.c=.o)
INCLUDES		= includes
CC				= cc -O3
RM				= rm -f
CPPFLAGS	=  -Wall -Wextra -Werror #-g3 -fsanitize=address   

LMLX = -lmlx -framework OpenGL -framework AppKit
NAME			= Cub3d

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(LMLX) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)