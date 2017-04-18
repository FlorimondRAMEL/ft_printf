/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:59:49 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 13:39:22 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_exit(int ret, t_f **conv_tab, t_b *b)
{
	free(*conv_tab);
	free(b->buff);
	return (ret);
}

static void	ft_init_var(t_b *b, char **buff, t_f **conv_tab)
{
	b->buff = *buff;
	b->head = 0;
	b->curr = BUFF_SIZE;
	*conv_tab = NULL;
}

int			ft_vsprintf(char *buff, const char *format, va_list ap)
{
	t_d	d;
	t_b	b;
	t_f	*conv_tab;
	int ret;

	ft_init_var(&b, &buff, &conv_tab);
	if ((conv_tab = ft_init_conv(conv_tab)) == NULL)
		return (-1);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
			b.head += ft_writebuff(&b, *(format++), 0);
		if (*format != '\0')
		{
			ft_parse_info(&d, &format, ap);
			if ((ret = ft_convert(&b, &d, conv_tab, ap)))
				return (ft_exit(ret, &conv_tab, &b));
			if (*format != '\0')
				format++;
		}
	}
	ft_putbuff(1, b.buff, b.head);
	free(conv_tab);
	free(b.buff);
	return (b.head);
}
