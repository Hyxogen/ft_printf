#ifndef FORMATS_H
#define FORMATS_H

#include <wchar.h>
#include "../format_info.h"

size_t	print_string(int fd, t_format_info *formatInfo, va_list *current);
size_t	print_specifier(int fd, t_format_info *formatInfo, va_list *current);
size_t	print_sint(int fd, t_format_info *formatInfo, va_list *current);
size_t	print_char(int fd, t_format_info *formatInfo, va_list *current);
size_t	print_uhex(int fd, t_format_info *formatInfo, va_list *current);
size_t	print_lhex(int fd, t_format_info *formatInfo, va_list *current);
#endif
