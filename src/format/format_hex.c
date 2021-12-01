#include "formats.h"
#include "../utils/utils.h"

int	get_number_str_length_hex(unsigned int number);
int	get_preciscion_str_length_hex(const t_format_info *formatInfo, unsigned int number);
int	get_width_str_length_hex(const t_format_info *formatInfo, int precLen, unsigned int number);
size_t	print_padding_hex(int zero, int width);

size_t
	print_uhex(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t			ret;
	unsigned int	number;
	int				num_len;
	int				prec_len;
	int				width_len;

	number = va_arg(*current, unsigned int);
	num_len = get_number_str_length_hex(number);
	prec_len = get_preciscion_str_length_hex(formatInfo, number);
	width_len = get_width_str_length_hex(formatInfo, prec_len, number);
	ret = 0;
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && !(formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_hex(0, width_len);
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && (formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_hex(1, width_len);
	if ((formatInfo->m_Flags & FLAG_MASK_SHARP) && number)
		ret += put_str_fd(1, "0X");
	ret += print_padding_hex(1, prec_len);
	if (!((formatInfo->m_Precision == 0) && (number == 0)))
		ret += put_ihex_fd(fd, number, "0123456789ABCDEF");
	if ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_hex(0, width_len);
	return (ret);
}

size_t
	print_lhex(int fd, t_format_info *formatInfo, va_list *current)
{
	size_t			ret;
	unsigned int	number;
	int				num_len;
	int				prec_len;
	int				width_len;

	number = va_arg(*current, unsigned int);
	num_len = get_number_str_length_hex(number);
	prec_len = get_preciscion_str_length_hex(formatInfo, number);
	width_len = get_width_str_length_hex(formatInfo, prec_len, number);
	ret = 0;
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && !(formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_hex(0, width_len);
	if (!(formatInfo->m_Flags & FLAG_MASK_MINUS) && (formatInfo->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_hex(1, width_len);
	if ((formatInfo->m_Flags & FLAG_MASK_SHARP) && number)
		ret += put_str_fd(1, "0x");
	ret += print_padding_hex(1, prec_len);
	if (!((formatInfo->m_Precision == 0) && (number == 0)))
		ret += put_ihex_fd(fd, number, "0123456789abcdef");
	if ((formatInfo->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_hex(0, width_len);
	return (ret);
}