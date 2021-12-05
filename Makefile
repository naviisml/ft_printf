NAME = libftprintf.a

AR = @ar
AR_FLAGS = -rcs

COMPILER = @gcc
COMPILER_FLAGS = -Wall -Werror -Wextra

# Configuration...

# Library...
LIBRARY			=	libft.a
LIBRARY_FOLDER	=	./libft

# Source Files...
SOURCE_FOLDER	=	./srcs
SOURCE_FILES	=	conversions/parse_fill.c \
					conversions/parse_prefix.c \
					conversions/parse_example.c \
					flags/parse_string.c \
					flags/parse_number.c \
					flags/parse_hex.c \
					parser.c \
					ft_print.c \
					ft_printf.c \
					ft_fprintf.c \

# Object Files...
EXTRA_FOLDERS	=	$(SOURCE_FOLDER)
OBJECT_FOLDER	=	./objects
OBJECT_FILES	=	$(addprefix $(OBJECT_FOLDER)/, $(addprefix $(SOURCE_FOLDER)/, $(SOURCE_FILES:.c=.o)))

.PHONY =  $(NAME) $(LIBRARY) all library clean fclean re dev

# Compile the .c files to .o files...
$(OBJECT_FOLDER)/%.o: %.c
	@mkdir -p $(OBJECT_FOLDER) $(addprefix $(OBJECT_FOLDER)/, $(dir $<))
	@echo "Compiling \t$(notdir $<) (100%)"
	@$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

# Compile the program...
$(NAME): $(OBJECT_FILES)
	@echo "Building $(NAME)... (100%)"
	$(AR) $(AR_FLAGS) $(NAME) $(LIBRARY) $(OBJECT_FILES)

# Compile a library...
$(LIBRARY):
	@echo "Compiling \t$(LIBRARY)..."
	@$(MAKE) bonus -C $(LIBRARY_FOLDER)
	@mv $(addprefix $(LIBRARY_FOLDER)/, $(LIBRARY)) $(LIBRARY)

all: $(LIBRARY) $(NAME)

# Remove the `object` folder and files...
clean:
	@$(MAKE) clean -C $(LIBRARY_FOLDER)
	@rm -rf $(OBJECT_FILES) $(OBJECT_FOLDER)

# Remove the `object` and `build` folder and files...
fclean: clean
	@$(MAKE) fclean -C $(LIBRARY_FOLDER)
	@rm -rf $(NAME) $(LIBRARY)

# Clean the program up and re-compile it...
re: fclean all

# Re-compile the program and run the script...
dev: re
	@echo "Running $(NAME)...""
	@$(NAME)