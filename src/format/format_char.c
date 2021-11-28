#include "formats.h"
#include "../utils/utils.h"

size_t
	print_char(int fd, t_format_info *formatInfo, va_list *current)
{
	int	chr;
	int ret;
	int	width;

	width = formatInfo->m_Width;
	ret = 0;
	while ((width > 1) && ((formatInfo->m_Flags & FLAG_MASK_MINUS) != FLAG_MASK_MINUS))
	{
		ret += put_chr_fd(fd, ' ');
		width--;
	}
	chr = va_arg(*current, int);
	ret += put_chr_fd(fd, chr);
	while ((width > 1) && ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS))
	{
		ret += put_chr_fd(fd, ' ');
		width--;
	}
	return (ret);
}