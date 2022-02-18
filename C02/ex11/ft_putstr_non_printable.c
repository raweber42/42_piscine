/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:16:48 by raweber           #+#    #+#             */
/*   Updated: 2022/02/14 11:31:24 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int decimal)
{
	int		remainder;
	int		i;
	char	hexnum[3];

	i = 0;
	while (decimal != 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
			remainder += 48;
		else
			remainder += 87;
		hexnum[i] = remainder;
		i++;
		decimal = decimal / 16;
	}
	if (i == 1)
		write(1, "0", 1);
	i--;
	while (i >= 0)
	{
		write(1, &hexnum[i], 1);
		i--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	extended;

	i = 0;
	while (str[i] != '\0')
	{
		extended = (unsigned char) str[i];
		if (str[i] < 32 || extended > 127)
		{
			write(1, "\\", 1);
			print_hex(extended);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
