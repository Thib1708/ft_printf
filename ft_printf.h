/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:43 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putnbr_base(long int nb, char *tab);
int		print_adress(void *addr);
int		ft_putnbr_undec(unsigned int n);
int		ft_strlen(char *s);

#endif
