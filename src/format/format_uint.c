#include "../format_info.h"
#include "../utils/utils.h"

int		get_number_str_length_int(long number);
int		get_preciscion_str_length_int(const t_format_info *formatInfo,
			long number);
int		get_width_str_length_int(const t_format_info *formatInfo,
			int precLen, long number);
size_t	print_padding_int(int zero, int width);

size_t
	print_uint(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t			ret;
	unsigned int	number;
	int				num_len;
	int				prec_len;
	int				width_len;

	number = va_arg(*current, unsigned int);
	num_len = get_number_str_length_int(number);
	prec_len = get_preciscion_str_length_int(formatInfo, number);
	width_len = get_width_str_length_int(formatInfo, prec_len, number);
	ret = 0;
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS))
		ret += print_padding_int(formatInfo->m_Flags & FLAG_MASK_ZERO, width_len);
	ret += print_padding_int(1, prec_len);
	if (!((formatInfo->m_Precision == 0) && (number == 0)))
		ret += put_number_base_unsigned(fd, number, "0123456789", 10);
	if ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_int(0, width_len);
	return (ret);
}
