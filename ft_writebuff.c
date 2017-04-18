/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writebuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:00:08 by framel            #+#    #+#             */
/*   Updated: 2016/06/01 21:25:57 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fwritebuff(t_b *b, char c)
{
	if (b->curr > (b->head))
		b->buff[b->head] = c;
	else
	{
		ft_buffrealloc(b);
		b->curr += BUFF_SIZE;
		ft_fwritebuff(b, c);
	}
	return (1);
}

int	ft_writebuff(t_b *b, char c, int shift)
{
	if (b->curr > (b->head + shift))
		b->buff[b->head + shift] = c;
	else
	{
		ft_buffrealloc(b);
		b->curr += BUFF_SIZE;
		ft_writebuff(b, c, shift);
	}
	return (1);
}
