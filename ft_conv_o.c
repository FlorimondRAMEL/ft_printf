/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:50:14 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 13:50:11 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_unsigned(t_b *b, t_d *d, int base, va_list ap)
{
	if (d->f & L || d->f & J || d->f & Z || d->f & T || d->s == 'O' \
			|| d->s == 'U')
		return (ft_conv_l(b, d, base, ap));
	else if (d->f & HH)
		return (ft_conv_hh(b, d, base, ap));
	else if (d->f & H)
		return (ft_conv_h(b, d, base, ap));
	else
		return (ft_conv_i(b, d, base, ap));
}

int			ft_conv_o(t_b *b, t_d *d, va_list ap)
{
	return (ft_conv_unsigned(b, d, 8, ap));
}

int			ft_conv_u(t_b *b, t_d *d, va_list ap)
{
	return (ft_conv_unsigned(b, d, 10, ap));
}

int			ft_conv_base(t_b *b, t_d *d, va_list ap)
{
	int	base;

	if (d->p > 0)
		base = d->p;
	else
		base = 2;
	d->p = -1;
	return (ft_conv_unsigned(b, d, base, ap));
}
