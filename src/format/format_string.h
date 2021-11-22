#ifndef FORMAT_STRING_H
#define FORMAT_STRING_H

#include <wchar.h>
#include "../format_info.h"

size_t	print_string(FILE *stream, t_format_info *formatInfo, va_list current);

#endif
