/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:46:38 by coder             #+#    #+#             */
/*   Updated: 2022/02/21 13:46:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = 0;
	b = 0;
	while (s1[i] != 0 && s1[i] == s2[i])
	{
		i++;
	}
	a += s1[i];
	b += s2[i];
	return (a - b);
}

void	ft_sort_strings(int nb, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < nb)
	{
		j = i;
		while (j > 0 && (ft_strcmp(argv[j - 1], argv[j]) > 0))
		{
			temp = argv[j - 1];
			argv[j - 1] = argv[j];
			argv[j] = temp;
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_sort_strings(argc - 1, argv + 1);
	while (i < argc)
	{
		while (argv[i][j] != 0)
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
	return (0);
}
