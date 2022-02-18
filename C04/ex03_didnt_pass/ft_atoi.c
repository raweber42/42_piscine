/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:45:51 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 14:28:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_cutter(char *str, int minus_counter, int start_index, int length)
{
	int		i;
	int		temp;
	int		calc_length;
	int		return_value;
	int		power_of;

	i = start_index;
	power_of = 1;
	calc_length = length;
	return_value = 0;
	while (calc_length - 1 != 0)
	{
		power_of *= 10;
		calc_length--;
	}
	while (i < (start_index + length))
	{
		temp = (str[i] - 48);
		return_value += (temp * power_of);
		power_of /= 10;
		i++;
	}
	if (minus_counter % 2 == 1)
		return_value *= -1;
	return (return_value);
}

int	ft_atoi(char *str)
{
	int		i;
	int		start_index;
	int		length;
	int		minus_counter;

	i = 0;
	minus_counter = 0;
	while (str[i] != 0)
	{
		if (str[i] == 45)
			minus_counter++;
		if (str[i] > 47 && str[i] < 58)
		{
			start_index = i;
			length = 0;
			while (str[i] > 47 && str[i] < 58)
			{
				length++;
				i++;
			}
			return (ft_int_cutter(str, minus_counter, start_index, length));
		}
		i++;
	}
	return (0);
}
