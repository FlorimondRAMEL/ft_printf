/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrbuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:59:17 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 14:47:59 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrbuff(t_b *b, const char *str, int prec)
{
	int i;

	i = 0;
	if (!str)
		return (ft_putstrbuff(b, "(null)", prec));
	else if (prec < 0)
		while (str[i])
			i += ft_writebuff(b, str[i], i);
	else if (!prec)
		while (str[i] && prec-- < 0)
			i += ft_writebuff(b, ' ', i);
	else
		while (str[i] && prec--)
			i += ft_writebuff(b, str[i], i);
	return (i);
}
