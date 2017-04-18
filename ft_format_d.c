/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 14:50:46 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 10:21:39 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_showsign(t_b *b, intmax_t nbr)
{
	if (nbr >= 0)
		b->head += ft_fwritebuff(b, '+');
	else
		b->head += ft_fwritebuff(b, '-');
}

static void	ft_rightpad_d(t_b *b, t_d *d, char c, int len)
{
	if (d->p > 0)
		d->w -= d->p > len ? (d->p - len) : (len - d->p - 2);
	while (--d->w > 0)
		b->head += ft_fwritebuff(b, c);
}

static void	ft_format_flags(t_b *b, t_d *d, intmax_t nbr)
{
	if (nbr < 0)
		d->f |= PLUS;
	if (d->f & PLUS)
	{
		d->w--;
		if (d->w <= 0 || d->f & ZERO)
		{
			ft_showsign(b, nbr);
			d->f &= ~PLUS;
		}
	}
	else if (d->f & SPCE)
	{
		b->head += ft_fwritebuff(b, ' ');
		d->w--;
	}
}

void		ft_format_d(t_b *b, t_d *d, intmax_t nbr)
{
	int	len;

	len = ft_ldnbrlen_base(nbr, 10);
	ft_format_flags(b, d, nbr);
	if (!(d->f & LEFT))
	{
		if (d->p == -1 && d->f & ZERO)
			ft_rightpad_d(b, d, '0', len);
		else if (d->w > d->p)
			ft_rightpad_d(b, d, ' ', len);
	}
	if (d->f & PLUS && !(d->f & ZERO))
		ft_showsign(b, nbr);
	while (d->p-- > len)
	{
		d->w--;
		b->head += ft_fwritebuff(b, '0');
	}
}
