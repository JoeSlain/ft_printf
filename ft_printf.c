/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:23:12 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/10 16:01:31 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_good_format(t_flags *flags)
{
	char *s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (flags->data == *s)
			return (1);
		s++;
	}
	return (0);
}

int		ft_which_type(t_flags *flags, va_list ap, int *ret)
{
	int res;

	if (flags->data == 'c')
		res = ft_c(flags, ret, (char)va_arg(ap, int));
	if (flags->data == 's')
		res = ft_s(flags, ret, va_arg(ap, char*));
	if (flags->data == 'p')
		res = ft_p(flags, ret, va_arg(ap, void*), "0123456789abcdef");
	if (flags->data == 'd' || flags->data == 'i')
		res = ft_dui(flags, ret, (long int)va_arg(ap, int));
	if (flags->data == 'X')
		res = ft_x(flags, ret, "0123456789ABCDEF",
		(unsigned int)va_arg(ap, unsigned int));
	if (flags->data == 'x')
		res = ft_x(flags, ret, "0123456789abcdef",
		(unsigned int)va_arg(ap, unsigned int));
	if (flags->data == 'u')
		res = ft_u(flags, ret, (unsigned int)va_arg(ap, unsigned int));
	if (flags->data == '%')
		res = ft_perc(flags, ret);
	return (res);
}

void	ft_init(t_flags *flags)
{
	flags->prec = -1;
	flags->width = -1;
	flags->data = -1;
	flags->arg = -1;
}

int		ft_flags(const char *s, int *i, int *ret, va_list ap)
{
	t_flags *flags;

	(*i)++;
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	ft_init(flags);
	flags->arg = ft_dash_or_zero(s, i);
	flags->width = ft_width(s, i, flags, ap);
	flags->prec = ft_prec(s, i, ap);
	if (!(flags->data = s[*i]))
		return (0);
	(*i)++;
	if (ft_is_good_format(flags) == 0)
		return (0);
	if (ft_which_type(flags, ap, ret) == 0)
		return (0);
	free(flags);
	flags = NULL;
	return (1);
}

int		ft_printf(const char *s, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	ret = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			write(1, &s[i], 1);
			ret++;
			i++;
		}
		if (s[i] == '%')
			if (!(ft_flags(s, &i, &ret, ap)))
				return (-1);
	}
	return (ret);
}
