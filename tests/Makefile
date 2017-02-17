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
			func_to_test.c								\
			func_to_test/00_func_to_test_launcher.c		\
			func_to_test/01_ok_test.c					\
			func_to_test/02_ko_test.c					\
			func_to_test/03_segv_test.c					\
			func_to_test/04_buse_test.c					\
			func_to_test/05_timeout_test.c

# ---------------------------------------------------------------------------- #
# PROJECT COMPILATION                                                          #
# ---------------------------------------------------------------------------- #

LIBS = 		$(TEST_FRAMEWORK)

LDFLAGS = 	$(addprefix -L, 												\
				$(dir $(TEST_FRAMEWORK))									\
				)

LDLIBS = 	$(addprefix -l,													\
				$(subst lib,,$(basename $(notdir $(TEST_FRAMEWORK))))		\
				)

CPPFLAGS = 	$(addprefix -I,													\
				$(DIRINC)													\
				$(dir $(TEST_FRAMEWORK))/incs								\
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

fcleanlibs:
	make -C $(dir $(TEST_FRAMEWORK)) fclean

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
