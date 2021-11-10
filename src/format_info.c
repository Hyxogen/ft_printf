//
// Created by Daan Meijer on 11/10/21.
//

#include "format_info.h"
#include <stdio.h>
#include "libft.h"
#include "format_info_utils.h"

int
	get_flags(const char *format, t_format_info *formatInfo)
{
	int	ret;

	ret = 0;
	while (*format && ft_strchr(FLAGS, *format))
	{
		formatInfo->m_Flags |= FLAG_MASK_MINUS * (*format == FLAG_MINUS);
		formatInfo->m_Flags |= FLAG_MASK_PLUS * (*format == FLAG_PLUS);
		formatInfo->m_Flags |= FLAG_MASK_ZERO * (*format == FLAG_ZERO);
		formatInfo->m_Flags |= FLAG_MASK_BLANK * (*format == FLAG_BLANK);
		formatInfo->m_Flags |= FLAG_MASK_SHARP * (*format == FLAG_SHARP);
		ret++;
		format++;
	}
	return (ret);
}

int
	get_width(const char *format, t_format_info *formatInfo)
{
	int	ret;

	ret = 0;
	if (*format == '0')
	{
		formatInfo->m_FillZeroes = TRUE;
		format++;
		ret++;
	}
	if (ft_isdigit(*format))
		formatInfo->m_Width = ft_atoi(format);
	else if (*format != '*')
		formatInfo->m_Width = -1;
	else
	{
		formatInfo->m_VariableWidth = TRUE;
		ret++;
		format++;
	}
	while (ft_isdigit(*format))
	{
		format++;
		ret++;
	}
	return (ret);
}

int
	get_preciscion(const char *format, t_format_info *formatInfo)
{
	int	ret;

	if (*format != '.')
		return (0);
	ret = 1;
	format++;
	if (*format == '*'){
		formatInfo->m_VariablePrecision = TRUE;
		return (ret + 1);
	}
	formatInfo->m_Precision = ft_atoi(format);
	while (ft_isdigit(*format))
	{
		format++;
		ret++;
	}
	return (ret);
}

int
	get_size_type(const char *format, t_format_info *formatInfo)
{
	const t_string_flag_pair	*pair;
	int	ret;

	(void)formatInfo;
	ret = 0;
	pair = get_string_flag(format);
	if (!pair)
		formatInfo->m_Size = SIZE_NONE;
	else
	{
		formatInfo->m_Size = pair->m_Flag;
		ret += pair->m_StrLen;
	}
	pair = get_string_flag(format);
	if (!pair)
		return (ret);
	printf("Type is: %s flag:%d\n", pair->m_Str, pair->m_Flag);
	formatInfo->m_Type = pair->m_Flag;
	ret += pair->m_StrLen;
	return (ret);
}

//TODO check if multiple of the same flags are equal it still works
void
	get_format_info(const char *format, t_format_info *formatInfo)
{
	ft_memset(formatInfo, 0, sizeof(t_format_info));
	format += get_flags(format, formatInfo);
	format += get_width(format, formatInfo);
	format += get_preciscion(format, formatInfo);
	get_size_type(format, formatInfo);
}