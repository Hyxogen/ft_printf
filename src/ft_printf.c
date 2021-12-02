#include "../include/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "format_info.h"
#include "dispatcher.h"
#include "utils/utils.h"

int
	ft_vprintf(int fd, const char *format, va_list *args)
{
	char			*specifier;
	size_t			formatLen;
	t_format_info	formatInfo;
	int				ret;
	int				tmp;

	formatLen = ft_strlen(format);
	ret = 0;
	while (1)
	{
		specifier = ft_memchr(format, FORMAT_SPECIFIER, formatLen);
		if (!specifier)
			break ;
		tmp = put_strn_fd(fd, format, specifier - format);
		format += tmp;
		formatLen -= tmp;
		ret += tmp;
		tmp = get_format_info(specifier + 1, &formatInfo, args);
		format += tmp;
		formatLen -= tmp;
		tmp = dispatch(fd, &formatInfo, args);
		ret += tmp;
	}
	ret += put_strn_fd(fd, format, formatLen);
	return (ret);
}

int
	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, format);
	ret = ft_vprintf(1, format, &arg_list);
	va_end(arg_list);
	return (ret);
}
