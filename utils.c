/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:26:31 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/10 12:20:37 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_size(long int i, int base)
{
	int n;

	n = 0;
	while (i > 0)
	{
		n++;
		i /= base;
	}
	return (n);
}

static char	*ft_nbr_is_zero(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoabase(long long int i, int base, char *tab)
{
	char	*res;
	int		n;

	n = 0;
	if (i == 0)
		return (ft_nbr_is_zero());
	if (i < 0)
		i *= -1;
	n = ft_size(i, base);
	if (!(res = malloc(n + 1)))
		return (NULL);
	res[n] = '\0';
	while (n > 0 && i != 0)
	{
		res[--n] = tab[i % base];
		i /= base;
	}
	return (res);
}
