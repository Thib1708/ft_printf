# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:57:40 by tgiraudo          #+#    #+#              #
#    Updated: 2022/11/15 19:05:45 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	  ft_printf.c \


NAME		= libftprintf.a

OBJS		= ${SRCS:.c=.o}

HEADERS		= .

.c.o:
	gcc -Wall -Wextra -Werror -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
