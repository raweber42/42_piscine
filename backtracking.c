/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:01:22 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 21:01:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_valid_placement(int row, int col, char array[6][7], char digit);

int	ft_solve(int row, int col, char array[6][7]);

int	ft_place_number(int row, int col, char array[6][7], char digit)
{
	array[row][col] = digit;
	if ((col + 1) < 5)
	{
		if (ft_solve(row, col + 1, array))
			return (1);
		else
			array[row][col] = '0';
	}
	else if ((row + 1) < 5)
	{
		if (ft_solve(row + 1, 1, array))
			return (1);
		else
			array[row][col] = '0';
	}
	else
		return (1);
	return (0);
}

int	ft_else_helper(int row, int col, char array[6][7])
{
	char	digit;

	digit = '1';
	while (digit < '5')
	{
		if (ft_valid_placement(row, col, array, digit))
		{
			if (ft_place_number(row, col, array, digit))
				return (1);
		}
		digit++;
	}
	return (0);
}

int	ft_solve(int row, int col, char array[6][7])
{	
	if (row < 5 && col < 5)
	{
		if (array[row][col] != '0')
		{
			if ((col + 1) < 5)
				return (ft_solve(row, col + 1, array));
			else if ((row + 1) < 5)
				return (ft_solve(row + 1, 1, array));
			else
				return (1);
		}
		else
		{
			if (ft_else_helper(row, col, array))
				return (1);
		}
		return (0);
	}
	else
		return (1);
}
