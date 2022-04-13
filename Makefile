# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
OBJS_DIR		:= obj
LIBS_DIR		:=

# *********************************** Files ************************************
NAME	:= philo_bonus
MAIN	:= main.c
SRCS	:= $(shell ls $(SRCS_DIR))
OBJS	:= $(SRCS:.c=.o)
HEADERS	:= $(shell ls $(INCLUDES_DIR))

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -pthread
INCLUDES	:= -I $(INCLUDES_DIR)
LIBS		:=

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# *********************************** Colors ***********************************
NC		:= '\033[0m'
GREEN	:= '\033[32m'
RED		:= '\033[0;31m'

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@echo "Compiling" $(GREEN) "main"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) \
$(MAIN) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@$(MKDIR) $(OBJS_DIR)
	@echo "Compiling" $(GREEN) $(basename $(shell basename $<)) $(NC)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@echo "Removing" $(RED) "object files" $(NC)
	@$(RM) $(OBJS_DIR)

fclean:	clean
	@echo "Removing" $(RED) $(NAME) $(NC)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
