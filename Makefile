GCC      = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -O2 -I include

SRCS = $(wildcard ex_*/[0-9][0-9].cpp)
BINS = $(SRCS:.cpp=)

all: $(BINS)

%: %.cpp include/Vector.hpp include/Matrix.hpp
	$(GCC) $(CFLAGS) $< -o $@

run: all
	./ex_$(N)/$(N)

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all run clean re
