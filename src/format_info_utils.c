//
// Created by Daan Meijer on 11/10/21.
//

#include "format_info_utils.h"
#include "libft.h"

const t_string_flag_pair
	*get_string_flag(const char *str)
{
	const t_string_flag_pair *pair;
	int index;

	index = 0;
	while (g_StringFlags[index].m_Str)
	{
		pair = &g_StringFlags[index];
		if (!ft_strncmp(str, pair->m_Str, pair->m_StrLen))
			return pair;
		index++;
	}
	return (0);
}
