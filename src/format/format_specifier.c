//
// Created by Daan Meijer on 11/11/21.
//

#include "format_specifier.h"
#include "ft_printf.h"

size_t
	print_specifier(FILE *stream, t_format_info *formatInfo, va_list current)
{
	(void)formatInfo;
	(void)current;
	return (fwrite(FORMAT_SPECIFIER_STR, sizeof(char), 1, stream));
}
