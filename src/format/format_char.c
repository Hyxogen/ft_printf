#include "format_char.h"
#include "../format_info.h"

int
	print_char(FILE *stream, t_format_info *formatInfo, void *data)
{
	int		ret;
	char	filler;

	ret = 1;
	if (formatInfo->m_Width <= 1 || formatInfo->m_Flags & FLAG_MASK_MINUS)
		fwrite(data, sizeof(char), 1, stream);
	else
	{
		filler = ' ';
		if (formatInfo->m_FillZeroes)
			filler = '0';
		fwrite(&filler, sizeof(char), formatInfo->m_Width - 1, stream);
		fwrite(data, sizeof(char), 1, stream);
		ret += formatInfo->m_Width - 1;
	}
	return (ret);
}