NAME  = miniRT
CC = cc
CFLAGS  = -Wall -Wextra -Werror -I$(INC) -g
LDFLAGS = -Llibft -lft
LGFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd -lz

CFILE = color/1_color \
		color/2_color \
		figure/cylinder \
		figure/figure_1 \
		figure/figure_2 \
		figure/figure_3 \
		figure/plane \
		figure/sphere \
		parsing/parsing \
		parsing/parsing1 \
		ray_tracing/ray_tracing \
		ray_tracing/view_port \
		scene/a_light \
		scene/camera \
		scene/light \
		scene/scene \
		tools/1_utils \
		tools/2_utils \
		tools/3_utils \
		vector/1_vec \
		vector/2_vec \
		window/draw \
		window/hook \
		window/hook1 \
		window/hook2 \
		window/hook3 \
		window/win \
		figure/cylinder1 \
		main
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
