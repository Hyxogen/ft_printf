#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define FORMAT_SPECIFIER '%'
#define FORMAT_SPECIFIER_STR "%"

int ft_printf(const char *format, ...);
int ft_vprintf();
int ft_fprintf();
int ft_vfprintf();
int ft_sprintf();
int ft_snprintf();

#endif //FT_PRINTF_H
