# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:57:40 by tgiraudo          #+#    #+#              #
#    Updated: 2022/11/16 15:22:33 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	  ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils_2.c

NAME		= libftprintf.a

OBJS		= ${SRCS:.c=.o}

HEADERS		= .

%.o : %.c	Makefile ft_printf.h
	gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
