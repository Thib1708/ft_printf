/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:05:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 22:04:56 by tgiraudo         ###   ########.fr       */
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
			n += ft_print_type(args, s[i]);
		}
		else
			n += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (n);
}

int	ft_print_type(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (print_adress(va_arg(args, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_undec(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

// int main()
// {
// 	printf("%d\n", ft_printf("%d", -2147483648));
// 	printf("%d", printf("%ld", -2147483648));
// }