NAME  = minirt
CC = cc
CFLAGS  = -Wall -Wextra -Werror -I$(INC) -g
LDFLAGS = -Llibft -lft
LGFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd -lz

CFILE = main \
		vector/1_vec \
		window/hook \
		window/win \
		figure/sphere \
		scene/camera \
		scene/scene \
		ray_tracing/ray_tracing \
		ray_tracing/view_port \
		tools/utils \
		parsing/read_file \
		parsing/parse_line

SRCS = $(addprefix src/, $(addsuffix .c, $(CFILE)))
OBJS_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a
INC = inc/
HEADER = minirt.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LGFLAGS) -o $(NAME)

$(LIBFT):
	@make -C ./libft

$(MINILIBX):
	@make -C minilibx-linux

$(OBJS_DIR)%.o: %.c $(INC)$(HEADER)
	mkdir -p $(OBJS_DIR)$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	@make -C libft clean
	@make -C minilibx-linux clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
