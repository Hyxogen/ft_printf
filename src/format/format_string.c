#include <stdarg.h>
#include "../../Dependencies/Libft/libft.h"
#include "format_string.h"
#include "../utils/utils.h"

size_t	print_string(int fd, t_format_info *formatInfo, va_list current)
{
	const char	*string;

	(void)formatInfo;
	string = va_arg(current, const char *);
	return (put_str_fd(fd, string));
}