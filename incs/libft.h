/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouvel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:44:46 by anouvel           #+#    #+#             */
/*   Updated: 2017/02/12 19:44:48 by anouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

/*
** Array manipulation
*/
char				**ft_array_dup(char **array);
int					ft_array_indexof(char const **array, char const *str);
size_t				ft_array_pop(char ***argv, size_t start, size_t len);
int					ft_array_push_back(char ***array, char const *value);
int					ft_array_push_front(char ***array, char const *value);
int					ft_array_push_index(char ***array, char const *value,
						size_t const index);

/*
** Integer conversion.
*/

char				*ft_itoa(int n);
char				*ft_lltoa(long long n);

/*
** Mathematics
*/

int					ft_powi(int n, int exp);

/*
** Memory.
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_memdel_tab(void ***ap);
void				*ft_memdup(void const *src, size_t size);

/*
** Put functions.
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putmem_fd(void *content, size_t size, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int nb, int fd);

/*
** String functions.
*/

void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strisalnum(char const *str);
int					ft_strisnumeric(char const *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin3(char const *s1, char const *s2,
						char const *s3);
char				*ft_strjoin3_safe(char const *s1, char const *s2,
						char const *s3);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(const char *s, char c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				*ft_strtolower(char *s);
char				*ft_strser(const char *s);
short				ft_wctomb(char *dest, wchar_t c);
size_t				ft_wstrlen(const wchar_t *str);

/*
** Standard libc recoding.
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
