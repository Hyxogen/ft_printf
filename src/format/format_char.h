//
// Created by Daan Meijer on 11/10/21.
//

#ifndef FORMAT_CHAR_H
#define FORMAT_CHAR_H

#include <wchar.h>
#include "../format_info.h"

size_t	print_char(FILE *stream, t_format_info *formatInfo, va_list current);

#endif //FORMAT_CHAR_H
