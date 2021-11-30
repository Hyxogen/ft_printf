#include "utils.h"

size_t
	put_sint_fd(int fd, int number)
{
	(void) fd;
	(void) number;
	return (0);
}

static size_t put_sintn_fd_internal(int fd, long number, size_t *n) {
	size_t	ret;

	ret = 0;
	if (number / 10)
	{
		ret = put_sintn_fd_internal(fd, number / 10, n);
		*n -= 1;
	}
	if (*n)
		ret += put_chr_fd(fd, '0' + (number % 10));
	return (ret);
}

size_t
	put_sintn_fd(int fd, long number, size_t n)
{
	size_t	ret;

	ret = 0;
	if (n && number < 0)
	{
		number *= -1;
		ret += put_chr_fd(fd, '-');
		n--;
	}
	ret += put_sintn_fd_internal(fd, number, &n);
	return (ret);
}
