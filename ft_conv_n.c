/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:49:57 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 16:24:48 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_n(t_b *b, t_d *d, va_list ap)
{
	int *written;

	(void)d;
	written = va_arg(ap, int *);
	if (written)
		*written = b->head;
	return (0);
}
