CC = cc
CFLAGS = -Wall -Werror -Wextra -g

NAME = libft.a
SRCS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memset.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_substr.c
SRCS_BONUS = \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstdestroy.c \
	ft_lstprint.c
SRCS_EXTRA = \
	ft_itoa_base.c \
	ft_itoa_uint.c
SRCS_PRINTF = \
	ft_printf.c \
	helpers.c \
	padding_int.c \
	padding_str.c \
	parse.c \
	printf_char.c \
	printf_hex.c \
	printf_int.c \
	printf_percent.c \
	printf_ptr.c \
	printf_str.c \
	printf_uint.c 

OBJS := $(SRCS:%.c=obj/base/%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=obj/base_bonus/%.o)
OBJS_EXTRA := $(SRCS_EXTRA:%.c=obj/extra/%.o)
OBJS_PRINTF := $(SRCS_PRINTF:%.c=obj/ft_printf/%.o)

all: $(NAME) bonus extra printf

$(NAME): $(OBJS)
	ar crs $@ $^

bonus: $(OBJS_BONUS)
	ar crs $(NAME) $^

extra: $(OBJS_EXTRA)
	ar crs $(NAME) $^

printf: $(OBJS_PRINTF)
	ar crs $(NAME) $^

$(OBJS): $(SRCS:%.c=src/base/%.c)
	@mkdir -p obj obj/base
	$(CC) $(CFLAGS) -c $(@:obj/base/%.o=src/base/%.c) -o $@
$(OBJS_BONUS): $(SRCS_BONUS:%.c=src/base_bonus/%.c)
	@mkdir -p obj obj/base_bonus
	$(CC) $(CFLAGS) -c $(@:obj/base_bonus/%.o=src/base_bonus/%.c) -o $@
$(OBJS_EXTRA): $(SRCS_EXTRA:%.c=src/extra/%.c)
	@mkdir -p obj obj/extra
	$(CC) $(CFLAGS) -c $(@:obj/extra/%.o=src/extra/%.c) -o $@
$(OBJS_PRINTF): $(SRCS_PRINTF:%.c=src/ft_printf/%.c)
	@mkdir -p obj obj/ft_printf
	$(CC) $(CFLAGS) -c $(@:obj/ft_printf/%.o=src/ft_printf/%.c) -o $@

fclean: clean
	rm -f $(NAME)
clean:
	rm -rf obj
re: fclean all
.PHONY: all clean fclean re
