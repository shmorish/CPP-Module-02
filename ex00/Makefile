NAME = Canonical_Form
SRCS = $(wildcard srcs/*.cpp)
OBJS = $(patsubst srcs/%.cpp, objs/%.o, $(SRCS))
RM = rm -f
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MP -MMD
INC = -I./includes/
HEADERS = $(wildcard includes/*.hpp)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

objs/%.o: srcs/%.cpp
	mkdir -p objs
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

clean :
	$(RM) $(OBJS)
	rm -rf objs

fclean : clean
	$(RM) $(NAME)

re : fclean all

format :
	clang-format -i $(SRCS) $(HEADERS)

.PHONY : all clean fclean re