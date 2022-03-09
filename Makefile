SRCS	= ft_printf.c ft_putchar_fd.c ft_putnbr_base.c ft_putnbr_base_ptr.c ft_putnbr_fd.c ft_putnbr_basedec.c ft_strlen.c ft_putstr_fd.c

OBJS	= ${SRCS:.c=.o}

OBJB	= ${SRCSB:.c=.o}
NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror 
AR		= ar rc

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${OBJB}

fclean: clean
		${RM} ${NAME}

re: fclean all bonus

.PHONY: all clean fclean re
