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

NAME =		libft.a

# ---------------------------------------------------------------------------- #

SRCS =		ft_get_/get_next_line.c				\
			ft_arr_/ft_array_dup.c				\
			ft_arr_/ft_array_indexof.c			\
			ft_arr_/ft_array_pop.c				\
			ft_arr_/ft_array_push_back.c		\
			ft_arr_/ft_array_push_front.c		\
			ft_arr_/ft_array_push_index.c		\
			ft_ito_/ft_itoa.c					\
			ft_ito_/ft_lltoa.c					\
			ft_math_/ft_powi.c					\
			ft_mem_/ft_memalloc.c				\
			ft_mem_/ft_memdel.c					\
			ft_mem_/ft_memdel_tab.c				\
			ft_mem_/ft_memdup.c					\
			ft_put_/ft_putchar.c				\
			ft_put_/ft_putchar_fd.c				\
			ft_put_/ft_putstr.c					\
			ft_put_/ft_putstr_fd.c				\
			ft_put_/ft_putmem_fd.c				\
			ft_put_/ft_putnbr.c					\
			ft_put_/ft_putnbr_fd.c				\
			ft_put_/ft_putendl.c				\
			ft_put_/ft_putendl_fd.c				\
			ft_str_/ft_strnew.c					\
			ft_str_/ft_strdel.c					\
			ft_str_/ft_strclr.c					\
			ft_str_/ft_strisnumeric.c			\
			ft_str_/ft_strisalnum.c				\
			ft_str_/ft_striter.c				\
			ft_str_/ft_striteri.c				\
			ft_str_/ft_strmap.c					\
			ft_str_/ft_strmapi.c				\
			ft_str_/ft_strequ.c					\
			ft_str_/ft_strnequ.c				\
			ft_str_/ft_strsub.c					\
			ft_str_/ft_strjoin.c				\
			ft_str_/ft_strjoin3.c				\
			ft_str_/ft_strjoin3_safe.c			\
			ft_str_/ft_strser.c					\
			ft_str_/ft_strtrim.c				\
			ft_str_/ft_strsplit.c				\
			ft_str_/ft_strtolower.c				\
			ft_str_/ft_wctomb.c					\
			ft_str_/ft_wstrlen.c				\
			recodes/ft_memset.c					\
			recodes/ft_bzero.c					\
			recodes/ft_memcpy.c					\
			recodes/ft_memccpy.c				\
			recodes/ft_memmove.c				\
			recodes/ft_memchr.c					\
			recodes/ft_memcmp.c					\
			recodes/ft_strlen.c					\
			recodes/ft_strdup.c					\
			recodes/ft_strcpy.c					\
			recodes/ft_strncpy.c				\
			recodes/ft_strcat.c					\
			recodes/ft_strncat.c				\
			recodes/ft_strlcat.c				\
			recodes/ft_strchr.c					\
			recodes/ft_strrchr.c				\
			recodes/ft_strstr.c					\
			recodes/ft_strnstr.c				\
			recodes/ft_strcmp.c					\
			recodes/ft_strncmp.c				\
			recodes/ft_atoi.c					\
			recodes/ft_atoll.c					\
			recodes/ft_isalpha.c				\
			recodes/ft_isdigit.c				\
			recodes/ft_isalnum.c				\
			recodes/ft_isascii.c				\
			recodes/ft_isprint.c				\
			recodes/ft_isspace.c				\
			recodes/ft_toupper.c				\
			recodes/ft_tolower.c				\
			ft_lst_/t_list/t_list_add.c			\
			ft_lst_/t_list/t_list_del.c			\
			ft_lst_/t_list/t_list_splice.c		\
			ft_lst_/list_push_front.c			\
			ft_lst_/list_push_back.c			\
			ft_lst_/list_del.c					\
			ft_lst_/list_is_empty.c				\
			ft_lst_/list_insert.c				\
			ft_lst_/list_size.c					\
			ft_lst_/list_move.c					\
			ft_lst_/list_nth.c					\
			ft_lst_/list_nth_safe.c				\
			ft_lst_/list_slice.c				\
			ft_lst_/list_splice.c

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

tests:
	@make -C tests test								\
		TEST_FRAMEWORK=$$(pwd)/framework/libunit.a

tests-clean:
	make -C tests fclean							\
		TEST_FRAMEWORK=$$(pwd)/framework/libunit.a

real-tests:
	@make -C real-tests test						\
		TEST_FRAMEWORK=$$(pwd)/framework/libunit.a	\
        TEST_TARGET=$$(pwd)/libft.a

real-tests-clean:
	make -C real-tests fclean						\
		TEST_FRAMEWORK=$$(pwd)/framework/libunit.a	\
		TEST_TARGET=$$(pwd)/libft.a

norme:
	/usr/bin/norminette -R CheckFilename	\
		$$(find * -name "*.[ch]")

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

.PHONY: all libs fcleanlibs clean fclean re norme tests real-tests

# ---------------------------------------------------------------------------- #
