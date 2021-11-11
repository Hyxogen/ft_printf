//
// Created by Daan Meijer on 11/11/21.
//

#ifndef FORMAT_SPECIFIER_H
#define FORMAT_SPECIFIER_H

#include <wchar.h>
#include "../format_info.h"

size_t	print_specifier(FILE *stream, t_format_info *formatInfo, va_list current);

#endif //FORMAT_SPECIFIER_H
