NAME = ex00
GCC = g++
GCCFLAGS = -Wall -Wextra -Werror -std=c++17 -I ../include
SRCS = 00.cpp

all : ex00

$(NAME):	$(SRCS)
	$(GCC) $(GCCFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *.o $(NAME)

re: clean all


.PHONY: all clean re
