/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:55:20 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/06 18:37:35 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_perc(t_flags *flags, int *ret)
{
	int k;
	int toprint;

	flags->prnt = flags->arg == '0' ? '0' : ' ';
	k = -1;
	if (flags->width > 0)
		toprint = flags->width;
	else
		toprint = 1;
	if (flags->arg == '-')
		write(1, "%", 1);
	while (++k < toprint - 1)
		write(1, &flags->prnt, 1);
	if (!(flags->arg == '-'))
		write(1, "%", 1);
	(*ret) += toprint;
	return (1);
}
