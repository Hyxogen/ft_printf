//
// Created by Daan Meijer on 11/10/21.
//

#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>
#include "format_info.h"

typedef struct s_dispatch_pair {
	int32_t	m_Flags;
	size_t (*m_Function)(FILE*, t_format_info*, void*);
}	t_dispatch_pair;

const t_dispatch_pair *get_pair(int32_t flags);

uint32_t get_flags(t_format_info *formatInfo);

size_t	dispatch(FILE* stream, t_format_info *formatInfo, va_list current);

#endif //DISPATCHER_H