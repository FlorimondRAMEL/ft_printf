/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:52:40 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:44:07 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writebuff_ox(t_b *b, t_d *d)
{
	b->head += ft_fwritebuff(b, '0');
	if (d->f & LWER)
		b->head += ft_fwritebuff(b, 'x');
	else
		b->head += ft_fwritebuff(b, 'X');
}

void	ft_left_format_xnbr(t_b *b, t_d *d, uintmax_t nbr)
{
	char c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	if (nbr != 0 && (d->f & SHRP))
		d->w -= 2;
	if (!(d->f & ZERO))
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, c);
	if ((d->s == 'x' || d->s == 'X') && nbr != 0 && (d->f & SHRP))
		ft_writebuff_ox(b, d);
	else if ((d->s == 'o') && (d->f & SHRP))
		b->head += ft_fwritebuff(b, '0');
	if (d->f & ZERO)
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, c);
}

void	ft_right_format_nbr(t_b *b, t_d *d)
{
	while (--d->w > 0)
		b->head += ft_fwritebuff(b, ' ');
}
