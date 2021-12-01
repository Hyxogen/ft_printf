#include "formats.h"
#include "../utils/utils.h"


int	get_number_str_length_int(long number);
int	get_preciscion_str_length_int(const t_format_info *formatInfo, long number);
int	get_width_str_length_int(const t_format_info *formatInfo, int precLen, long number);
size_t	print_padding_int(int zero, int width);

size_t
	print_sint(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t	ret;
	long	number;
	int		num_len;
	int		prec_len;
	int		width_len;

	number = va_arg(*current, int);
	num_len = get_number_str_length_int(number);
	prec_len = get_preciscion_str_length_int(formatInfo, number);
	width_len = get_width_str_length_int(formatInfo, prec_len, number);
	ret = 0;
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && !(formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_int(0, width_len);
	if (number < 0)
		ret += put_chr_fd(1, '-');
	else if (formatInfo->m_Flags & (FLAG_MASK_PLUS | FLAG_MASK_BLANK))
		ret += put_chr_fd(1, '+' - (11 * !!(formatInfo->m_Flags & FLAG_MASK_BLANK)));
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && (formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_int(1, width_len);
	ret += print_padding_int(1, prec_len);
	if (!((formatInfo->m_Precision == 0) && (number == 0)))
		ret += put_sint_fd(fd, ablsolute_sint(number));
	if ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_int(0, width_len);
	return (ret);
}