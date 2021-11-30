#ifndef UTILS_H
#define UTILS_H

#include <wchar.h>

size_t	put_str_fd(int fd, const char *str);
size_t	put_strn_fd(int fd, const char *str, size_t n);
size_t	put_chr_fd(int fd, int c);
size_t	put_sintn_fd(int fd, long number, size_t n);

#endif
