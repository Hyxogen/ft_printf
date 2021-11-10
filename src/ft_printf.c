#include "../include/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

/*
 * Altijd size precision etc. doorsturen?
 * Werkt dat voor precision?
 *
 * Eerst converten met type en dan aanpassen met de flags?
 * -Werkt niet even goed voor float (wel mogelijk)
 * -Werkt niet voor niet nul terminated strings
 */

int ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, format);
	ret = ft_vfprintf(stdout, format, arg_list);
	va_end(arg_list);
	return (ret);
}