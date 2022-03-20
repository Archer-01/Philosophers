# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
OBJS_DIR		:= obj
LIBS_DIR		:=

# *********************************** Files ************************************
NAME	:= philo
MAIN	:= main.c
SRCS	:= $(shell ls $(SRCS_DIR))
OBJS	:= $(SRCS:.c=.o)
HEADERS	:= $(shell ls $(INCLUDES_DIR))

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -pthread -g
INCLUDES	:= -I $(INCLUDES_DIR)
LIBS		:=

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) \
$(MAIN) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
