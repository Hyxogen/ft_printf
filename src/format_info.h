#ifndef FORMAT_INFO_H
#define FORMAT_INFO_H
#include "../include/boolean.h"
#include <wchar.h>

# define FLAG_MASK_MINUS 0b000001
# define FLAG_MASK_PLUS 0b000010
# define FLAG_MASK_ZERO 0b000100
# define FLAG_MASK_BLANK 0b001000
# define FLAG_MASK_SHARP 0b010000

# define FLAGS "-+0 #"
# define FLAG_MINUS '-'
# define FLAG_PLUS '+'
# define FLAG_ZERO '0'
# define FLAG_BLANK ' '
# define FLAG_SHARP '#'

# define SIZE_HALFHALF 0b00000000
# define SIZE_HALF 0b00000001
# define SIZE_NONE 0b00000010
# define SIZE_LONG 0b00000100
# define SIZE_LONGLONG 0b00001000
# define SIZE_INTMAX 0b00010000
# define SIZE_SIZET 0b00100000
# define SIZE_PTRDIFF 0b01000000
# define SIZE_LONGDOUBLE 0b10000000

/*TODO een define maken voor low and upper case voor inder defines?*/
# define TYPE_CHAR			0b000000000000000000000000
# define TYPE_STRING		0b000000000000000100000000
# define TYPE_SINT			0b000000000000001000000000
# define TYPE_UOCT			0b000000000000010000000000
# define TYPE_LOHEX			0b000000000000100000000000
# define TYPE_HIHEX			0b000000000001000000000000
# define TYPE_UINT			0b000000000010000000000000
# define TYPE_LOFLOAT		0b000000000100000000000000
# define TYPE_HIFLOAT		0b000000001000000000000000
# define TYPE_LOFLOAT_HEX	0b000000010000000000000000
# define TYPE_HIFLOAT_HEX	0b000000100000000000000000
# define TYPE_LOFLOAT_EX	0b000001000000000000000000
# define TYPE_HIFLOAT_EX	0b000010000000000000000000
# define TYPE_CHAR_COUNT	0b000100000000000000000000
# define TYPE_POINTER		0b001000000000000000000000
# define TYPE_SPECIFIER		0b010000000000000000000000
# define TYPE_INVALID		0b100000000000000000000000

/*%[flags][width][.precision][size]type*/
typedef struct s_format_info {
	unsigned char	m_Flags;
	t_bool			m_FillZeroes;
	t_bool			m_VariableWidth;
	int				m_Width;
	t_bool			m_VariablePrecision;
	int				m_Precision;
	char			m_Size;
	int 			m_Type;
}	t_format_info;

typedef struct s_string_flag_pair {
	const char	*m_Str;
	int			m_Flag;
	size_t 		m_StrLen;
}	t_string_flag_pair;

size_t	get_specifiers_count(const char *format);
int 	get_format_info(const char *format, t_format_info *format_info, va_list *argList);

#endif
