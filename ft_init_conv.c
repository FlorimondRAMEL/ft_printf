/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:58:27 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 14:49:47 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_f	*ft_init_conv_next(t_f *conv_tab)
{
	conv_tab[17].p = ft_conv_cc;
	conv_tab[18].p = ft_conv_c;
	conv_tab[19].p = ft_conv_ss;
	conv_tab[20].p = ft_conv_s;
	conv_tab[21].p = ft_conv_p;
	conv_tab[22].p = ft_conv_n;
	conv_tab[23].p = ft_conv_pt;
	conv_tab[24].p = ft_conv_fd;
	conv_tab[25].p = ft_conv_base;
	conv_tab[26].p = ft_conv_color;
	conv_tab[27].p = ft_conv_invalid;
	return (conv_tab);
}

t_f			*ft_init_conv(t_f *conv_tab)
{
	if ((conv_tab = (t_f *)malloc(sizeof(t_f) * 28)) == NULL)
		return (NULL);
	conv_tab[0].p = ft_conv_d;
	conv_tab[1].p = ft_conv_d;
	conv_tab[2].p = ft_conv_o;
	conv_tab[3].p = ft_conv_u;
	conv_tab[4].p = ft_conv_x;
	conv_tab[5].p = ft_conv_x;
	conv_tab[6].p = ft_conv_d;
	conv_tab[7].p = ft_conv_o;
	conv_tab[8].p = ft_conv_u;
	conv_tab[9].p = ft_conv_d;
	conv_tab[10].p = ft_conv_d;
	conv_tab[11].p = ft_conv_d;
	conv_tab[12].p = ft_conv_d;
	conv_tab[13].p = ft_conv_d;
	conv_tab[14].p = ft_conv_d;
	conv_tab[15].p = ft_conv_d;
	conv_tab[16].p = ft_conv_d;
	ft_init_conv_next(conv_tab);
	return (conv_tab);
}
