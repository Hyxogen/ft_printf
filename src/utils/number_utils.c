#include "utils.h"

//does not work for min long long number
size_t
	put_number_base_signed(int fd, long long number,
	 const char *baseStr, int base)
{
	size_t	ret;

	ret = 0;
	if (number < 0)
	{
		ret += put_chr_fd(fd, '-');
		number *= -1;
	}
	if (number / base)
		ret += put_number_base_signed(fd, number / base, baseStr, base);
	ret += put_chr_fd(fd, baseStr[number % base]);
	return (ret);
}

size_t
	put_number_base_unsigned(int fd, unsigned long long number,
	 const char *baseStr, int base)
{
	size_t	ret;

	ret = 0;
	if (number / base)
		ret += put_number_base_unsigned(fd, number / base, baseStr, base);
	ret += put_chr_fd(fd, baseStr[number % base]);
	return (ret);
}

long
	ablsolute_sint(int val)
{
	long	ret;

	ret = val;
	if (ret < 0)
		return (-1 * ret);
	return (ret);
}
