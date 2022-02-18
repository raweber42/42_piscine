/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:31:45 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 13:23:06 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	ptr = 0;
	if (to_find[0] == 0)
		return (&str[0]);
	while (str[i] != 0)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i] == to_find[j])
			{
				j++;
				i++;
				if (to_find[j] == 0)
					return (&str[i - j]);
			}
		}
		i++;
	}
	return (ptr);
}
