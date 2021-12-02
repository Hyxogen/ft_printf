#include <wchar.h>

size_t
	ft_strlen(const char *str)
{
	const char	*temp;

	temp = str;
	while (*temp)
		temp++;
	return (temp - str);
}
