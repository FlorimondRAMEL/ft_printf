/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:51:25 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:47:17 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_hhx(t_b *b, t_d *d, va_list ap)
{
	unsigned char	nbr;
	int				len;

	nbr = va_arg(ap, unsigned int);
	if (!d->p && d->w > 0 && !nbr)
		d->w++;
	len = ft_ulnbrlen_base(nbr, 16);
	d->w -= d->p > len ? (d->p - len + 1) : (len - 1);
	if (!(d->f & LEFT))
		ft_left_format_xnbr(b, d, nbr);
	else if ((d->f & SHRP) && (nbr != 0))
	{
		d->w -= 2;
		ft_writebuff_ox(b, d);
	}
	while (d->p > len)
	{
		b->head += ft_fwritebuff(b, '0');
		d->p--;
	}
	if (d->p || nbr)
		b->head += ft_ulitoa_baseb(b, d, nbr, 16);
	if (d->w > 0)
		ft_right_format_nbr(b, d);
}

static void	ft_conv_hx(t_b *b, t_d *d, va_list ap)
{
	unsigned short int	nbr;
	int					len;

	nbr = va_arg(ap, unsigned int);
	if (!d->p && d->w > 0 && !nbr)
		d->w++;
	len = ft_ulnbrlen_base(nbr, 16);
	d->w -= d->p > len ? (d->p - len + 1) : (len - 1);
	if (!(d->f & LEFT))
		ft_left_format_xnbr(b, d, nbr);
	else if ((d->f & SHRP) && (nbr != 0))
	{
		d->w -= 2;
		ft_writebuff_ox(b, d);
	}
	while (d->p > len)
	{
		b->head += ft_fwritebuff(b, '0');
		d->p--;
	}
	if (d->p || nbr)
		b->head += ft_ulitoa_baseb(b, d, nbr, 16);
	if (d->w > 0)
		ft_right_format_nbr(b, d);
}

static void	ft_conv_lx(t_b *b, t_d *d, va_list ap)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(ap, unsigned int);
	if (!d->p && d->w > 0 && !nbr)
		d->w++;
	len = ft_ulnbrlen_base(nbr, 16);
	d->w -= d->p > len ? (d->p - len + 1) : (len - 1);
	if (!(d->f & LEFT))
		ft_left_format_xnbr(b, d, nbr);
	else if ((d->f & SHRP) && (nbr != 0))
	{
		d->w -= 2;
		ft_writebuff_ox(b, d);
	}
	while (d->p > len)
	{
		b->head += ft_fwritebuff(b, '0');
		d->p--;
	}
	if (d->p || nbr)
		b->head += ft_ulitoa_baseb(b, d, nbr, 16);
	if (d->w > 0)
		ft_right_format_nbr(b, d);
}

static void	ft_conv_ulx(t_b *b, t_d *d, va_list ap)
{
	unsigned long int	nbr;
	int					len;

	nbr = va_arg(ap, unsigned long int);
	if (!d->p && d->w > 0 && !nbr)
		d->w++;
	len = ft_ulnbrlen_base(nbr, 16);
	d->w -= d->p > len ? (d->p - len + 1) : (len - 1);
	if (!(d->f & LEFT))
		ft_left_format_xnbr(b, d, nbr);
	else if ((d->f & SHRP) && (nbr != 0))
	{
		d->w -= 2;
		ft_writebuff_ox(b, d);
	}
	while (d->p > len)
	{
		b->head += ft_fwritebuff(b, '0');
		d->p--;
	}
	if (d->p || nbr)
		b->head += ft_ulitoa_baseb(b, d, nbr, 16);
	if (d->w > 0)
		ft_right_format_nbr(b, d);
}

int			ft_conv_x(t_b *b, t_d *d, va_list ap)
{
	if (d->s == 'x')
		d->f |= LWER;
	else
		d->f &= ~LWER;
	if (d->f & L || d->f & J || d->f & Z || d->f & T)
		ft_conv_ulx(b, d, ap);
	else if (d->f & HH)
		ft_conv_hhx(b, d, ap);
	else if (d->f & H)
		ft_conv_hx(b, d, ap);
	else
		ft_conv_lx(b, d, ap);
	return (0);
}
