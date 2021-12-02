#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define FORMAT_SPECIFIER '%'
# define FORMAT_SPECIFIER_STR "%"

int	ft_printf(const char *format, ...);
#endif
