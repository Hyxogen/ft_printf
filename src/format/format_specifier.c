#include "format_specifier.h"
#include "ft_printf.h"
#include "../utils/utils.h"

size_t
	print_specifier(int fd, t_format_info *formatInfo, va_list current)
{
	(void)formatInfo;
	(void)current;
	return (put_chr_fd(fd, FORMAT_SPECIFIER));
}
