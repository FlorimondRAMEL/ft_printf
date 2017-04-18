/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:28:24 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:41:31 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_ptr(t_b *b, t_d *d, int len)
{
	d->w -= d->p > len ? len + d->p : len;
	d->w -= !d->p ? 1 : 2;
	if (!(d->f & LEFT) && (!(d->f & ZERO) || d->p >= 0))
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
	b->head += ft_fwritebuff(b, '0');
	b->head += ft_fwritebuff(b, 'x');
	if (!(d->f & LEFT) && (d->f & ZERO))
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, '0');
}

int			ft_conv_p(t_b *b, t_d *d, va_list ap)
{
	int		len;
	void	*ptr;

	d->f |= LWER;
	ptr = va_arg(ap, void *);
	len = ft_ulnbrlen_base((uintmax_t)ptr, 16);
	ft_format_ptr(b, d, len);
	if (!ptr && d->p == 0)
	{
		ft_format_char(b, d, ' ', -2);
		return (0);
	}
	else
		while (d->p-- > len)
			b->head += ft_fwritebuff(b, '0');
	b->head += ft_ulitoa_baseb(b, d, (uintmax_t)ptr, 16);
	while (d->w-- > 0)
		b->head += ft_fwritebuff(b, ' ');
	return (0);
}
