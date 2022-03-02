SRCS	= ft_printf.c ft_putchar_fd.c ft_putnbr_base.c ft_strlen.c 

OBJS	= ${SRCS:.c=.o}

SRCSB	=  ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstiter_bonus.c  ft_lstmap_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c

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

bonus:	${OBJS} ${OBJB}
		@make OBJS="${OBJS} ${OBJB}"

clean:
		${RM} ${OBJS} ${OBJB}

fclean: clean
		${RM} ${NAME}

re: fclean all bonus

.PHONY: all clean fclean re
