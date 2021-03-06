/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:30:39 by raweber           #+#    #+#             */
/*   Updated: 2022/02/16 13:02:36 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
