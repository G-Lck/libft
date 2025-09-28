# Lib
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
LIB_SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c


LIB_OBJS = $(LIB_SRCS:.c=.o)

# Tests
TEST_SRCS = main.c tests.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_EXEC = tests

# Compilation de la lib statique
$(NAME): $(LIB_OBJS)
	ar rcs $(NAME) $(LIB_OBJS)

# Compilation des objets
%.o: %.c
	cc $(FLAGS) -c $< -o $@

# Compilation de l'exécutable de test
$(TEST_EXEC): $(NAME) $(TEST_OBJS)
	cc $(FLAGS) $(TEST_OBJS) -L. -lft -o $(TEST_EXEC)

# Compilation de la lib partagée
so: $(LIB_OBJS)
	cc -fPIC -shared -o libft.so $(LIB_OBJS)

# Règles standards
all: $(NAME) $(TEST_EXEC)

clean:
	rm -f $(LIB_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_EXEC) libft.so

re: fclean all

