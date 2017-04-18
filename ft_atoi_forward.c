/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:56:52 by framel            #+#    #+#             */
/*   Updated: 2016/05/20 13:41:16 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_forward(const char **format)
{
	int nbr;

	nbr = 0;
	while (ft_isdigit(**format))
		nbr = nbr * 10 + *((*format)++) - '0';
	return (nbr);
}
