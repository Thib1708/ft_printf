/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 20:08:48 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER__
#define __HEADER__ 

#include<stdarg.h>
#include<unistd.h>
#include <stdio.h>

int    ft_printf(const char *, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putnbr_base(long int nb, char *tab);
void	print_adress(void *addr);

#endif