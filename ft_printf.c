/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:05:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 20:16:19 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == 'c')
				ft_putchar(va_arg(args, int));
			else if (s[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (s[i] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'x')
				ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
			else if (s[i] == 'X')
				ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
			else if (s[i] == '%')
				ft_putchar('%');
			else if (s[i] == 'p')
				print_adress(va_arg(args, void *));
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	return (0);
}

int main()
{
	char *a ="test";
	ft_printf("%p\n", a);
	printf("%p", a);
}