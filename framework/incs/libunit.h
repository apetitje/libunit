/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:05:28 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 21:05:29 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include "ft_printf.h"

# define TIMEOUT    2

# define ASSERT_TRUE(x) if((assert_true(x,__FILE__,__LINE__))){return(-1);};
# define ASSERT_FALSE(x) if((assert_false(x,__FILE__,__LINE__))){return(-1);};

# define ASSERT_EQ(x,y) if((assert_eq(x,y,__FILE__,__LINE__))){return(-1);};
# define ASSERT_NE(x,y) if((assert_ne(x,__FILE__,__LINE__))){return(-1);};

# define ASSERT_LT(x,y) if((assert_lt(x,y,__FILE__,__LINE__))){return(-1);};
# define ASSERT_LE(x,y) if((assert_le(x,y,__FILE__,__LINE__))){return(-1);};
# define ASSERT_GT(x,y) if((assert_gt(x,y,__FILE__,__LINE__))){return(-1);};
# define ASSERT_GE(x,y) if((assert_ge(x,y,__FILE__,__LINE__))){return(-1);};

# define ASSERT_STR_EQ(x,y) if((astreq(x,y,__FILE__,__LINE__))){return (-1);};
# define ASSERT_STR_NE(x,y) if((astrne(x,y,__FILE__,__LINE__))){return (-1);};

# define ASSERT_STR_STDOUT(x,y) if((aout(x,y,__FILE__,__LINE__))){return(-1);};

typedef enum			e_status
{
	ST_OK = 0,
	ST_FAIL,
	ST_ERROR,
	ST_ALL
}						t_status;

typedef enum			e_mode
{
	RUN,
	ALLOW_TO_FAIL,
	PENDING
}						t_mode;

typedef int				t_signal;

typedef struct			s_unit_test
{
	int					term;
	int					ret;
	t_mode				mode;
	double				time_spent;
	t_status			status;
	t_signal			signal;
	char				*name;
	char				*suite;
	int					(*func)(void);
	struct s_unit_test	*next;
}						t_unit_test;

typedef struct			s_suite_test
{
	char				*name;
	t_unit_test			*test;
	t_mode				mode;
	t_status			status;
	double				time_spent;
	struct s_suite_test	*next;
}						t_suite_test;

typedef struct			s_suite_test_launcher
{
	size_t				nb_suite;
	size_t				nb_tests;
	size_t				nb_run_tests;
	size_t				nb_allow_to_fail_tests;
	size_t				nb_pending_tests;
	size_t				nb_test_st_ok;
	size_t				nb_test_st_fail;

	double				time_spent;

}						t_suite_test_launcher;

void					s_display_test_before(t_suite_test_launcher *launcher);
void					s_display_test_after(t_suite_test_launcher *launcher);
void					free_test_suite(t_suite_test **list);
void					load_suite(t_suite_test **suite, char *name,
		t_unit_test *test, t_mode mode);

int						launch_suite(t_suite_test **suite);
void					load_test(t_unit_test **test_list, char *name,
		int (*f)(void), t_mode mode);

int						launch_tests(t_suite_test_launcher *launcher,
		t_unit_test **test_list);

t_status				s_unit_test_get_return_signal(
		t_suite_test_launcher *launcher, t_unit_test *test);

t_status				s_unit_test_get_return_value(
		t_suite_test_launcher *launcher, t_unit_test *test);

int						assert_true(int boolean, char *s, int l);
int						assert_false(int boolean, char *s, int l);

int						assert_eq(int x, int y, char *s, int l);
int						assert_ne(int x, int y, char *s, int l);

int						assert_lt(int x, int y, char *s, int l);
int						assert_le(int x, int y, char *s, int l);
int						assert_gt(int x, int y, char *s, int l);
int						assert_ge(int x, int y, char *s, int l);

int						astreq(const char *x, const char *y,
		char *s, int l);

int						astrne(const char *x, const char *y,
		char *s, int l);

int						aout(void (*f)(const char *),
		char *cmp, char *s, int l);

#endif
