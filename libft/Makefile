# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:55:15 by ibohonos          #+#    #+#              #
#    Updated: 2018/02/02 16:17:01 by ibohonos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR		= ./obj
SRC_DIR 	= ./srcs
INCL_DIR 	= ./includes
OBJ 		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC 		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
			ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c \
			ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_printf.c ft_find_types.c ft_init_flags.c ft_type_d.c \
			ft_type_s.c ft_type_c.c ft_type_x.c ft_type_o.c ft_type_u.c \
			ft_init_modific.c ft_init_specific.c ft_is_spec.c \
			ft_init_default_all.c ft_count_nbrs.c ft_find.c ft_itoa_base.c \
			ft_unsigned_itoa_base.c ft_init_precision.c ft_init_width.c \
			ft_print_width.c ft_init_types.c ft_type_lu.c ft_type_llu.c \
			ft_type_hu.c ft_type_hhu.c ft_type_ju.c ft_type_zu.c \
			ft_type_lx.c ft_type_llx.c ft_type_hx.c ft_type_hhx.c \
			ft_type_jx.c ft_type_zx.c ft_type_ld.c ft_type_lld.c \
			ft_type_hd.c ft_type_hhd.c ft_type_jd.c ft_type_zd.c \
			ft_type_lo.c ft_type_llo.c ft_type_ho.c ft_type_hho.c \
			ft_type_jo.c ft_type_zo.c ft_type_p.c ft_type_ln.c \
			ft_type_lln.c ft_type_hn.c ft_type_hhn.c ft_type_jn.c \
			ft_type_zn.c ft_type_n.c ft_type_wchar.c ft_type_b.c \
			ft_type_cl.c ft_strupper.c ft_print_precision.c \
			ft_count_len_bits.c ft_count_len_bit.c ft_type_x_help_ifs.c \
			get_next_line.c

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(INCL_DIR) -o $@ -c $<

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
