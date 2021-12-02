#include "dispatcher.h"

#include "format/formats.h"

const static t_dispatch_pair	g_Pairs[] = {
		{TYPE_CHAR, &print_char},
		{TYPE_SPECIFIER, &print_specifier},
		{TYPE_STRING, &print_string},
		{TYPE_SINT, &print_sint},
		{TYPE_UINT, &print_uint},
		{TYPE_LOHEX, &print_lhex},
		{TYPE_HIHEX, &print_uhex},
		{TYPE_POINTER, &print_pointer},
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
			return (&g_Pairs[index]);
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
	dispatch(int fd, t_format_info *formatInfo, va_list *current)
{
	const t_dispatch_pair	*pair;

	pair = get_pair(get_mask(formatInfo));
	if (!pair)
		return (0);
	return (pair->m_Function(fd, formatInfo, current));
}
