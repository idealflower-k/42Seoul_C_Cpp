NAME = do-op
CC = gcc
WFLAGS = -Wall -Wextra -Werror
RM = rm
SRCS = do_op.c operator.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${WFLAGS} -o $@ $^ 

%.o : %.c
	${CC} ${WFLAGS} -c $^ -o $@

clean :
	${RM} -f ${OBJS}

fclean : clean
	${RM} -f ${NAME}

re : fclean all
