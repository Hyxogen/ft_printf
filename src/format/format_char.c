#include "format_char.h"
#include "../utils/utils.h"

size_t
	print_char(int fd, t_format_info *formatInfo, va_list current)
{
	int	chr;

	(void)formatInfo;
	chr = va_arg(current, int);
	return (put_chr_fd(fd, chr));
}