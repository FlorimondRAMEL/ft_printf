/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:12:31 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:36:54 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_wchar(t_b *b, unsigned int wchar)
{
	if (wchar < 128)
		b->head += ft_fwritebuff(b, wchar);
	else if (wchar < 2048)
	{
		b->head += ft_fwritebuff(b, 192 | (wchar >> 6));
		b->head += ft_fwritebuff(b, 128 | (wchar & 63));
	}
	else if (wchar < 65536)
	{
		b->head += ft_fwritebuff(b, 224 | (wchar >> 12));
		b->head += ft_fwritebuff(b, 128 | ((wchar >> 6) & 63));
		b->head += ft_fwritebuff(b, 128 | (wchar & 63));
	}
	else if (wchar < 1114112)
	{
		b->head += ft_fwritebuff(b, 240 | (wchar >> 18));
		b->head += ft_fwritebuff(b, 128 | ((wchar >> 12) & 63));
		b->head += ft_fwritebuff(b, 128 | ((wchar >> 6) & 63));
		b->head += ft_fwritebuff(b, 128 | (wchar & 63));
	}
}

int		ft_conv_cc(t_b *b, t_d *d, va_list ap)
{
	unsigned int	wchar;
	int				len;
	char			c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	wchar = va_arg(ap, unsigned int);
	len = ft_sizeof_wchar(wchar);
	if (len > 0)
	{
		if (!(d->f & LEFT))
			ft_format_char(b, d, c, len - 1);
		ft_conv_wchar(b, wchar);
		if (d->f & LEFT)
			ft_format_char(b, d, c, len - 1);
		return (0);
	}
	return (-1);
}
