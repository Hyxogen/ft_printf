#include "formats.h"
#include "../utils/utils.h"


static int get_number_str_length(long number)
{
	int	num_len;

	num_len = 1;
	if (number < 0)
		num_len = 2;
	while (number / 10)
	{
		num_len++;
		number /= 10;
	}
	return (num_len);
}

static int get_preciscion_str_length(const t_format_info *formatInfo, long number) {
	int	num_len;

	num_len = get_number_str_length(number);
	if (number < 0)
		num_len--;
	if (formatInfo->m_Precision > num_len)
		return (formatInfo->m_Precision - num_len);
	return (0);
}

static int get_width_str_length(const t_format_info *formatInfo, int precLen, long number) {
	int	total_len;

	total_len = get_number_str_length(number) + precLen;
	if ((formatInfo->m_Precision == 0) && !(number))
		total_len--;
	if ((number >= 0) && (formatInfo->m_Flags & (FLAG_MASK_BLANK | FLAG_MASK_PLUS)))
		total_len++;
	if (formatInfo->m_Width > total_len)
		return (formatInfo->m_Width - total_len);
	return (0);
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

size_t
	print_sint(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t	ret;
	long	number;
	int		num_len;
	int		prec_len;
	int		width_len;

	number = va_arg(*current, int);
	num_len = get_number_str_length(number);
	prec_len = get_preciscion_str_length(formatInfo, number);
	width_len = get_width_str_length(formatInfo, prec_len, number);
	ret = 0;
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && !(formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding(0, width_len);
	if (number < 0)
		ret += put_chr_fd(1, '-');
	else if (formatInfo->m_Flags & (FLAG_MASK_PLUS | FLAG_MASK_BLANK))
		ret += put_chr_fd(1, '+' - (11 * !!(formatInfo->m_Flags & FLAG_MASK_BLANK)));
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && (formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding(1, width_len);
	ret += print_padding(1, prec_len);
	if (!((formatInfo->m_Precision == 0) && (number == 0)))
		ret += put_sint_fd(fd, ablsolute_sint(number));
	if ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding(0, width_len);
	return (ret);
}