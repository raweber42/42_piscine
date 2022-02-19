/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/19 16:21:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_pre_processing(int array[5][6], int total_size)
{
	int row;
	int col;
	int min = 1;
	int max = total_size - 2; //because we have 5 instead of 3
	
	while (row < total_size)
	{
		while (col < total_size)
		{
			// //if (row != 0 && col != 0)
			// printf("%d", array[row][col]);
			// if (row == 0 || row == 4)
			// 	col++;
			// else
			// 	col+=3;

			// deal with 0th and 4th (last) row
			if (row == 0 && array[row][col] == max)
			{
				array[row + 1][col] = min; // while loop instead
				array[row + 2][col] = min + 1;
				array[row + 3][col] = min + 2;
			}
			if (row == 0 && array[row][col] == min)
				array[row + 1][col] = max;

			if (row == 4 && array[row][col] == max)
			{
				array[row - 1][col] = min; // while loop instead
				array[row - 2][col] = min + 1;
				array[row - 3][col] = min + 2;
			}
			if (row == 4 && array[row][col] == min)
				array[row - 1][col] = max;

			if (col == 0 && array[row][col] == max)
			{
				array[row][col + 1] = min; // while loop instead
				array[row][col + 2] = min + 1;
				array[row][col + 3] = min + 2;
			}
			if (col == 0 && array[row][col] == min)
					array[row][col + 1] = max;
			
			if (col == 4 && array[row][col] == max)
			{
					array[row][col - 1] = min; // while loop instead
					array[row][col - 2] = min + 1;
					array[row][col - 3] = min + 2;
			}
			if (col == 4 && array[row][col] == min)
					array[row][col - 1] = max;
			col++;
		}
		col = 0;
		row++;
	}
}

int ft_valid_placement(int row, int col, int array[5][6])
{
	
}

// MAGIC ###############
int	ft_solve(int row, int col, int array[5][6], int total_size)
{
	// base cases
	if (col == total_size - 2) // end of column -> go to next column
	{
		row++;
		col = 1;
	}
	if (row > total_size - 2) // end of column LAST ROW -> finished round (probably have to go back)
	{
		//finish
		return 1; /// ??????? right like that?
	}

	
	int		value;

	value = 1;
	if (array[row][col] != 0)
		return ; //already filled with value! // return value??

	while (value <= 5)
	{
		array[row][col] = value; // choice
		if (ft_valid_placement(row, col, ...)) // check constraints
		{
			if (ft_solve(row, col + 1, array))
			{
				return 1;
			}
		}
	}
	// if doesn't fit, redo the change
	array[row][col] = 0;
}

// MAGIC ##############


// this should take command line arguments! // convert to to integers, they are chars!!!!
int main(void)
{
	int total_size;
	int row;
	int col;
	int max;
	int min;
	int temp;
	
	row = 0;
	col = 0;
	total_size = 5;
	max = 3;
	min = 1;
	int	array[5][6] =   {{0, 1, 2, 3, 0},
						 {1, 0, 0, 0, 3},
						 {2, 0, 0, 0, 2},
						 {2, 0, 0, 0, 1},
						 {0, 2, 2, 1, 0}};
	
	ft_pre_processing(array, total_size);

	// here goes the magic! (only for 3x3 array!) --> check this again!
	row = 1;
	col = 1;
	while (row < total_size - 1)
		{
		while (col < total_size - 1)
		{
			//magic backtracking
			ft_solve(row, col, array, total_size);
			col++;
		}
		row++;
		col = 1;
	}

	// print the WHOLE (incl outer columns) array after solving it.
	row = 0;
	col = 0;
	while (row < total_size)
		{
		while (col < total_size)
		{
			printf("%d", array[row][col]);
			col++;
		}
		row++;
		col = 0;
		printf("\n");
	}
	return 0;
}
