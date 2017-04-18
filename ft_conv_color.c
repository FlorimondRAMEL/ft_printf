/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:47:01 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 14:58:24 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_color(t_b *b, t_d *d, va_list ap)
{
	int	color;

	color = va_arg(ap, int);
	b->head += ft_putstrbuff(b, "\e[", 3);
	b->head += ft_ulitoa_baseb(b, d, color, 10);
	b->head += ft_fwritebuff(b, 'm');
	return (0);
}
