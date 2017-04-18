/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:02:33 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:43:54 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_hhd(t_b *b, t_d *d, va_list ap)
{
	char	nbr;
	int		len;

	nbr = va_arg(ap, int);
	len = ft_ldnbrlen_base(nbr, 10);
	d->w -= len - 1;
	if (nbr == 0 && d->p == 0)
	{
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
		return (0);
	}
	ft_format_d(b, d, nbr);
	ft_lditoa_baseb(b, nbr, 10);
	b->head += len;
	if (d->f & LEFT)
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

static int	ft_conv_hd(t_b *b, t_d *d, va_list ap)
{
	short int	nbr;
	int			len;

	nbr = va_arg(ap, int);
	len = ft_ldnbrlen_base(nbr, 10);
	d->w -= len - 1;
	if (nbr == 0 && d->p == 0)
	{
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
		return (0);
	}
	ft_format_d(b, d, nbr);
	ft_lditoa_baseb(b, nbr, 10);
	b->head += len;
	if (d->f & LEFT)
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

static int	ft_conv_ld(t_b *b, t_d *d, va_list ap)
{
	long int	nbr;
	int			len;

	nbr = va_arg(ap, long int);
	len = ft_ldnbrlen_base(nbr, 10);
	d->w -= len - 1;
	if (nbr == 0 && d->p == 0)
	{
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
		return (0);
	}
	ft_format_d(b, d, nbr);
	ft_lditoa_baseb(b, nbr, 10);
	b->head += len;
	if (d->f & LEFT)
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

static int	ft_conv_id(t_b *b, t_d *d, va_list ap)
{
	int	nbr;
	int len;

	nbr = va_arg(ap, int);
	len = ft_ldnbrlen_base(nbr, 10);
	d->w -= len - 1;
	if (nbr == 0 && d->p == 0)
	{
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
		return (0);
	}
	ft_format_d(b, d, nbr);
	ft_lditoa_baseb(b, nbr, 10);
	b->head += len;
	if (d->f & LEFT)
		while (--d->w > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_d(t_b *b, t_d *d, va_list ap)
{
	int ret;

	if (d->f & L || d->f & Z || d->f & J || d->s & T || d->s == 'D')
		ret = ft_conv_ld(b, d, ap);
	else if (d->f & HH)
		ret = ft_conv_hhd(b, d, ap);
	else if (d->f & H)
		ret = ft_conv_hd(b, d, ap);
	else
		ret = ft_conv_id(b, d, ap);
	return (ret);
}
