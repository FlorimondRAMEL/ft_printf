/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:09:28 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 12:54:10 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isinstrspec(char c)
{
	char	*str;
	int		i;

	str = STR_SPEC;
	i = -1;
	while (++i <= 27)
		if (str[i] == c)
			return (i);
	return (-1);
}

int	ft_isinstr(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
