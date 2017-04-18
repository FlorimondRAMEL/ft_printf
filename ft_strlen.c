/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:59:23 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 15:09:56 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sizeof_wchar(wchar_t wchar)
{
	int i;

	if (wchar < 0)
		return (-1);
	else if (wchar < 0x80)
		i = 1;
	else if (wchar < 0x800)
		i = 2;
	else if (wchar < 0xD800)
		i = 3;
	else if (wchar < 0xE000)
		return (-1);
	else if (wchar < 0x10000)
		i = 3;
	else if (wchar < 0x110000)
		i = 4;
	else
		return (-1);
	return (i);
}

int		ft_wstrlen(wchar_t *str)
{
	int i;
	int size;

	i = 0;
	if (str)
		while (*str != '\0')
		{
			size = ft_sizeof_wchar(*str);
			if (size >= 0)
				i += size;
			else
				return (-1);
			str++;
		}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
		while (*str++ != '\0')
		{
			i++;
		}
	return (i);
}
