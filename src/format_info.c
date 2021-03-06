#include "format_info.h"
#include "format_info_utils.h"
#include "ft_printf.h"
#include "utils/utils.h"

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
	get_width(const char *format, t_format_info *formatInfo, va_list *argList)
{
	int	ret;

	ret = 0;
	if (*format == '0')
	{
		format++;
		ret++;
	}
	if (ft_isdigit(*format))
		formatInfo->m_Width = ft_atoi(format);
	else if (*format != '*')
		formatInfo->m_Width = -1;
	else
	{
		formatInfo->m_Width = va_arg(*argList, int);
		return (ret + 1);
	}
	while (ft_isdigit(*format))
	{
		format++;
		ret++;
	}
	return (ret);
}

int
	get_preciscion(const char *format,
		t_format_info *formatInfo, va_list *argList)
{
	int	ret;

	formatInfo->m_Precision = -1;
	if (*format != '.')
		return (0);
	ret = 1;
	format++;
	if (*format == '*')
	{
		formatInfo->m_Precision = va_arg(*argList, int);
		return (ret + 1);
	}
	else if (ft_isdigit(*format))
		formatInfo->m_Precision = ft_atoi(format);
	else if (get_string_flag(format))
		formatInfo->m_Precision = 0;
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
	int							ret;

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
	formatInfo->m_Type = pair->m_Flag;
	ret += pair->m_StrLen;
	return (ret);
}

int
	get_format_info(const char *format,
		t_format_info *formatInfo, va_list *argList)
{
	int	ret;

	ret = 0;
	ft_memset(formatInfo, 0, sizeof(t_format_info));
	ret += get_flags(format, formatInfo);
	ret += get_width(format + ret, formatInfo, argList);
	ret += get_preciscion(format + ret, formatInfo, argList);
	ret += get_size_type(format + ret, formatInfo);
	if (formatInfo->m_Precision != -1)
		formatInfo->m_Flags &= ~FLAG_MASK_ZERO;
	return (ret);
}
