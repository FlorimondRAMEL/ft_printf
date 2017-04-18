/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffrealloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:57:24 by framel            #+#    #+#             */
/*   Updated: 2016/05/20 11:14:16 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_buffrealloc(t_b *b)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = b->buff;
	if (b->buff)
	{
		if ((b->buff = malloc(b->curr + BUFF_SIZE)) == NULL)
			return (-1);
		while (++i < (int)b->curr)
			b->buff[i] = tmp[i];
		free(tmp);
		return (0);
	}
	return (-1);
}
