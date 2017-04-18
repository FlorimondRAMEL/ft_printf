/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:57:37 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:19:14 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(t_b *b, t_d *d, va_list ap)
{
	int		c;
	char	z;

	z = ' ';
	if (d->f & L)
		return (ft_conv_cc(b, d, ap));
	if (d->f & ZERO)
		z = '0';
	c = va_arg(ap, int);
	if (!(d->f & LEFT))
		ft_format_char(b, d, z, 0);
	b->head += ft_fwritebuff(b, c);
	if (d->w > 0)
		ft_format_char(b, d, ' ', 0);
	return (0);
}
