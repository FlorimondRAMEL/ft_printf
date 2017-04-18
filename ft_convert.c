/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:58:20 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:41:24 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_invalid(t_b *b, t_d *d, va_list ap)
{
	char c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	(void)ap;
	if (!(d->f & LEFT))
		while (d->w-- > 1)
			b->head += ft_fwritebuff(b, c);
	if (d->s)
		b->head += ft_fwritebuff(b, d->s);
	while (d->w-- > 1)
		b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int	ft_convert(t_b *b, t_d *d, t_f *conv_tab, va_list ap)
{
	int i;

	i = ft_isinstrspec(d->s);
	if (i < 0)
		return (ft_conv_invalid(b, d, ap));
	else
		return (conv_tab[i].p(b, d, ap));
}
