NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
printf/ft_flags_bonus.c printf/ft_helpersA_bonus.c printf/ft_helpersB_bonus.c printf/ft_printf_bonus.c \
printf/ft_printf_char_bonus.c printf/ft_printf_decimal_bonus.c printf/ft_printf_hexadecimal_bonus.c \
printf/ft_printf_percentage_bonus.c printf/ft_printf_string_bonus.c printf/ft_printf_unsigned_decimal_bonus.c \
printf/ft_printf_void_pointer_bonus.c printf/ft_putnbr_base_bonus.c printf/pf_putchar_bonus.c \
printf/pf_puthexnbr_bonus.c \
gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)