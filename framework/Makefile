# ---------------------------------------------------------------------------- #
# PROJECT CONFIGURATION                                                        #
# ---------------------------------------------------------------------------- #

DIRSRC =	srcs
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

NAME =		libunit.a

SRCS =		launch_tests.c 				\
			launch_test_get_return.c	\
			load_test.c 				\
			fn_assert.c					\
			fn_assert_int.c				\
			fn_assert_eq.c				\
			load_suite.c 				\
			launch_suite.c				\
			display_suite.c				\
			free_tests_func.c			\
			ft_printf/ft_free.c			\
			ft_printf/ft_wide.c			\
			ft_printf/ft_asprintf.c		\
			ft_printf/ft_pad.c			\
			ft_printf/ft_func.c			\
			ft_printf/ft_format.c		\
			ft_printf/ft_modifier.c		\
			ft_printf/ft_output_func.c	\
			ft_printf/ft_flags.c		\
			ft_printf/ft_alpha.c		\
			ft_printf/ft_num.c			\
			ft_printf/ft_printf.c		\
			ft_printf/ft_dprintf.c		\
			ft_wide_strlen.c			\
			ft_itoa_base.c				\
			ft_isalnum.c				\
			ft_isalpha.c				\
			ft_isascii.c				\
			ft_isdigit.c				\
			ft_isprint.c				\
			ft_memalloc.c				\
			ft_memdel.c					\
			ft_putchar.c				\
			ft_putstr.c					\
			ft_strcat.c					\
			ft_strcmp.c					\
			ft_strcpy.c					\
			ft_strdel.c					\
			ft_strdup.c					\
			ft_strlcat.c				\
			ft_strlen.c					\
			ft_strncat.c				\
			ft_strncmp.c				\
			ft_strncpy.c				\
			ft_strnew.c					\
			ft_tolower.c				\
			ft_toupper.c				\
			ft_atoi.c					\
			ft_putnbr.c					\
			ft_putendl.c				\
			ft_itoa_p.c					\
			ft_memset.c					\
			ft_bzero.c					\
			ft_memcpy.c					\
			ft_memccpy.c				\
			ft_memmove.c				\
			ft_memchr.c					\
			ft_memcmp.c					\
			ft_strchr.c					\
			ft_strrchr.c				\
			ft_strstr.c					\
			ft_strnstr.c				\
			ft_strclr.c					\
			ft_striter.c				\
			ft_striteri.c				\
			ft_strmap.c					\
			ft_strmapi.c				\
			ft_strequ.c					\
			ft_strnequ.c				\
			ft_strsub.c					\
			ft_strjoin.c				\
			ft_strtrim.c				\
			ft_strsplit.c				\
			ft_putchar_fd.c				\
			ft_putstr_fd.c				\
			ft_putendl_fd.c				\
			ft_putnbr_fd.c				\
			ft_lstmap.c					\
			ft_lstiter.c				\
			ft_lstadd.c					\
			ft_lstdel.c					\
			ft_lstdelone.c				\
			ft_sqrt.c					\
			ft_realloc.c				\
			ft_strndup.c				\
			ft_dtoa.c					\
			ft_pow.c					\
			ft_strjoinf.c				\
			ft_lstaddback.c				\
			ft_lstjoin.c				\
			ft_sort_wordtab.c			\
			ft_revsort_wordtab.c		\
			ft_list_at.c				\
			ft_list_index.c				\
			ft_lstnew.c					\
			ft_ilen.c					\
			ft_strrcmp.c

# ---------------------------------------------------------------------------- #
# PROJECT COMPILATION                                                          #
# ---------------------------------------------------------------------------- #

LIBS =

LDFLAGS =

LDLIBS =

CPPFLAGS =	$(addprefix -I,							\
            	$(DIRINC)							\
            	)

CFLAGS =	-Wall -Wextra -Werror

SRC =		$(addprefix $(DIRSRC)/, $(SRCS))
OBJ =		$(addprefix $(DIROBJ)/, $(SRCS:.c=.o))

# ---------------------------------------------------------------------------- #
# PUBLIC RULES                                                                 #
# ---------------------------------------------------------------------------- #

all: libs $(NAME)

$(NAME): $(DIROBJ) $(DIRDEP) $(OBJ) $(LIBS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

libs:

fcleanlibs:

clean:
	$(RM) -r $(DIROBJ)
	$(RM) -r $(DIRDEP)

fclean: clean
	$(RM) $(NAME)

re: fcleanlibs fclean all

# ---------------------------------------------------------------------------- #
# CUSTOM RULES                                                                 #
# ---------------------------------------------------------------------------- #

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
