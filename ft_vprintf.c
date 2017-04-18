/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:59:29 by framel            #+#    #+#             */
/*   Updated: 2016/05/20 11:24:56 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Buff is allocated in ft_vprintf by ft_buffalloc
**	and freed at the end of ft_vsprintf function.
**	Do not free it in ft_vprintf!!!
*/

int	ft_vprintf(const char *format, va_list ap)
{
	int		ret;
	char	*buff;

	buff = NULL;
	if (ft_buffalloc(&buff))
		return (-1);
	ret = ft_vsprintf(buff, format, ap);
	return (ret);
}
