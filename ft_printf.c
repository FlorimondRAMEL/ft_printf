/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:58:54 by framel            #+#    #+#             */
/*   Updated: 2016/06/02 14:44:26 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format)
	{
		va_start(ap, format);
		ret = ft_vprintf(format, ap);
		va_end(ap);
		return (ret);
	}
	return (-1);
}
