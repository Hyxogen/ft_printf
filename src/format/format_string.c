#include <stdarg.h>
#include "../../Dependencies/Libft/libft.h"
#include "formats.h"
#include "../utils/utils.h"

#define NULL_STRING "(null)"
#define NULL_STRING_LEN 6

static size_t
	print_null_string(int fd, t_format_info *fInf) {
	size_t	ret;

	ret = 0;
	while (fInf->m_Width > NULL_STRING_LEN)
	{
		ret += put_chr_fd(fd, ' ');
		fInf->m_Width -= 1;
	}
	ret += put_strn_fd(fd, NULL_STRING, fInf->m_Precision);
	return (ret);
}

size_t
	print_string(int fd, t_format_info *fInf, va_list *current)
{
	char	*string;
	size_t	str_len;
	size_t	ret;

	string = va_arg(*current, char *);
	if (string == 0)
		return (print_null_string(fd, fInf));
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
