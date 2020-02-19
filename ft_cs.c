/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:12:27 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/11 17:31:48 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(t_flags *flags, int *ret, char c)
{
	int k;
	int toprint;

	k = -1;
	if (flags->width > 0)
		toprint = flags->width;
	else
		toprint = 1;
	if (flags->arg == '-')
		write(1, &c, 1);
	while (++k < toprint - 1)
		write(1, " ", 1);
	if (!(flags->arg == '-'))
		write(1, &c, 1);
	(*ret) += toprint;
	return (1);
}

int	ft_s(t_flags *flags, int *ret, char *s)
{
	int len;
	int k;
	int toprint;

	len = 0;
	k = -1;
	if (!s)
		s = "(null)";
	while ((flags->prec < 0 || flags->prec > len) && s[len])
		len++;
	flags->prnt = flags->arg == '0' ? '0' : ' ';
	if ((flags->width > flags->prec && flags->prec > 0 && flags->arg != 0)
	|| flags->prec == 0)
		flags->prnt = ' ';
	toprint = flags->width > len ? flags->width : len;
	if (flags->arg == '-')
		write(1, &s[0], len);
	while (++k < toprint - len)
		write(1, &flags->prnt, 1);
	if (!(flags->arg == '-'))
		write(1, &s[0], len);
	(*ret) += toprint;
	return (1);
}
