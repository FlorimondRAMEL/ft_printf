/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:59:01 by framel            #+#    #+#             */
/*   Updated: 2016/06/03 14:50:58 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 42

# define ZERO 0x1
# define SIGN 0x2
# define PLUS 0x4
# define SPCE 0x8
# define LEFT 0x10
# define SHRP 0x20
# define LWER 0x40
# define QOTE 0x80

# define HH     0x100
# define H      0x200
# define L      0x400
# define LL     0x800
# define LLL    0x1000
# define J      0x2000
# define Z      0x4000
# define T      0x8000

# define DIG_LO(x) "0123456789abcdefghijklmnoparstuvwxyz"[x]
# define DIG_UP(x) "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[x]

# define STR_FLAG   "$#0- +'"
# define STR_MODI  "hljztL"
# define STR_SPEC "diouxXDOUeEaAfFgGCcSspn%vbk\0"

typedef struct		s_d
{
	int				f;
	int				w;
	int				p;
	int				s;
}					t_d;

typedef struct		s_b
{
	char			*buff;
	int				head;
	int				curr;
}					t_b;

typedef	struct		s_f
{
	int				(*p)(t_b *b, t_d *d, va_list ap);
}					t_f;

/*
**	FT_PRINTF FUNCTIONS
*/

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vsprintf(char *buff, const char *format, va_list ap);

/*
**	BUFFER MANAGEMENT
*/

int					ft_buffalloc(char **buff);
int					ft_buffrealloc(t_b *b);
int					ft_writebuff(t_b *b, char c, int shift);
int					ft_fwritebuff(t_b *b, char c);
int					ft_putstrbuff(t_b *b, const char *str, int prec);
char				*ft_joinbuff(char *s1, char const *s2);
void				ft_writebuff_ox(t_b *b, t_d *d);

/*
**	STRINGS FUNCTIONS
*/

int					ft_isdigit(int c);
int					ft_wstrlen(wchar_t *str);
int					ft_sizeof_wchar(wchar_t wchar);
int					ft_putbuff(int fd, char const *buff, int head);
int					ft_isinstr(char c, char *str);
void				ft_conv_wchar(t_b *b, unsigned int wchar);
size_t				ft_strlen(const char *str);

/*
**	FORMAT FUNCTIONS
*/

void				ft_format_char(t_b *b, t_d *d, char c, int n);
void				ft_format_str(t_b *b, t_d *d, char c, int n);
void				ft_left_format_xnbr(t_b *b, t_d *d, uintmax_t nbr);
void				ft_right_format_nbr(t_b *b, t_d *d);
void				ft_format_d(t_b *b, t_d *d, intmax_t nbr);
void				ft_rightpad(t_b *b, t_d *d, char c);

/*
**	NUMBER FUNCTIONS
*/

int					ft_atoi_forward(const char **format);
int					ft_lditoa_baseb(t_b *b, intmax_t value, int base);
int					ft_ulitoa_baseb(t_b *b, t_d *d, uintmax_t value, int base);
int					ft_ulnbrlen_base(uintmax_t value, int base);
int					ft_ldnbrlen_base(intmax_t value, int base);
int					ft_conv_hh(t_b *b, t_d *d, int base, va_list ap);
int					ft_conv_h(t_b *b, t_d *d, int base, va_list ap);
int					ft_conv_i(t_b *b, t_d *d, int base, va_list ap);
int					ft_conv_l(t_b *b, t_d *d, int base, va_list ap);

/*
**	CONVERSION FUNCTIONS
*/

int					ft_conv_d(t_b *b, t_d *d, va_list ap);
int					ft_conv_o(t_b *b, t_d *d, va_list ap);
int					ft_conv_u(t_b *b, t_d *d, va_list ap);
int					ft_conv_x(t_b *b, t_d *d, va_list ap);
int					ft_conv_cc(t_b *b, t_d *d, va_list ap);
int					ft_conv_c(t_b *b, t_d *d, va_list ap);
int					ft_conv_ss(t_b *b, t_d *d, va_list ap);
int					ft_conv_s(t_b *b, t_d *d, va_list ap);
int					ft_conv_p(t_b *b, t_d *d, va_list ap);
int					ft_conv_n(t_b *b, t_d *d, va_list ap);
int					ft_conv_pt(t_b *b, t_d *d, va_list ap);
int					ft_conv_fd(t_b *b, t_d *d, va_list ap);
int					ft_conv_base(t_b *b, t_d *d, va_list ap);
int					ft_conv_color(t_b *b, t_d *d, va_list ap);
int					ft_conv_invalid(t_b *b, t_d *d, va_list ap);

/*
**	PROCESSING FUNCTIONS
*/

t_f					*ft_init_conv(t_f *conv_tab);
int					ft_isinstrspec(char c);
int					ft_exit(int ret, t_f **conv_tab, t_b *b);
int					ft_convert(t_b *b, t_d *d, t_f *conv_tab, va_list ap);
void				ft_parse_info(t_d *d, const char **format, va_list ap);

#endif
