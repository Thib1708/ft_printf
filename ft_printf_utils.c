/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:21:18 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 16:24:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n >= 0 && n <= 9)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
}

int	ft_putstr(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		n += ft_putchar(*s++);
	return (n);
}

int	ft_putnbr_base(long int nb, char *base)
{
	if (nb < 0)
		return (ft_putnbr_base(4294967296 + nb, base));
	if (nb < 16)
		return (ft_putchar(base[nb % 16]));
	return (ft_putnbr_base(nb / 16, base) + ft_putchar(base[nb % 16]));
}

int	print_adress(void *addr)
{
	unsigned long	address;
	char			adr[17];
	char			*hexa;
	int				i;

	if (!addr)
		return (ft_putstr("0x0"));
	address = (long int)addr;
	i = 0;
	hexa = "0123456789abcdef";
	while (address)
	{
		adr[i] = hexa[address % 16];
		address /= 16;
		i++;
	}
	adr[i] = '\0';
	ft_putstr("0x");
	while (--i >= 0)
		ft_putchar(adr[i]);
	return (ft_strlen(adr) + 2);
}
