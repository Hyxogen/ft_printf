#include "../format_info.h"
#include "../utils/utils.h"

int get_number_str_length_int(long number)
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

int get_preciscion_str_length_int(const t_format_info *formatInfo, long number) {
	int	num_len;

	num_len = get_number_str_length_int(number);
	if (number < 0)
		num_len--;
	if (formatInfo->m_Precision > num_len)
		return (formatInfo->m_Precision - num_len);
	return (0);
}

int get_width_str_length_int(const t_format_info *formatInfo, int precLen, long number) {
	int	total_len;

	total_len = get_number_str_length_int(number) + precLen;
	if ((formatInfo->m_Precision == 0) && !(number))
		total_len--;
	if ((number >= 0) && (formatInfo->m_Flags & (FLAG_MASK_BLANK | FLAG_MASK_PLUS)))
		total_len++;
	if (formatInfo->m_Width > total_len)
		return (formatInfo->m_Width - total_len);
	return (0);
}

size_t print_padding_int(int zero, int width)
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