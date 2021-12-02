#include "utils.h"

size_t
	print_padding(int ch, int times)
{
	size_t	ret;

	ret = 0;
	while (times >= 0)
	{
		ret += put_chr_fd(1, ch);
		times--;
	}
	return (ret);
}
