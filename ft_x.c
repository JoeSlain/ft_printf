/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:11:36 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/10 15:58:33 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_affichex(int len, int len_prec, char **s)
{
	int i;

	i = -1;
	while (++i < len_prec - len)
		write(1, "0", 1);
	i = -1;
	while (++i < len && len_prec != 0)
		write(1, &(*s)[i], 1);
}

int		ft_x(t_flags *flags, int *ret, char *base, unsigned int n)
{
	int				len;
	int				total;
	int				i;
	char			*s;

	if (!(s = ft_itoabase(n, ft_strlen(base), base)))
		return (0);
	len = (flags->prec > ft_strlen(s)) ? flags->prec : ft_strlen(s);
	if (flags->prec == 0 && n == 0)
		len = 0;
	total = (flags->width > len) ? flags->width : len;
	(*ret) += total;
	i = flags->width > -1 ? -1 : -2;
	flags->prnt = flags->arg == '0' ? '0' : ' ';
	if ((flags->width > flags->prec && flags->prec > 0 && flags->arg != 0)
	|| flags->prec == 0)
		flags->prnt = ' ';
	if (flags->arg == '-')
		ft_affichex(ft_strlen(s), len, &s);
	while (++i < total - len)
		write(1, &flags->prnt, 1);
	if (flags->arg != '-')
		ft_affichex(ft_strlen(s), len, &s);
	return (ft_free(s));
}
