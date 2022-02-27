/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:04:43 by raweber           #+#    #+#             */
/*   Updated: 2022/02/24 16:20:52 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	ft_base_check(char *base);

// determines length of nbr in new base
int	ft_get_new_length(int nbr, int base_length)
{
	int		counter;

	counter = 1;
	while (nbr / base_length)
	{
		counter++;
		nbr /= base_length;
	}
	counter++;
	if (nbr < 0)
		counter++;
	return (counter);
}

// converts int to new base
void	ft_putnbr_base(int nbr, char *base, char *value_new_base)
{
	int		base_length;
	long	nbr_long;
	int		i;

	base_length = ft_base_check(base);
	if (base_length != 0)
	{	
		nbr_long = (long)nbr;
		i = 0;
		if (nbr_long < 0)
		{
			i = 1;
			nbr_long = -nbr_long;
			value_new_base[0] = '-';
		}
		while (nbr_long / base_length)
		{
			value_new_base[i] = base[nbr_long % base_length];
			nbr_long /= base_length;
			i++;
		}
		value_new_base[i] = base[nbr_long % base_length];
	}
}

// reverts the array, but omits last char (and first if negative)
void	ft_rev_int_tab(char *tab, int size, int minus_flag)
{
	int		low;
	int		high;
	int		temp;

	low = 0;
	if (minus_flag)
		low = 1;
	high = size - 1;
	while (low < high)
	{
		temp = tab[low];
		tab[low] = tab[high];
		tab[high] = temp;
		low++;
		high--;
	}
}

// handles all sub_functions and returns number in new base
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value_int;
	int		lenght_new_base;
	char	*value_new_base;

	value_int = ft_atoi_base(nbr, base_from);
	if (value_int == 0)
		return (0);
	lenght_new_base = ft_get_new_length(value_int, ft_base_check(base_to));
	value_new_base = (char *)malloc(lenght_new_base);
	ft_putnbr_base(value_int, base_to, value_new_base);
	if (value_new_base[0] == '-')
		ft_rev_int_tab(value_new_base, lenght_new_base - 1, 1);
	else
		ft_rev_int_tab(value_new_base, lenght_new_base - 1, 0);
	return (value_new_base);
}
