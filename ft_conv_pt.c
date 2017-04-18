/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:57:48 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:28:25 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_pt(t_b *b, t_d *d, va_list ap)
{
	char c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	(void)ap;
	if (!(d->f & LEFT))
		ft_format_char(b, d, c, 0);
	b->head += ft_fwritebuff(b, '%');
	if (d->w > 0)
		ft_format_char(b, d, ' ', 0);
	return (0);
}
