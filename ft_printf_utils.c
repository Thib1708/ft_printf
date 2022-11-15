/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:21:18 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 20:52:42 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr_base(long int nb, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putchar(base[nb % 16]);
	}
	else
		ft_putchar(base[nb % 16]);
}

void	print_adress(void *addr)
{
	unsigned long	address;
	char			adr[17];
	char			*hexa;
	int				i;

	address = (long int)addr;
	i = 0;
	hexa = "0123456789abcdef";
	while (address)
	{
		adr[i] = hexa[address % 16];
		address /= 16;
		i++;
	}
	ft_putstr("0x");
	while (i >= 0)
		ft_putchar(adr[i--]);
}

void	ft_print_dec(double nbr)
{
	
}