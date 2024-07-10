NAME = libft.a


SRC_DIR = src

LIBFT_DIR = Libft
LIBFT_SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_ischarset.c \
	ft_count_words.c \
	ft_strlen.c \
	ft_nbrlen.c \
	ft_nbrlen_base.c \
	ft_strtoupper.c \
	ft_strtolower.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_valabs.c \
	ft_atoi.c \
	ft_atoi_base.c \
	ft_atol.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_convert_base.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr_base_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
LIBFT = ${addprefix ${LIBFT_DIR}/, ${LIBFT_SRC}}

GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_SRC = get_next_line.c
GET_NEXT_LINE = ${addprefix ${GET_NEXT_LINE_DIR}/, ${GET_NEXT_LINE_SRC}}

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRC = pf_printf.c \
	pf_eval_format.c \
	pf_checkcase.c \
	pf_addprefix.c \
	pf_print_prefix.c \
	pf_putchar.c \
	pf_putstr.c \
	pf_putptr.c \
	pf_putnbr.c \
	pf_putu_base.c \
	pf_unbrlen_base.c
FT_PRINTF = ${addprefix ${FT_PRINTF_DIR}/, ${FT_PRINTF_SRC}}

FT_FPRINTF_DIR = ft_fprintf
FT_FPRINTF_SRC = fpf_printf.c \
	fpf_eval_format.c \
	fpf_checkcase.c \
	fpf_print_prefix.c \
	fpf_putchar.c \
	fpf_putstr.c \
	fpf_putptr.c \
	fpf_putnbr.c \
	fpf_putu_base.c
FT_FPRINTF = ${addprefix ${FT_FPRINTF_DIR}/, ${FT_FPRINTF_SRC}}

SRC = ${LIBFT} \
	${GET_NEXT_LINE} \
	${FT_PRINTF} \
	${FT_FPRINTF}


OBJ_DIR = obj
OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}


HDR_DIR = hdr
HDR = libft.h \
		ft_printf.h \
		get_next_line.h
INCLUDE = ${addprefix ${HDR_DIR}/, ${HDR}}


CC = cc
CFLAGS = -Wall -Wextra -Werror -I${HDR_DIR}



all: ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INCLUDE}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
