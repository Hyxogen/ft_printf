//
// Created by Daan Meijer on 11/10/21.
//

#include "dispatcher.h"

#include "format/format_char.h"

const static t_dispatch_pair g_Pairs[] = {
		{TYPE_CHAR, &print_char},
		{0, 0}
};

const t_dispatch_pair
	*get_pair(int32_t flags)
{
	size_t			index;

	index = 0;
	while (g_Pairs[index].m_Function)
	{
		if ((g_Pairs[index].m_Flags & flags) == flags)
			return &g_Pairs[index];
		index++;
	}
	return (NULL);
}

uint32_t
	get_mask(t_format_info *formatInfo)
{
	return (formatInfo->m_Type | ((uint32_t) formatInfo->m_Size));
}

size_t
	dispatch(FILE *stream, t_format_info *formatInfo, va_list current)
{
	const t_dispatch_pair *pair;

	pair = get_pair(get_mask(formatInfo));
	if (!pair)
	{
		printf("Not implemented!\n");
		return (0);
	}
	return (pair->m_Function(stream, formatInfo, current));
}