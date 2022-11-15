/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:26:07 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/08/18 20:53:17 by tgiraudo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hex(unsigned char *addr)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789abcdef";
	while (addr[i] && i < 16)
	{
		if (!(i % 2))
			ft_putchar(' ');
		ft_putchar(tab[addr[i] / 16]);
		ft_putchar(tab[addr[i] % 16]);
		i++;
	}
	while (i < 16)
	{
		if (!(i % 2))
			ft_putchar(' ');
		write(1, "  ", 2);
		i++;
	}
}

void	print(unsigned char *addr)
{
	int	i;

	i = 0;
	ft_putchar(' ');
	while (addr[i] && i < 16)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	print_adress(long int addr)
{
	char	adr[17];
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	while (addr)
	{
		adr[i] = hexa[addr % 16];
		addr /= 16;
		i++;
	}
	while (i < 16)
		adr[i++] = '0';
	i--;
	while (i + 1)
		write(1, &adr[i--], 1);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned long	adresse;

	i = 0;
	adresse = (unsigned long)addr;
	while (i < size)
	{	
		print_adress(adresse + i);
		hex((unsigned char *)(adresse + i));
		print((unsigned char *)(adresse + i));
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
