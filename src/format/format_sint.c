#include "formats.h"
#include "../utils/utils.h"


static int get_number_str_length(long number)
{
	if (number < 0)
		return (get_number_str_length((-1 * number) / 10) + 2);
	if (number / 10)
		return (get_number_str_length(number / 10) + 1);
	return (1);
}

static size_t print_padding(int zero, int width)
{
	size_t	ret;
	char	filler;

	ret = 0;
	filler = ' ';
	if (zero)
		filler = '0';
	while (width)
	{
		ret += put_chr_fd(1, filler);
		width--;
	}
	return (ret);
}

size_t	print_sint(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t	ret;
	long	number;
	int		num_len;

	number = va_arg(*current, int);
	num_len = get_number_str_length(number);
	ret = 0;
	if (formatInfo->m_Precision > 0) {
		if (number < 0)
		{
			ret += put_chr_fd(1, '-');
			number *= - 1;
			num_len -= 1;
		}
		if (formatInfo->m_Precision > num_len)
			formatInfo->m_Precision -= num_len;
		ret += print_padding(1, formatInfo->m_Precision);
	}
	// if ((formatInfo->m_Flags & FLAG_MASK_MINUS) != FLAG_MASK_MINUS)
	// 	print_padding((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS, formatInfo->m_Width, num_len);
	ret += put_sintn_fd(fd, number, 20);
	return (ret);
}