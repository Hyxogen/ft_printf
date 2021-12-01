#include "../format_info.h"
#include "../utils/utils.h"

int get_number_str_length(unsigned int number)
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

int get_preciscion_str_length(const t_format_info *formatInfo, unsigned int number) {
	int	num_len;

	num_len = get_number_str_length(number);
	if (formatInfo->m_Precision > num_len)
		return (formatInfo->m_Precision - num_len);
	return (0);
}

int get_width_str_length(const t_format_info *formatInfo, int precLen, unsigned int number) {
	int	total_len;

	total_len = get_number_str_length(number) + precLen;
	if ((formatInfo->m_Precision == 0) && !(number))
		total_len--;
	if ((formatInfo->m_Flags & FLAG_MASK_SHARP) && number)
		total_len += 2;
	if (formatInfo->m_Width > total_len)
		return (formatInfo->m_Width - total_len);
	return (0);
}

size_t print_padding(int zero, int width)
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