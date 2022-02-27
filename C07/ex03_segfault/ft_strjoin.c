/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:16:06 by raweber           #+#    #+#             */
/*   Updated: 2022/02/24 16:20:40 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}

int	ft_get_byte_size(int size, char **strs, char *sep)
{
	int		i;
	int		bytes;

	i = 0;
	bytes = 1;
	while (i < size)
	{
		bytes += ft_strlen(strs[i]);
		i++;
	}
	bytes += (ft_strlen(sep) * (size - 1));
	return (bytes);
}

int	ft_string_write(char **strs, int k, int i, char *joined)
{
	int	j;

	j = 0;
	while (strs[i][j] != 0)
	{
		joined[k] = strs[i][j];
		k++;
		j++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		i;
	int		j;
	int		k;

	joined = (char *)malloc(sizeof(char) * ft_get_byte_size(size, strs, sep));
	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		k = ft_string_write(strs, k, i, joined);
		while ((sep[j] != 0) && (i < size - 1))
		{	
			joined[k] = sep[j];
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	joined[k] = '\0';
	return (joined);
}
