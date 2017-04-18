/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_baseb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:43:23 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 14:46:32 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulnbrlen_base(uintmax_t value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
		len = 1;
	while (value != 0)
	{
		value = value / base;
		len = len + 1;
	}
	return (len);
}

int	ft_ulitoa_baseb(t_b *b, t_d *d, uintmax_t value, int base)
{
	int	nb_len;
	int	i;

	if (base < 2 || base > 36)
		return (-1);
	nb_len = ft_ulnbrlen_base(value, base);
	i = nb_len - 1;
	if (value == 0)
		ft_writebuff(b, '0', i--);
	while (value != 0)
	{
		if (d->f & LWER)
			ft_writebuff(b, DIG_LO(value % base), i--);
		else
			ft_writebuff(b, DIG_UP(value % base), i--);
		value = value / base;
	}
	return (nb_len);
}
