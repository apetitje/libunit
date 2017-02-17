# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION                                                        #
# ---------------------------------------------------------------------------- #

DIRSRC =	.
DIRINC =	incs
DIRLIB =	libs
DIRTST =	test
DIROBJ =	.objs
DIRDEP =	.deps

# ---------------------------------------------------------------------------- #
# EXTERNAL TOOLS SETTINGS                                                      #
# ---------------------------------------------------------------------------- #

CC =		clang
AR =		ar
ARFLAGS =	rc
RM =		rm -f

# ---------------------------------------------------------------------------- #
# TARGET SETUP                                                                 #
# ---------------------------------------------------------------------------- #

NAME =		tests.out

SRCS =		main.c										\
			ft_strtolower/00_strtolower_launcher.c		\
			ft_strtolower/01_strtolower_basic_test.c	\
			ft_strtolower/02_strtolower_medium_test.c	\
			ft_strtolower/03_strtolower_hard_test.c		\
			ft_atoi/00_atoi_launcher.c					\
			ft_atoi/01_atoi_basic_test.c				\
			ft_atoi/02_atoi_hard_test.c					\
			ft_itoa/00_itoa_launcher.c					\
			ft_itoa/01_itoa_basic_test.c				\
			ft_itoa/02_itoa_medium_test.c				\
			ft_itoa/03_itoa_hard_test.c					\
			ft_itoa/04_itoa_neg_test.c					\
			ft_itoa/05_itoa_neg_test_hard.c				\
			ft_isascii/00_isascii_launcher.c			\
			ft_isascii/01_isascii_basic_test.c			\
			ft_isascii/02_isascii_false_test.c			\
			ft_putstr/00_putstr_launcher.c				\
			ft_putstr/01_putstr_basic_test.c			\
			ft_putstr/02_putstr_medium_test.c			\
			ft_putstr/03_putstr_hard_test.c				\
			ft_putstr/04_putstr_empty_test.c

# ---------------------------------------------------------------------------- #
# PROJECT COMPILATION                                                          #
# ---------------------------------------------------------------------------- #

LIBS = 		$(TEST_FRAMEWORK) $(TEST_TARGET)

LDFLAGS = 	$(addprefix -L, 												\
				$(dir $(TEST_FRAMEWORK))									\
				$(dir $(TEST_TARGET))										\
				)

LDLIBS = 	$(addprefix -l,													\
				$(subst lib,,$(basename $(notdir $(TEST_FRAMEWORK))))		\
				$(subst lib,,$(basename $(notdir $(TEST_TARGET))))			\
				)

CPPFLAGS = 	$(addprefix -I,													\
				$(DIRINC)													\
				$(dir $(TEST_FRAMEWORK))/incs								\
				$(dir $(TEST_TARGET))/incs									\
				)

CFLAGS = 	-Wall -Wextra -Werror

SRC =		$(addprefix $(DIRSRC)/, $(SRCS))
OBJ =		$(addprefix $(DIROBJ)/, $(SRCS:.c=.o))

# ---------------------------------------------------------------------------- #
# PUBLIC RULES                                                                 #
# ---------------------------------------------------------------------------- #

all: libs $(NAME)

$(NAME): $(DIROBJ) $(DIRDEP) $(OBJ) $(LIBS)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

libs:
	make -C $(dir $(TEST_FRAMEWORK))
	make -C $(dir $(TEST_TARGET))

fcleanlibs:
	make -C $(dir $(TEST_FRAMEWORK)) fclean
	make -C $(dir $(TEST_TARGET)) fclean

clean:
	$(RM) -r $(DIROBJ)
	$(RM) -r $(DIRDEP)

fclean:	clean
	$(RM) $(NAME)

re: fcleanlibs fclean all

# ---------------------------------------------------------------------------- #
# CUSTOM RULES                                                                 #
# ---------------------------------------------------------------------------- #

test: all $(NAME)
	./$(NAME)

norme:
	/usr/bin/norminette -R CheckTopCommentHeader	\
		$$(find * -name "*.[ch]" ! -path "test/*")

# ---------------------------------------------------------------------------- #
# /!\ PRIVATE RULES /!\                                                        #
# ---------------------------------------------------------------------------- #

$(DIROBJ):
	@mkdir -p $(DIROBJ)

$(DIRDEP):
	@mkdir -p $(DIRDEP)

DEPFLAGS = 		-MT $@ -MMD -MP -MF $(DIRDEP)/$*.Td

COMPILE.c =		$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

POSTCOMPILE =	mv -f $(DIRDEP)/$*.Td $(DIRDEP)/$*.d

$(DIROBJ)/%.o:	$(DIRSRC)/%.c
$(DIROBJ)/%.o:	$(DIRSRC)/%.c $(DIRDEP)/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(word 2,$^))
	$(COMPILE.c) $(OUTPUT_OPTION) $<
	@$(POSTCOMPILE)

$(DIRDEP)/%.d:	;
.PRECIOUS:	$(DIRDEP)/%.d

-include $(patsubst %,$(DIRDEP)/%.d,$(basename $(SRCS)))

# ---------------------------------------------------------------------------- #

.PHONY:	all libs fcleanlibs clean fclean re norme

# ---------------------------------------------------------------------------- #






