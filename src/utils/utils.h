#ifndef UTILS_H
# define UTILS_H

# include <wchar.h>

size_t	put_str_fd(int fd, const char *str);
size_t	put_strn_fd(int fd, const char *str, size_t n);
size_t	put_chr_fd(int fd, int c);
size_t	put_sintn_fd(int fd, long number, size_t n);
size_t	put_sint_fd(int fd, long number);
size_t	put_number_base_unsigned(int fd, unsigned long long number,
			const char *baseStr, int base);
size_t	put_number_base_signed(int fd, long long number,
			const char *baseStr, int base);
//TODO betere naam voor dit (lijkt op lowcase hex)
long	ablsolute_sint(int val);
unsigned long long
		flag_on(unsigned long long v, unsigned long long flag);

#endif
