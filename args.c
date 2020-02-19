/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:27:14 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/06 18:59:09 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dash_or_zero(const char *s, int *i)
{
	char ret;

	ret = -1;
	while (s[*i] == '0' || s[*i] == '-')
	{
		if (s[*i] == '0' && ret != '-')
			ret = s[*i];
		else if (s[*i] == '-')
			ret = s[*i];
		(*i)++;
	}
	return (ret);
}

int	ft_width(const char *s, int *i, t_flags *flags, va_list ap)
{
	long int	ret;

	ret = -1;
	if (s[*i] == '*')
	{
		(*i)++;
		if ((ret = va_arg(ap, int)) < 0)
		{
			flags->arg = '-';
			ret *= -1;
		}
		return ((int)ret);
	}
	ret = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		ret = (10 * ret) + s[*i] - '0';
		(*i)++;
	}
	if (s[*i] > '9' && s[*i] < '0')
		ret = -1;
	return (ret);
}

int	ft_prec(const char *s, int *i, va_list ap)
{
	int ret;

	if (s[*i] == '.')
	{
		(*i)++;
		if (s[*i] == '*')
		{
			ret = va_arg(ap, int);
			(*i)++;
			return (ret);
		}
		ret = 0;
		if (s[*i] >= '0' && s[*i] <= '9')
		{
			while (s[*i] >= '0' && s[*i] <= '9')
			{
				ret = (ret * 10) + s[*i] - '0';
				(*i)++;
			}
		}
		return (ret);
	}
	return (-1);
}
