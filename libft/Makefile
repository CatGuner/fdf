# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atammie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 19:01:16 by atammie           #+#    #+#              #
#    Updated: 2020/01/22 20:42:32 by atammie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MASKS=-Wall -Wextra -Werror

OFILES=get_next_line.o ft_lstiter.o ft_lstadd.o ft_lstdelone.o ft_lstdel.o ft_lstnew.o ft_splitmemdel.o ft_atoi.o ft_memchr.o ft_putnbr_fd.o ft_striter.o ft_strnstr.o ft_bzero.o ft_memcmp.o ft_putstr.o ft_striteri.o ft_strrchr.o ft_copytomas.o ft_memcpy.o ft_putstr_fd.o ft_strjoin.o ft_strsplit.o ft_countlet.o ft_memdel.o ft_splitfill.o ft_strlcat.o ft_strstr.o ft_isalnum.o ft_memmove.o ft_strcat.o ft_strlen.o ft_strsub.o ft_isalpha.o ft_memset.o ft_strchr.o ft_strmap.o ft_strtrim.o ft_isascii.o ft_numwords.o ft_strclr.o ft_strmapi.o ft_swap.o ft_isdigit.o ft_putchar.o ft_strcmp.o ft_strncat.o ft_tolower.o ft_isprint.o ft_putchar_fd.o ft_strcpy.o ft_strncmp.o ft_toupper.o ft_itoa.o ft_putendl.o ft_strdel.o ft_strncpy.o  ft_memalloc.o ft_putendl_fd.o ft_strdup.o ft_strnequ.o  ft_memccpy.o ft_putnbr.o ft_strequ.o ft_strnew.o

NAME=libft.a

.PHONY: all, $(NAME), clean, fclean, re
all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

$(OFILES): %.o : %.c
	@gcc -c $(MASKS) -I. $<

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
