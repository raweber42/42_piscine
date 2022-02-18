/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:28:42 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 13:03:47 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = 0;
	b = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((i < n) && (s1[i] || s2[i]))
	{
		a += s1[i];
		b += s2[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
