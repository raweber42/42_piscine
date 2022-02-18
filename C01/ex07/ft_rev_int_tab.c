/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:44:00 by coder             #+#    #+#             */
/*   Updated: 2022/02/10 11:45:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		low;
	int		high;
	int		temp;

	low = 0;
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
