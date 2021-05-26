SRCS		= ft_scene.c ft_scene_tools.c ft_sprites.c ft_cheks.c ft_parser.c ft_error.c ft_map.c ft_tex_parser.c ft_rescol_parser.c ft_save.c ft_keys.c cube3d.c
FILES		= $(addprefix srcs/, $(SRCS))
U_HEAD		= -I ./include/
OBJS		= $(FILES:.c=.o)
NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a .
			$(MAKE) -C ./mlx/
			cp mlx/libmlx.a .
			$(CC) $(OBJS) -Lmlx -lmlx -L. -lft -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

test:		fclean $(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a .
			$(CC) $(OBJS) -L. -lft -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) $(U_HEAD) -c $< -o $(<:.c=.o)

clean:
			$(MAKE) clean -C ./mlx
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)
			$(RM) libft.a
			$(RM) libmlx.a

re:			fclean all

.PHONY:		all fclean re clean
