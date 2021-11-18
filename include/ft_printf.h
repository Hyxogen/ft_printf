#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

#define FORMAT_SPECIFIER '%'
#define FORMAT_SPECIFIER_STR "%"

int ft_printf(const char *format, ...);
int ft_vprintf();
int ft_fprintf();
int ft_vfprintf();
int ft_sprintf(char *buffer, const char *format, ...);
int ft_vsprintf(char *buffer, const char *format, va_list list);
int ft_snprintf();

#endif
