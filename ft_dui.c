/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:10:31 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/11 17:22:31 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_affiche(t_data *data, t_flags *flags, int n)
{
	int i;

	i = -1;
	if (n < 0 && (char)flags->prnt != '0')
		write(1, "-", 1);
	while (++i < data->len_prec - data->len)
		write(1, "0", 1);
	i = -1;
	while (++i < data->len && data->len_prec != 0)
		write(1, &(data->s)[i], 1);
}

int		ft_set_flags(int *i, t_flags *flags, int n, t_data *data)
{
	if (!(data->s = ft_itoabase(n, 10, "0123456789")))
		return (0);
	data->len = ft_strlen(data->s);
	data->len_prec = (flags->prec > data->len) ? flags->prec : data->len;
	if (flags->prec == (int)0 && n == 0)
		data->len_prec = 0;
	data->total = (flags->width > data->len_prec)
	? flags->width : data->len_prec;
	(*i) = flags->width > -1 ? -1 : -2;
	flags->prnt = flags->arg == '0' ? '0' : ' ';
	if ((flags->width > flags->prec && flags->prec > 0 && flags->arg != 0)
	|| flags->prec == 0)
		flags->prnt = ' ';
	if (n < 0 && flags->prec > flags->width)
		(*i)--;
	if (n < 0 && flags->prnt == '0')
		write(1, "-", 1);
	return (1);
}

int		ft_dui(t_flags *flags, int *ret, int n)
{
	t_data	*data;
	int		i;

	i = 0;
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (!(ft_set_flags(&i, flags, n, data)))
		return (0);
	(*ret) += (n < 0 && flags->width < data->len + 1) ?
	data->total + 1 : data->total;
	if (flags->width == flags->prec && flags->prec == data->len + 1 && n < 0)
		(*ret)++;
	if (n < 0)
		(data->total)--;
	if (flags->arg == '-')
		ft_affiche(data, flags, n);
	while (++i < data->total - data->len_prec)
		write(1, &flags->prnt, 1);
	if (flags->arg != '-')
		ft_affiche(data, flags, n);
	free(data->s);
	data->s = NULL;
	free(data);
	data = NULL;
	return (1);
}
