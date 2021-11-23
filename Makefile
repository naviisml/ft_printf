NAME = program

AR = @ar
AR_FLAGS = -rcs

COMPILER = @gcc
COMPILER_FLAGS = -Wall -Werror -Wextra

# Configuration...
BUILD_FOLDER	=	./build
#BUILD_FILES		=	libft.a

# Library...
LIBRARY			=	libft
LIBRARY_PUTPUT	=	libft.a

# Source Files...
SOURCE_FOLDER	=	./srcs
SOURCE_FILES	=	ft_example.c

# Object Files...
EXTRA_FOLDERS	=	$(SOURCE_FOLDER)
OBJECT_FOLDER	=	./objects
OBJECT_FILES	=	$(addprefix $(OBJECT_FOLDER)/, $(addprefix $(SOURCE_FOLDER)/, $(SOURCE_FILES:.c=.o)))

.PHONY =  $(NAME) all library clean fclean re dev

# Compile the .c files to .o files...
$(OBJECT_FOLDER)/%.o: %.c
	@mkdir -p $(OBJECT_FOLDER) $(addprefix $(OBJECT_FOLDER)/, $(dir $<))
	@echo "Compiling \t$(notdir $<) (100%)"
	@$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

# Compile the program...
$(NAME): $(OBJECT_FILES)
	@echo "Building $(NAME)... (100%)"
	$(COMPILER) $(COMPILER_FLAGS) $(OBJECT_FILES) $(addprefix $(BUILD_FOLDER)/, $(BUILD_FILES)) -o $(NAME)

# Compile a library...
library:
	@echo "Compiling $(LIBRARY)..."
	@$(MAKE) bonus -C $(LIBRARY)
	@mkdir -p $(BUILD_FOLDER)
	@mv $(addprefix $(LIBRARY)/, $(LIBRARY_PUTPUT)) $(addprefix $(BUILD_FOLDER)/, $(LIBRARY_PUTPUT))

all: $(NAME)

# Remove the `object` folder and files...
clean:
	@rm -rf $(OBJECT_FILES) $(OBJECT_FOLDER)

# Remove the `object` and `build` folder and files...
fclean: clean
	@rm -rf $(NAME) $(BUILD_FOLDER)

# Clean the program up and re-compile it...
re: fclean all

# Re-compile the program and run the script...
dev: re
	@echo "Running $(NAME)...""
	@$(NAME)