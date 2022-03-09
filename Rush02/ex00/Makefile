CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_split.c ft_str.c rush02.c ft_putstr.c
OBJS	= ${SRCS:.c=.o}
TARGET	= rush-02

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

.PHONY: all clean fclean
