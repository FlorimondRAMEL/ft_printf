/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:58:02 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 11:39:32 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_string(t_b *b, t_d *d, char **s, int len)
{
	char	c;

	c = ' ';
	if (d->f & ZERO)
		c = '0';
	if (!(d->f & LEFT))
		if (*s || d->f && ZERO)
			while (d->w-- > len)
				b->head += ft_fwritebuff(b, c);
	b->head += ft_putstrbuff(b, *s, d->p);
	if (!d->p)
		while (d->w-- >= 0)
			b->head += ft_fwritebuff(b, c);
	if (*s)
		while (d->w-- > len)
			b->head += ft_fwritebuff(b, ' ');
	return (0);
}

int			ft_conv_s(t_b *b, t_d *d, va_list ap)
{
	char	*s;
	int		len;

	if (d->f & L)
		return (ft_conv_ss(b, d, ap));
	len = 0;
	s = va_arg(ap, char *);
	if (s)
		len = ft_strlen(s);
	if (d->p > 0 && len > d->p)
		len = d->p;
	ft_format_string(b, d, &s, len);
	return (0);
}
