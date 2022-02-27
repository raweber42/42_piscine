/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:04:39 by raweber           #+#    #+#             */
/*   Updated: 2022/02/24 16:20:50 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// check that base is valid
int	ft_base_check(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == 43 || base[i] == 45 || base[i] < 33)
		{
			return (-1);
		}
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

// checks position in base OR existence in base
int	ft_process_with_flag(char c, char *base, char flag)
{
	int		i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
		{
			if (flag == 'd')
				return (i);
			if (flag == 'b')
				return (1);
		}
		i++;
	}
	if (flag == 'd')
		return (i);
	return (0);
}

// calculates the integer value depending on base
int	ft_get_result(int length, int start_index, char *base, char *str)
{
	int		i;
	int		base_length;
	int		power_of;
	int		calc_length;
	int		result;

	base_length = ft_base_check(base);
	calc_length = length;
	power_of = 1;
	result = 0;
	while (calc_length - 1 != 0)
	{
		power_of *= base_length;
		calc_length--;
	}
	i = start_index;
	while (i < (start_index + length))
	{
		result += (ft_process_with_flag(str[i], base, 'd') * power_of);
		power_of /= base_length;
		i++;
	}
	return (result);
}

// cuts out the actual string for processing
int	ft_int_cutter(char *str, char *base)
{
	int		i;
	int		start_index;
	int		length;

	i = 0;
	start_index = 0;
	length = 0;
	while (str[i] != 0)
	{
		if (ft_process_with_flag(str[i], base, 'b'))
		{
			start_index = i;
			length = 0;
			while (ft_process_with_flag(str[i++], base, 'b'))
			{
				length++;
			}
			break ;
		}
		i++;
	}
	return (ft_get_result(length, start_index, base, str));
}

// calls subfunctions and returns the searched int value
int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		minus_counter;
	int		base_length;

	i = 0;
	minus_counter = 1;
	base_length = ft_base_check(base);
	while (str[i] != 0 && base_length > 1)
	{
		if (str[i] == 45)
			minus_counter *= -1;
		if (ft_process_with_flag(str[i], base, 'b'))
		{
			return (minus_counter * (ft_int_cutter(str, base)));
		}
		else if (!(str[i] > 47 && str[i] < 58))
		{
			if (str[i] != 45 && str[i] != 43 && str[i] > 32)
				return (0);
		}
		i++;
	}
	return (0);
}
