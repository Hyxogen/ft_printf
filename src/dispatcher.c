#include "dispatcher.h"

#include "format/format_char.h"
#include "format/format_specifier.h"
#include "format/format_string.h"

const static t_dispatch_pair g_Pairs[] = {
		{TYPE_CHAR, &print_char},
		{TYPE_SPECIFIER, &print_specifier},
		{TYPE_STRING, &print_string},
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
	dispatch(int fd, t_format_info *formatInfo, va_list current)
{
	const t_dispatch_pair *pair;

	pair = get_pair(get_mask(formatInfo));
	if (!pair)
	{
		printf("Not implemented");
		return (0);
	}
	return (pair->m_Function(fd, formatInfo, current));
}