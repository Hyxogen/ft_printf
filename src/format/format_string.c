#include <stdarg.h>
#include "../../Dependencies/Libft/libft.h"
#include "formats.h"
#include "../utils/utils.h"

#define NULL_STRING "(null)"

static size_t
	print_string_internal(int fd, t_format_info *fInf, const char *string)
{
	size_t	str_len;
	size_t	ret;

	str_len = ft_strlen(string);
	ret = 0;
	if ((fInf->m_Precision >= 0) && ((size_t) fInf->m_Precision < str_len))
		str_len = fInf->m_Precision;
	while (((fInf->m_Flags & FLAG_MASK_MINUS) != FLAG_MASK_MINUS)
		&& (fInf->m_Width > 0) && ((size_t) fInf->m_Width > str_len))
	{
		ret += put_chr_fd(fd, ' ');
		fInf->m_Width -= 1;
	}
	ret += put_strn_fd(fd, string, fInf->m_Precision);
	while (((fInf->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		&& (fInf->m_Width > 0) && ((size_t) fInf->m_Width > str_len))
	{
		ret += put_chr_fd(fd, ' ');
		fInf->m_Width -= 1;
	}
	return (ret);
}

size_t
	print_string(int fd, t_format_info *fInf, va_list *current)
{
	char	*string;

	string = va_arg(*current, char *);
	if (string == 0)
		return (print_string_internal(fd, fInf, NULL_STRING));
	return (print_string_internal(fd, fInf, string));
}
