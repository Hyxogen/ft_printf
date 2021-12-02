#ifndef UTILS_H
# define UTILS_H

# include <wchar.h>

# define BTEN "0123456789"
# define BLHEX "0123456789abcdef"
# define BUHEX "0123456789ABCDEF"

size_t	put_str_fd(int fd, const char *str);
size_t	put_strn_fd(int fd, const char *str, size_t n);
size_t	put_chr_fd(int fd, int c);
size_t	put_sintn_fd(int fd, long number, size_t n);
size_t	put_sint_fd(int fd, long number);
size_t	put_number_base_unsigned(int fd, unsigned long long number,
			const char *baseStr, int base);
size_t	put_number_base_signed(int fd, long long number,
			const char *baseStr, int base);
long	ablsolute_sint(int val);
size_t	print_padding(int fd, int ch, int times);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *dest, int ch, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(int c);
#endif
