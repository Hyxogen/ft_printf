#include <stdarg.h>
#include "../../Dependencies/Libft/libft.h"
#include "format_string.h"

size_t	print_string(FILE *stream, t_format_info *formatInfo, va_list current)
{
	const char	*string;
	size_t		str_len;

	(void)formatInfo;
	string = va_arg(current, const char *);
	str_len = ft_strlen(string);
	fwrite(string, sizeof(char), str_len, stream);
	return (str_len);
}