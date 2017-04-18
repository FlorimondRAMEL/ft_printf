/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:43:59 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 15:10:22 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_wlen(t_d *d, wchar_t *wchar, int *len)
{
	int	tmp;

	while (*wchar && d->p - *len > 0)
	{
		tmp = ft_sizeof_wchar(*wchar++);
		if (d->p - (*len + tmp) >= 0)
			*len += tmp;
	}
	return (0);
}

static int	ft_putwcharb(t_b *b, t_d *d, wchar_t *wchar, int len)
{
	if (wchar)
	{
		if (d->p < 0)
			while (*wchar)
				ft_conv_wchar(b, *wchar++);
		else
			while (*wchar)
			{
				if (d->p >= ft_sizeof_wchar(*wchar))
					ft_conv_wchar(b, *wchar);
				d->p -= ft_sizeof_wchar(*wchar++);
			}
	}
	else
		b->head += ft_putstrbuff(b, "(null)", 6);
	while (d->w-- > len)
		b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_ss(t_b *b, t_d *d, va_list ap)
{
	wchar_t			*wchar;
	int				len;
	char			c;

	len = 0;
	c = ' ';
	if (d->f & ZERO)
		c = '0';
	wchar = va_arg(ap, wchar_t *);
	if (d->p > 0)
		ft_get_wlen(d, wchar, &len);
	else
		len = ft_wstrlen(wchar);
	if (!(d->f & LEFT))
	{
		if (d->p)
			while (d->w-- > len)
				b->head += ft_fwritebuff(b, c);
		else
			while (d->w-- > 0)
				b->head += ft_fwritebuff(b, c);
	}
	return (ft_putwcharb(b, d, wchar, len));
}
