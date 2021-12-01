#include "utils.h"

size_t
	put_sint_fd(int fd, long number)
{
	size_t	ret;

	ret = 0;
	if (number / 10)
		ret += put_sint_fd(fd, number / 10);
	ret += put_chr_fd(fd, '0' + (number % 10));
	return (ret);
}

size_t
	put_ihex_fd(int fd, unsigned int number, const char *baseStr)
{
	size_t	ret;

	ret = 0;
	if (number / 16)
		ret += put_ihex_fd(fd, number / 16, baseStr);
	ret += put_chr_fd(fd, baseStr[number % 16]);
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
