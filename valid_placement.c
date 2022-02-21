/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:36:44 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 21:36:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_first_turn(int row, char array[6][7])
{
	int		i;
	char	temp_max;
	char	visible;

	i = 1;
	temp_max = '0';
	visible = '0';
	while (i < 5)
	{
		if (array[row][i] > temp_max)
		{
			temp_max = array[row][i];
			visible++;
		}
		i++;
	}
	if (array[row][0] < visible)
	{
		return (0);
	}
	return (1);
}

int	ft_second_turn(int col, char array[6][7])
{
	int		i;
	char	temp_max;
	char	visible;

	i = 1;
	temp_max = '0';
	visible = '0';
	while (i < 5)
	{
		if (array[i][col] > temp_max)
		{
			temp_max = array[i][col];
			visible++;
		}
		i++;
	}
	if (array[0][col] < visible)
	{		
		return (0);
	}
	return (1);
}

int	ft_third_turn(int row, char array[6][7])
{
	int		i;
	char	temp_max;
	char	visible;

	i = 4;
	temp_max = '0';
	visible = '0';
	while (i > 0)
	{
		if (array[row][i] > temp_max)
		{
			temp_max = array[row][i];
			visible++;
		}
		i--;
	}
	if (array[row][5] < visible)
	{
		return (0);
	}
	return (1);
}

int	ft_fourth_turn(int col, char array[6][7])
{
	int		i;
	char	temp_max;
	char	visible;

	i = 4;
	temp_max = '0';
	visible = '0';
	while (i > 0)
	{
		if (array[i][col] > temp_max)
		{
			temp_max = array[i][col];
			visible++;
		}
		i--;
	}
	if (array[5][col] < visible)
	{		
		return (0);
	}
	return (1);
}

int	ft_valid_placement(int row, int col, char array[6][7], char digit)
{
	int		i;

	i = 1;
	while (i < 5)
	{
		if (array[row][i] == digit)
			return (0);
		if (array[i][col] == digit)
			return (0);
		i++;
	}
	if (!ft_first_turn(row, array))
		return (0);
	if (!ft_second_turn(col, array))
		return (0);
	if (!ft_third_turn(row, array))
		return (0);
	if (!ft_fourth_turn(col, array))
		return (0);
	return (1);
}
