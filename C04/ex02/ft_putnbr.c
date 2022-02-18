/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:30:09 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 14:17:55 by raweber          ###   ########.fr       */
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
