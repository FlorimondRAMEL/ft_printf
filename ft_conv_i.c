/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:03:08 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:44:50 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_conv_o(t_b *b, t_d *d, uintmax_t nbr, int base)
{
	int		len;
	char	c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	len = ft_ulnbrlen_base(nbr, base);
	if (d->f & SHRP && (d->s == 'o' || d->s == 'O'))
		len++;
	d->p = d->p - len;
	d->p = (d->p > 0) ? d->p : 0;
	d->w = d->w - d->p - len;
	if (!(d->f & LEFT))
		ft_rightpad(b, d, c);
	if (nbr == 0)
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, c);
	while (d->p-- > 0)
		b->head += ft_fwritebuff(b, '0');
	if (d->f & SHRP && nbr != 0 && (d->s == 'o' || d->s == 'O'))
		b->head += ft_fwritebuff(b, '0');
}

int			ft_conv_i(t_b *b, t_d *d, int base, va_list ap)
{
	unsigned int	nbr;

	nbr = va_arg(ap, unsigned int);
	if (nbr == 0 && d->p == 0)
	{
		ft_rightpad(b, d, ' ');
		if (d->f & SHRP && (d->s == 'o' || d->s == 'O'))
			b->head += ft_fwritebuff(b, '0');
		return (0);
	}
	ft_format_conv_o(b, d, nbr, base);
	b->head += ft_ulitoa_baseb(b, d, nbr, base);
	if (d->f & LEFT)
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_l(t_b *b, t_d *d, int base, va_list ap)
{
	unsigned long int	nbr;

	nbr = va_arg(ap, unsigned long int);
	if (nbr == 0 && d->p == 0)
	{
		ft_rightpad(b, d, ' ');
		if (d->f & SHRP && (d->s == 'o' || d->s == 'O'))
			b->head += ft_fwritebuff(b, '0');
		return (0);
	}
	ft_format_conv_o(b, d, nbr, base);
	b->head += ft_ulitoa_baseb(b, d, nbr, base);
	if (d->f & LEFT)
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_h(t_b *b, t_d *d, int base, va_list ap)
{
	unsigned short int	nbr;

	nbr = va_arg(ap, unsigned int);
	if (nbr == 0 && d->p == 0)
	{
		ft_rightpad(b, d, ' ');
		if (d->f & SHRP && (d->s == 'o' || d->s == 'O'))
			b->head += ft_fwritebuff(b, '0');
		return (0);
	}
	ft_format_conv_o(b, d, nbr, base);
	b->head += ft_ulitoa_baseb(b, d, nbr, base);
	if (d->f & LEFT)
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_hh(t_b *b, t_d *d, int base, va_list ap)
{
	unsigned char	nbr;

	nbr = va_arg(ap, unsigned int);
	if (nbr == 0 && d->p == 0)
	{
		ft_rightpad(b, d, ' ');
		if (d->f & SHRP && (d->s == 'o' || d->s == 'O'))
			b->head += ft_fwritebuff(b, '0');
		return (0);
	}
	ft_format_conv_o(b, d, nbr, base);
	b->head += ft_ulitoa_baseb(b, d, nbr, base);
	if (d->f & LEFT)
		while (d->w-- > 0)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}
