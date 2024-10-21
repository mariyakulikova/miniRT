NAME  = minirt
CC = cc
CFLAGS  = -Wall -Wextra -Werror -g
LDFLAGS = -Llibft -lft
LGFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd -lz

CFILE = main \
		vector/1_vec \
		window/hook \
		window/win \
		figure/sphere \
		scene/camera \
		scene/scene \
		ray_tracing/

SRCS = $(addprefix src/, $(addsuffix .c, $(CFILE)))
OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
HEADER = inc/minirt.h
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LGFLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft

$(MINILIBX):
	@make -C minilibx-linux

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(SRCS_OBJS)
	@make -C libft clean
	@make -C minilibx-linux clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
