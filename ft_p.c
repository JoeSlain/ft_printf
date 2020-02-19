/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:09:54 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/06 18:55:16 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_affichep(int len, int len_prec, char **s, void *n)
{
	int isneg;
	int i;

	write(1, "0x", 2);
	i = -1;
	isneg = n < 0 ? 1 : 0;
	if (n < 0)
		write(1, "-", 1);
	while (++i < len_prec - len)
		write(1, "0", 1);
	i = -1;
	while (++i < len - isneg)
		write(1, &(*s)[i], 1);
}

int		ft_p(t_flags *flags, int *ret, void *n, char *base)
{
	int		len;
	int		len_prec;
	int		total;
	int		i;
	char	*s;

	if (!(s = ft_itoabase((long int)n, ft_strlen(base), base)))
		return (0);
	i = -1;
	len = ft_strlen(s);
	len_prec = (flags->prec > len) ? flags->prec : len;
	total = (flags->width > len_prec) ? flags->width : len_prec;
	(*ret) += flags->width > len_prec ? total : total + 2;
	total -= 2;
	if (flags->arg == '-')
		ft_affichep(len, len_prec, &s, n);
	while (++i < total - len_prec)
		write(1, " ", 1);
	if (flags->arg != '-')
		ft_affichep(len, len_prec, &s, n);
	free(s);
	s = NULL;
	return (1);
}
