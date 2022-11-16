/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:05:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 16:24:32 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		n;

	i = 0;
	n = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == 'c')
				n += ft_putchar(va_arg(args, int));
			else if (s[i] == 's')
				n += ft_putstr(va_arg(args, char *));
			else if (s[i] == 'p')
				n += print_adress(va_arg(args, void *));
			else if (s[i] == 'd')
				n += ft_putnbr(va_arg(args, int));
			else if (s[i] == 'i')
				n += ft_putnbr(va_arg(args, int));
			else if (s[i] == 'u')
				n += ft_putnbr_undec(va_arg(args, unsigned int));
			else if (s[i] == 'x')
				n += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
			else if (s[i] == 'X')
				n += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
			else if (s[i] == '%')
				n += ft_putchar('%');
		}
		else
			n += ft_putchar(s[i]);
		i++;
	}
	return (n);
}
