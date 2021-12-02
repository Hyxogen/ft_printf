#include <wchar.h>

void
	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *) s;
	while (n)
	{
		if (*arr == (unsigned char) c)
			return (arr);
		arr++;
		n--;
	}
	return (0);
}
