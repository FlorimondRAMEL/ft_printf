# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/12 11:17:31 by framel            #+#    #+#              #
#    Updated: 2016/06/03 14:51:42 by framel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

IFLAG = -I.

HEADER = ft_printf.h

SRCS = printf buffrealloc isdigit putstr_retfd vsprintf atoi_forward strlen\
	   writebuff buffalloc vprintf init_conv parse_info convert\
	   isinstr conv_d putstrbuff conv_o conv_x conv_pt\
	   format_char format_nbr ulitoa_baseb conv_c conv_s format_d\
	   lditoa_baseb conv_i format conv_fd\
	   conv_p conv_cc conv_ss conv_n conv_color

FT_SRCS := $(addprefix ft_, $(SRCS))

FT_OBJS := $(addsuffix .o, $(FT_SRCS))

FT_SRCS := $(addsuffix .c, $(SRCS))

all: $(NAME)

$(NAME): $(HEADER) $(FT_OBJS)
	@ar rc $(NAME) $(FT_OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) is done"

%.o: %.c
	@$(CC) $(CFLAG) -o $@ -c $? $(IFLAG)
	@echo "creating $@ from $?"

clean:
	@/bin/rm -f $(FT_OBJS)
	@echo "cleaning $(NAME) objects files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "cleaning all $(NAME) files"

re: fclean all
	@echo "$(NAME) is reset"

.PHONY: all clean fclean re
