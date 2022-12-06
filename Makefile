NAME		=	so_long	
				
INCLUDES	=	includes/so_long.h	

SRCS		=	srcs/main.c 			\
				srcs/key_control.c		\
				srcs/map_create.c		\
				srcs/map_info.c			\
				srcs/check.c

SRCS_M		=	srcs/free.c				\
				srcs/init.c 			\
				srcs/map_check.c 		\
				srcs/render.c

SRCS_B		=	srcs/free_bonus.c 		\
				srcs/init_bonus.c 		\
				srcs/map_check_bonus.c 	\
				srcs/render_bonus.c

DIR_MLX		=	./minilibx

DIR_LIBFT	=	./Libft

LIBFT		=	./Libft/libft.a

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

IFLAGS		=	-I. -I./minilibx -I./Libft

OBJS		=	${SRCS:%.c=%.o}

OBJS_M		=	${SRCS_M:%.c=%.o}

OBJS_B		=	${SRCS_B:%.c=%.o}

.PHONY:  	all clean fclean re bonus

all:		${NAME}

${NAME}: ${OBJS} ${OBJS_M} ${INCLUDES}
	@${MAKE} -C ${DIR_LIBFT} fclean
	@${MAKE} -C ${DIR_LIBFT} all
	@${CC} ${CFLAGS} ${OBJS} ${OBJS_M} ${LIBFT} -L${DIR_MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus: ${OBJS} ${OBJS_B} ${INCLUDES}
	@${MAKE} -C ${DIR_LIBFT} fclean
	@${MAKE} -C ${DIR_LIBFT} all
	@${CC} ${CFLAGS} ${OBJS} ${OBJS_B} ${LIBFT} -L${DIR_MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o:	%.c 
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS} ${OBJS_M} ${OBJS_B}
	@${MAKE} -C ${DIR_LIBFT} clean

fclean:  	clean
	@${RM} ${NAME}
	@${MAKE} -C ${DIR_LIBFT} fclean

re:   		fclean all
