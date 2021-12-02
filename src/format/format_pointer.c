#include "../format_info.h"
#include "../utils/utils.h"

int
	get_number_str_length_ptr(unsigned long long number)
{
	int	num_len;

	num_len = 1;
	while (number / 16)
	{
		num_len++;
		number /= 16;
	}
	return (num_len);
}

int
	get_preciscion_str_length_ptr(const t_format_info *fInf,
	unsigned long long number) {
	int	num_len;

	num_len = get_number_str_length_ptr(number);
	if (fInf->m_Precision > num_len)
		return (fInf->m_Precision - num_len);
	return (0);
}

int
	get_width_str_length_ptr(const t_format_info *fInf, int precLen,
	unsigned long long number) {
	int	total_len;

	total_len = get_number_str_length_ptr(number) + precLen;
	if ((fInf->m_Precision == 0) && !(number))
		total_len--;
	total_len += 2;
	if (fInf->m_Width > total_len)
		return (fInf->m_Width - total_len);
	return (0);
}

size_t
	print_padding_ptr(int zero, int width)
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
	print_pointer(int fd, t_format_info *fInf, va_list *current)
{
	size_t				ret;
	unsigned long long	number;
	int					num_len;
	int					prec_len;
	int					width_len;

	number = va_arg(*current, unsigned long long);
	num_len = get_number_str_length_ptr(number);
	prec_len = get_preciscion_str_length_ptr(fInf, number);
	width_len = get_width_str_length_ptr(fInf, prec_len, number);
	ret = 0;
	if (!(fInf->m_Flags & FLAG_MASK_MINUS) && !(fInf->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_ptr(0, width_len);
	if (!(fInf->m_Flags & FLAG_MASK_MINUS) && (fInf->m_Flags & FLAG_MASK_ZERO))
		ret += print_padding_ptr(1, width_len);
	ret += put_str_fd(1, "0x");
	ret += print_padding_ptr(1, prec_len);
	if (!((fInf->m_Precision == 0) && (number == 0)))
		ret += put_number_base_unsigned(fd, number, "0123456789abcdef", 16);
	if ((fInf->m_Flags & FLAG_MASK_MINUS) == FLAG_MASK_MINUS)
		ret += print_padding_ptr(0, width_len);
	return (ret);
}
