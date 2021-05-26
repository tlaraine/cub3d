SRCS		= get_next_line.c ft_itoa_ull_base.c ft_itoa_uint_base.c ft_itoa_ull.c ft_putchar.c ft_atoi_ull.c ft_strlenstr.c ft_strlen.c ft_atoi.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS		= ft_lstnew.c ft_lstadd_front.c  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
U_HEAD		= -I ../libft.h
OBJS		= ${SRCS:.c=.o}
OBJS_B		= ${BONUS:.c=.o}

NAME		= libft.a
CC			= gcc
RC			= ar rc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

$(NAME):	$(OBJS)
			@$(RC) $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS) $(OBJS_B)
			@$(RC) $(NAME) $(OBJS) $(OBJS_B)

.c.o:
			@$(CC) $(CFLAGS) $(U_HEAD) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean re clean bonus
