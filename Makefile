NAME			= push_swap

#		Couleurs		#

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
TEAL			= \033[0;36m
PURPLE			= \033[0;35m
CYAN            = \033[0;36m
MAGENTA         = \033[0;35m


#		FLags & Commandes CLI		#

CC 				= cc
REMOVE 			= rm -f
STANDARD_FLAGS 	= -g -Wall -Wextra -Werror
GDB_FLAGS		= -g3
VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

#		Directories			#

SRCS_DIR		= ./SRC/
UTILS_DIR		= ./Fonctions/
LIBFT_DIR       = ./Libft/

SRCS 			= $(addprefix $(SRCS_DIR),\
                main.c)
UTILS			= $(addprefix $(UTILS_DIR), \
                lst.c movements.c pa_pb.c ra_rb.c rra_rrb.c \
				sa_sb.c set_nodes.c utils.c chunk_utils.c lst_utils.c \
				mov_utils.c nodes_utils.c positions.c push_swap_utils.c push_swap.c \
				rank.c arg_utils.c main_utils.c)
LIBFT           = $(LIBFT_DIR)libft.a

#		Fonction		#	

all: 		${LIBFT} ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}

${NAME}:        
				${CC} ${SRCS} ${UTILS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
clean:
				${REMOVE} ${NAME} Test
				@echo "$(TEAL)Cleaning object files and temporary files...$(RESET)"

fclean:
				${REMOVE} ${NAME} Test
gdb:
				${CC} ${SRCS} ${UTILS} ${LIBFT} ${STANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				gdb ./${NAME}

test:  
				cc SRC/main.c -LLibft -lft -o test 

gdb_test:		
				${CC} ${TEST} ${UTILS} ${LIBFT} ${STANDARD_FLAGS} ${GDB_FLAGS} ${MINILIBX_FLAGS} -o Test
				gdb ./Test

run:
				${VALGRIND} ./${NAME} 1

re:				fclean all

.PHONY:			all clean fclean re valgrind run