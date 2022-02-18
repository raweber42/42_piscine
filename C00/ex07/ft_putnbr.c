/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 11:02:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	new;

	new = (long)nb;
	if (nb < 0)
	{
		ft_putchar('-');
		new = -new;
	}
	if (new / 10)
	{
		ft_putnbr(new / 10);
	}
	ft_putchar(new % 10 + '0');
}
