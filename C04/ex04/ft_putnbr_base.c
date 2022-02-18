/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:56:36 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 14:41:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_validity_check(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == 43 || base[i] == 45)
		{
			return (0);
		}
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[j] == base[i])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_recursive(int nbr, char *base, int base_length)
{
	long	nbr_long;

	nbr_long = (long)nbr;
	if (nbr_long < 0)
	{
		write(1, "-", 1);
		nbr_long = -nbr_long;
	}
	if (nbr_long / base_length)
	{
		ft_putnbr_recursive(nbr_long / base_length, base, base_length);
	}
	write(1, &base[nbr_long % base_length], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;

	base_length = ft_validity_check(base);
	if (base_length != 0)
	{
		ft_putnbr_recursive(nbr, base, base_length);
	}
}
