#include "../include/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "format_info.h"
#include "debug_utils.h"
#include "dispatcher.h"

/*
 * Altijd size precision etc. doorsturen?
 * Werkt dat voor precision?
 *
 * Eerst converten met type en dan aanpassen met de flags?
 * -Werkt niet even goed voor float (wel mogelijk)
 * -Werkt niet voor niet nul terminated strings
 */

/**
 * This functions trusts that the string is at least size of n
 * @param stream
 * @param string
 * @return
 */
int
	write_strn(FILE *stream, const char *string, size_t n)
{
	return (fwrite(string, sizeof(char), n, stream));
}

int
	ft_vfprintf(FILE *stream, const char *format, va_list args)
{
	char			*specifier;
	const char 		*searchStart;
	size_t			formatLen;
	t_format_info	formatInfo;
	int 			ret;
	int 			tmp;

	formatLen = ft_strlen(format);
	searchStart = format;
	ret = 0;
	while (1)
	{
		specifier = ft_memchr(searchStart, FORMAT_SPECIFIER, formatLen);
		if (!specifier)
			break ;
		if (*(specifier + 1) == FORMAT_SPECIFIER)
		{
			searchStart = specifier + 2;
			continue ;
		}
		tmp = write_strn(stream, format, specifier - format);
		format += tmp;
		formatLen -= tmp;
		ret += tmp;
		tmp = get_format_info(specifier + 1, &formatInfo, args);
		format += tmp;
		formatLen -= tmp;
		tmp  = dispatch(stream, &formatInfo, args);
		ret += tmp;
//		print_format_info(&formatInfo);
		break;
	}
	ret += write_strn(stream, format, formatLen);
	return (ret);
}


int
	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, format);
	ret = ft_vfprintf(stdout, format, arg_list);
	va_end(arg_list);
	return (ret);
}