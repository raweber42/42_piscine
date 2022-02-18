/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:45:39 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 11:36:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_lower(char *str)
{
	if (!(*str > 96 && *str < 123))
	{
		return (0);
	}
	return (1);
}

int	ft_str_is_alphanumeric(char *str)
{
	if (*str > 64 && *str < 91)
	{
		return (1);
	}
	if (*str > 96 && *str < 123)
	{
		return (1);
	}
	if (*str > 47 && *str < 58)
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (ft_is_lower(&str[0]) == 1)
	{
		str[0] -= 32;
	}
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
		{
			str[i] += 32;
		}
		if (ft_is_lower(&str[i]) == 1)
		{
			if (ft_str_is_alphanumeric(&str[i - 1]) == 0)
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
