/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/10 09:36:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_current(char *a)
{
	write(1, &a[0], 1);
	write(1, &a[1], 1);
	write(1, " ", 1);
	write(1, &a[2], 1);
	write(1, &a[3], 1);
	if (a[0] == '9' && a[1] == '8' && a[2] == '9' && a[3] == '9')
	{
		return ;
	}
	write(1, ", ", 2);
}

void	ft_calculating(char *a)
{
	while (a[0] <= '9')
	{	
		while (a[1] <= '9')
		{
			while (a[2] <= '9')
			{
				while (a[3] <= '9')
				{
					if (!(a[0] == a[2] && a[1] == a[3]))
					{
						ft_print_current(a);
					}
					a[3]++;
				}
				a[2]++;
				a[3] = '0';
			}
			a[1]++;
			a[2] = a[0];
			a[3] = a[1] + 1;
		}
		a[0]++;
		a[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	a[4];

	a[0] = '0';
	a[1] = '0';
	a[2] = '0';
	a[3] = '1';
	ft_calculating(a);
}
