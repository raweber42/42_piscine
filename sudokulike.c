/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_4x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:01:08 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 12:56:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_pre_processing(char array[6][7], int total_size)
{
	int row;
	int col;
	char min = '1';
	char max = total_size - 2 + '0'; //because we have 5 instead of 3
	printf("Max: %c\n", max);
	row = 0;
	col = 0;
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
				array[row + 4][col] = min + 3;
			}
			if (row == 0 && array[row][col] == min)
				array[row + 1][col] = max;

			if (row == 5 && array[row][col] == max)
			{
				array[row - 1][col] = min; // while loop instead
				array[row - 2][col] = min + 1;
				array[row - 3][col] = min + 2;
				array[row - 4][col] = min + 3;
			}
			if (row == 5 && array[row][col] == min)
				array[row - 1][col] = max;

			if (col == 0 && array[row][col] == max)
			{
				array[row][col + 1] = min; // while loop instead
				array[row][col + 2] = min + 1;
				array[row][col + 3] = min + 2;
				array[row][col + 4] = min + 3;
			}
			if (col == 0 && array[row][col] == min)
					array[row][col + 1] = max;
			
			if (col == 5 && array[row][col] == max)
			{
					array[row][col - 1] = min; // while loop instead
					array[row][col - 2] = min + 1;
					array[row][col - 3] = min + 2;
					array[row][col - 4] = min + 3;
			}
			if (col == 5 && array[row][col] == min)
					array[row][col - 1] = max;
			col++;
		}
		col = 0;
		row++;
	}
}

int ft_valid_placement(int row, int col, char array[6][7], char digit)
{
	int		i;

	i = 1; // changed 0 to 1
	
	// Sudoku rules
	while (i < 5)
	{
		if (array[row][i] == digit)
			return 0;
		if (array[i][col] == digit)
			return 0;
		i++;
	}
	
	// alirezas additions
	if (array[row][0] != '1' && col == 1)
	{
		if (digit > ('4' - array[row][0] + '1'))
		{
			printf("\nHere1\n");
			return 0;
		}	 	
	}
	if (array[0][col] != '1' && row == 1)
	{
		if (digit > ('4' - array[0][col] + '1'))
		{
			printf("\nHere2\n");
			return 0;
		}
	}
	if (array[row][5] != '1' && col == 4)
	{
		if (digit > ('4' - array[row][5] + '1'))
		{
			printf("\nHere3\n");
			return 0;
		}
	}
	if (array[5][col] != '1' && row == 4)
	{
		if (digit > ('4' - array[5][col] + '1'))
		{
			printf("\nHere4\n");
			return 0;
		}
	}

	return 1;
}

// MAGIC START ###############
int	ft_solve(int row, int col, char array[6][7])
{
	char digit;
	
	if (row < 5 && col < 5)
	{
		if (array[row][col] != '0')
		{
			if ((col + 1) < 5) // next column
				return ft_solve(row, col + 1, array);
			else if ((row + 1) < 5) // next row
				return ft_solve(row + 1, 1, array);
			else 
				return 1; // solved!
		}
		else
		{
			digit = '1';
			while (digit < '5')
			{
				
				if (ft_valid_placement(row, col, array, digit)) // why did he use i+1?
				{
					printf("row: %d, col: %d, placed digit: %c\n", row, col, digit);
					array[row][col] = digit;
					if ((col + 1) < 5)
					{
						if (ft_solve(row, col + 1, array))
							return 1;
						else
							array[row][col] = '0';
					}
					else if ((row + 1) < 5)
					{
						if (ft_solve(row + 1, 1, array))
							return 1;
						else
							array[row][col] = '0';
					}
					else
						return 1;
				}
				digit++;
			}
		}
		printf("digit: %c, next loop\n", digit);
		return 0;
	}
	else
		return 1;
}

// MAGIC END ##############


// this should take command line arguments! // convert to to integers, they are chars!!!!
int main(void)
{
	int total_size;
	int row;
	int col;
	char max;
	char min;
	
	row = 0;
	col = 0;
	total_size = 6;
	max = '4';
	min = '1';
	char	array[6][7] =   {{'0', '1', '2', '3', '2', '0'},
						     {'1', '0', '0', '0', '0', '4'},
						     {'2', '0', '0', '0', '0', '1'},
						     {'2', '0', '0', '0', '0', '3'},
						     {'2', '0', '0', '0', '0', '2'},
						     {'0', '3', '2', '1', '2', '0'}};

	// int	array[5][6] =   {{0, 1, 2, 3, 0},
	// 					 {1, 1, 0, 3, 3},
	// 					 {2, 0, 3, 0, 2},
	// 					 {2, 3, 1, 2, 1},
	// 					 {0, 2, 2, 1, 0}};
	
	ft_pre_processing(array, total_size); // -> commmented out for testing sudoku algorithm

	// print the WHOLE (incl outer columns) array after solving it.
	printf("Before backtracking:\n");
	row = 0;
	col = 0;
	while (row < total_size)
		{
		while (col < total_size)
		{
			printf("%c", array[row][col]);
			col++;
		}
		row++;
		col = 0;
		printf("\n");
	}

	printf("\n");

	// here goes the magic! (only for 3x3 array!) --> check this again!	
	if (ft_solve(1, 1, array))
	{
		// print the WHOLE (incl outer columns) array after solving it.
		printf("After backtracking:\n");
		row = 0;
		col = 0;
		while (row < total_size)
			{
			while (col < total_size)
			{
				printf("%c", array[row][col]);
				col++;
			}
			row++;
			col = 0;
			printf("\n");
		}
		printf("\n");
	}
	else
		printf("Didn't work!\n");
	return 0;
}
