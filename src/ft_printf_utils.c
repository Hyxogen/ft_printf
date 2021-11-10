#include "../include/ft_printf.h"
#include "ft_printf_utils.h"
#include <wchar.h>

size_t
	get_specifiers_count(const char *format)
{
	size_t	count;

	count = 0;
	while (format)
	{
		if (*format != FORMAT_SPECIFIER)
			;
		else if ((*format == FORMAT_SPECIFIER)
					&& (*(format + 1) == FORMAT_SPECIFIER))
			format++;
		else
			count++;
		format++;
	}
	return (count);
}