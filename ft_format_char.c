/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:00:03 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 12:38:00 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_char(t_b *b, t_d *d, char c, int n)
{
	while (--d->w > n)
		b->head += ft_fwritebuff(b, c);
}

void	ft_format_str(t_b *b, t_d *d, char c, int n)
{
	while (d->w > n)
	{
		b->head += ft_fwritebuff(b, c);
		d->w--;
	}
}
