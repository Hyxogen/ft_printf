#include "../format_info.h"
#include "../utils/utils.h"

int		get_number_str_length_int(long number);
int		get_preciscion_str_length_int(const t_format_info *fInf,
			long number);
int		get_width_str_length_int(const t_format_info *fInf,
			int precLen, long number);
size_t	print_padding_int(int zero, int width);

size_t
	print_uint(int fd, t_format_info *fInf, va_list *current)
{
	size_t			ret;
	unsigned int	number;
	int				num_len;
	int				prec_len;
	int				width_len;

	number = va_arg(*current, unsigned int);
	num_len = get_number_str_length_int(number);
	prec_len = get_preciscion_str_length_int(fInf, number);
	width_len = get_width_str_length_int(fInf, prec_len, number);
	ret = 0;
	if (!(fInf->m_Flags & FLAG_MASK_MINUS))
		ret += print_padding_int(fInf->m_Flags & FLAG_MASK_ZERO, width_len);
	ret += print_padding_int(1, prec_len);
	if (!((fInf->m_Precision == 0) && (number == 0)))
		ret += put_number_base_unsigned(fd, number, BTEN, 10);
	if ((fInf->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_int(0, width_len);
	return (ret);
}
