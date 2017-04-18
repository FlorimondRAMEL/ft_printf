/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:57:13 by framel            #+#    #+#             */
/*   Updated: 2016/06/01 23:21:00 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_buffalloc(char **buff)
{
	if (BUFF_SIZE > 0)
	{
		if ((*buff = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
			return (-1);
		return (0);
	}
	return (-1);
}
