/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:01:13 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 14:59:20 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_fd(t_b *b, t_d *d, va_list ap)
{
	int		fd;

	(void)d;
	fd = va_arg(ap, int);
	ft_putbuff(fd, b->buff, b->head);
	return (b->head);
}
