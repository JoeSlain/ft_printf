/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:24:11 by jcueille          #+#    #+#             */
/*   Updated: 2020/02/10 15:59:08 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	char		data;
	char		arg;
	int			prec;
	int			width;
	char		prnt;

}				t_flags;

typedef	struct	s_data
{
	char		*s;
	int			len_prec;
	int			len;
	int			total;

}				t_data;

int				ft_perc(t_flags *flags, int *ret);
int				ft_printf(const char *s, ...);
int				ft_flags(const char *s, int *i, int *ret, va_list ap);
int				ft_strlen(const char *s);
int				ft_size(long int i, int base);
char			*ft_itoabase(long long int i, int base, char *tab);
int				ft_dash_or_zero(const char *s, int *i);
int				ft_width(const char *s, int *i, t_flags *flags, va_list ap);
int				ft_c(t_flags *flags, int *ret, char c);
int				ft_s(t_flags *flags, int *ret, char *s);
int				ft_prec(const char*s, int *i, va_list ap);
int				ft_is_good_format(t_flags *flags);
int				ft_dui(t_flags *flags, int *ret, int n);
int				ft_u(t_flags *flags, int *ret, unsigned int n);
int				ft_x(t_flags *flags, int *ret, char *base, unsigned int n);
int				ft_p(t_flags *flags, int *ret, void *n, char *base);
int				ft_which_type(t_flags *flags, va_list ap, int *ret);
void			ft_init(t_flags *flags);
int				ft_flags(const char *s, int *i, int *ret, va_list ap);
int				ft_printf(const char *s, ...);
void			ft_affiche(t_data *data, t_flags *flags, int n);
int				ft_free(char *s);
#endif
