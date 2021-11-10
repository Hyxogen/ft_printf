#include "../include/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int ft_vfprintf(FILE *stream, const char *format, va_list arg_list)
{

}

int ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, format);
	ret = ft_vfprintf(stdout, format, arg_list);
	va_end(arg_list);
	return (ret);
}