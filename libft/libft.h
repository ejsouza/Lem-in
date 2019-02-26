/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:50:14 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 11:11:06 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 128
# define BASE 256
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# include <strings.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <locale.h>
# include <wchar.h>

typedef struct					s_gnl
{
	char						**rem;
	char						buff[BUFF_SIZE + 1];
	char						*tmp;
	char						*leaks;
	int							ret;
}								t_gnl;

typedef struct					s_list
{
	void						*content;
	size_t						content_size;
	struct s_list				*next;
}								t_list;

typedef struct					s_bits
{
	char						c4[9];
	char						c3[9];
	char						c2[9];
	char						local2[9];
	char						local3[9];
	char						local4[9];
	int							i;
	int							len;
}								t_bits;

typedef struct					s_ptf
{
	char						buff[BASE];
	char						*arr;
	char						*tab;
	char						*tmp;
	char						type;
	va_list						ap;
	int							at;
	int							x;
	int							j;
	int							len;
	long long					va_int;
	unsigned long long			va_uns_int;
	intmax_t					va_intmax;
	uintmax_t					va_uintmax;
	wchar_t						*wchar;
	char						*va_ptr;
	long long					condition;
	size_t						control;
	int							totalbytes;
	int							ptrlen;
	_Bool						flag;
	short						k;
	short						nb;

}								t_ptf;

typedef struct					s_verify
{
	_Bool						dot;
	_Bool						minus;
	_Bool						plus;
	_Bool						space;
	_Bool						hash;
	_Bool						zero;
	_Bool						width;
	_Bool						percent;
	short						widthnum;
	short						pwidth;
	short						h;
	short						l;
	short						j;
	short						z;
	char						*target;
}								t_verify;

size_t							ft_strlen(const char *s);
size_t							ft_strlcat(char *dst, const char *src,
		size_t size);
size_t							ft_wordlen(char const *s, char c);
void							ft_putchar(char c);
void							ft_putchar_fd(char c, int fd);
void							ft_putnbr(int n);
void							ft_putnbr_fd(int n, int fd);
void							ft_putendl(char const *s);
void							ft_putendl_fd(char const *s, int fd);
void							ft_putstr(char *str);
void							ft_putstr_fd(char const *s, int fd);
void							ft_swap(int *a, int *b);
void							ft_bzero(void *s, size_t n);
void							ft_memdel(void **ap);
void							ft_strdel(char **as);
void							ft_strclr(char *s);
void							ft_striter(char *s, void (*f)(char *));
void							ft_striteri(char *s, void (*f)(unsigned int,
			char *));
void							*ft_memset(void *b, int c, size_t len);
void							*ft_memcpy(void *dst, const void *src,
		size_t n);
void							*ft_memccpy(void *dst, const void *src, int c,
		size_t n);
void							*ft_memmove(void *dst, const void *src,
		size_t len);
void							*ft_memchr(const void *s, int c, size_t n);
void							*ft_memalloc(size_t size);
int								ft_strcmp(const char *s1, const char *s2);
int								ft_strncmp(const char *s1, const char *s2,
		size_t n);
int								ft_tolower(int c);
int								ft_toupper(int c);
int								ft_isprint(int c);
int								ft_isascii(int c);
int								ft_isspace(int c);
int								ft_plus_minus(int c);
int								ft_space_or_tab(int c);
int								ft_isalnum(int c);
int								ft_isdigit(int c);
int								ft_isalpha(int c);
int								ft_wordcount(char *s, char c);
int								ft_memcmp(const void *s1, const void *s2,
		size_t n);
int								ft_atoi(const char *str);
long							ft_atoi_long_int(char *s);
int								ft_strequ(char const *s1, char const *s2);
int								ft_strnequ(char const *s1, char const *s2,
		size_t n);
char							*ft_strstr(const char *haystack, const char
		*needle);
char							*ft_strchr(const char *s, int c);
char							*ft_strrchr(const char *s, int c);
char							*ft_strcat(char *s1, const char *s2);
char							*ft_strncat(char *s1, const char *s2, size_t n);
char							*ft_strdup(const char *s1);
char							*ft_strcpy(char *dst, const char *src);
char							*ft_strncpy(char *dst, const char *src,
		size_t len);
char							*ft_strnstr(const char *haystack,
const char						*needle, size_t len);
char							*ft_strnew(size_t size);
char							*ft_strmap(char const *s, char (*f)(char));
char							*ft_strmapi(char const *s,
		char (*f)(unsigned int, char));
char							*ft_strsub(char const *s,
		unsigned int start, size_t len);
char							*ft_strjoin(char const *s1, char const *s2);
char							*ft_strtrim(char const *s);
char							*ft_itoa(int n);
char							**ft_strsplit(char const *s, char c);
int								get_next_line(const int fd, char **line);
int								ft_intlen(int nb);
int								ft_printf(const char *restrict format, ...);
void							ft_write_to_percent(const char *restrict format,
		t_ptf *p);
int								ft_chose_itoa(t_ptf *p, t_verify **v);
void							ft_wchar_foo(t_ptf *p, int ret);
int								ft_wchar(t_ptf *p, t_verify **v);
int								ft_one_byte(t_ptf *p, intmax_t n);
void							ft_add_spag(t_ptf *p, t_verify **v);
void							ft_parsing_spag(t_ptf *p, t_verify **v);
int								ft_string_spag(t_ptf *p, t_verify **v);
int								ft_wchar_spag(t_ptf *p, t_verify **v);
char							*ft_signed_long_itoa(long long int n);
char							*ft_unsigned_itoa_base(unsigned long long int n,
		char *base);
int								ft_pre_precision_spag(t_ptf *p, t_verify **v);
void							ft_add_sign(t_ptf *p, t_verify **v);
void							ft_width_second(t_ptf *p, t_verify **v);
int								ft_pre_precision(t_ptf *p, t_verify **v);
int								ft_precision_first(t_ptf *p, t_verify **v);
int								ft_left_adjusted(t_ptf *p, t_verify **v);
int								ft_char_itoa(intmax_t n, t_ptf *p,
		t_verify **v);
void							ft_foo(t_ptf *p, t_verify **v, int *x, int *k);
void							ft_padd_zero(t_ptf *p, t_verify **v);
void							ft_right_padd(t_ptf *p, t_verify **v);
int								ft_verify_percent(const char *restrict format,
		t_ptf *p);
int								ft_hexa_prefix(t_ptf *p, t_verify **v);
void							ft_hash(t_ptf *p, t_verify **v);
int								ft_hljz(const char *restrict format, t_ptf *p,
		t_verify **v);
char							ft_def_ch(t_ptf *p, t_verify **v);
void							ft_handler(t_ptf *p, t_verify **v);
int								ft_verify_type(const char *restrict format,
		t_ptf *p);
void							ft_int(t_ptf *p, t_verify **v);
void							ft_hexadecimal(t_ptf *p, t_verify **v);
void							ft_unsigned_int(t_ptf *p, t_verify **v);
void							ft_char(t_ptf *p, t_verify **v);
void							ft_ptr(t_ptf *p, t_verify **v);
char							*ft_intmax_t_itoa(intmax_t n, char *base);
char							*ft_itoa_base(long long n, char *base);
void							ft_no_frmt(const char *restrict format,
		t_ptf *p, t_verify **v);
int								ft_oct(t_ptf *p, t_verify **v);
int								ft_void(t_ptf *p);
void							ft_get_width(const char *restrict format,
		t_ptf *p, t_verify **v);
void							ft_initialize_verify(t_verify **v, t_ptf *p);
void							ft_flags(const char *restrict format, t_ptf *p,
		t_verify **v);
int								ft_parsing(const char *restrict format,
		t_ptf *p);
void							ft_precision_fmt(t_ptf *p, t_verify **v);
int								ft_right_adjusted(t_ptf *p, t_verify **v);
void							ft_select_function(t_ptf *p, t_verify **v);
void							ft_set_unicode_bits(t_ptf *p, t_bits **c,
		short func);
short							ft_unsigned_intlen(uintmax_t n);
short							ft_signed_intlen(intmax_t n);
int								ft_unsigned_itoa(uintmax_t n, char *base,
		t_ptf *p, t_verify **v);
int								ft_signed_itoa(intmax_t n, char *base,
		t_ptf *p);
void							ft_free(t_ptf *p, t_verify **v);
int								ft_malloc_static(t_ptf *p, t_verify **v);
int								ft_string(t_ptf *p, t_verify **v);
int								ft_atoi_bi(const char *str);

#endif
