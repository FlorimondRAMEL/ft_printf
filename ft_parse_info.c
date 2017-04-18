/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:58:45 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:18:51 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_d *d, const char **format)
{
	if (**format == '-')
		d->f |= LEFT;
	else if (**format == '+')
		d->f |= PLUS;
	else if (**format == ' ')
	{
		d->f |= SPCE;
		d->f &= ~ZERO;
	}
	else if (**format == '#')
		d->f |= SHRP;
	else if (**format == '0' && !(d->f & LEFT))
		d->f |= ZERO;
	(*format)++;
}

static void	get_wdth(t_d *d, const char **format, va_list ap)
{
	d->w = 0;
	if (ft_isdigit(**format))
		d->w = ft_atoi_forward(format);
	if (**format == '*')
	{
		d->w = va_arg(ap, int);
		(*format)++;
		if (ft_isdigit(**format))
			get_wdth(d, format, ap);
	}
	if (d->w < 0)
	{
		d->w = -d->w;
		d->f |= LEFT;
	}
}

static void	get_prec(t_d *d, const char **format, va_list ap)
{
	d->p = -1;
	while (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
			d->p = ft_atoi_forward(format);
		else if (**format == '*')
		{
			d->p = va_arg(ap, int);
			if (d->p < 0)
				d->p = -1;
			(*format)++;
		}
		else
			d->p = 0;
	}
}

static void	get_modi(t_d *d, const char **format)
{
	if (**format == 'h')
	{
		if (d->f & H)
			d->f |= HH;
		else
			d->f |= H;
	}
	else if (**format == 'l')
	{
		if (d->f & L)
			d->f |= LL;
		else
			d->f |= L;
	}
	else if (**format == 'L')
		d->f |= LLL;
	else if (**format == 'j')
		d->f |= J;
	else if (**format == 'z')
		d->f |= Z;
	else if (**format == 't')
		d->f |= T;
	(*format)++;
}

void		ft_parse_info(t_d *d, const char **format, va_list ap)
{
	d->f = 0;
	(*format)++;
	while (ft_isinstr(**format, STR_FLAG) >= 0)
		parse_flags(d, format);
	get_wdth(d, format, ap);
	get_prec(d, format, ap);
	while (ft_isinstr(**format, STR_MODI) >= 0)
		get_modi(d, format);
	while (ft_isinstr(**format, STR_FLAG) >= 0)
		parse_flags(d, format);
	d->s = **format;
}
