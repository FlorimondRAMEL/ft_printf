/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lditoa_baseb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 20:13:54 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 14:43:54 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ldnbrlen_base(intmax_t value, int base)
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

int	ft_lditoa_baseb(t_b *b, intmax_t value, int base)
{
	int	nb_len;
	int	i;

	if (base < 2 || base > 36)
		return (-1);
	nb_len = ft_ldnbrlen_base(value, base);
	i = nb_len - 1;
	if (value == 0)
		ft_writebuff(b, '0', i--);
	while (value != 0)
	{
		ft_writebuff(b, value < 0 ? DIG_UP(-(value % base)) : \
				DIG_UP(value % base), i--);
		value = value / base;
	}
	return (nb_len);
}
