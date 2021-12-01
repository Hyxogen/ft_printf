#include <unistd.h>
#include "../../Dependencies/Libft/libft.h"

size_t
	put_str_fd(int fd, const char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

size_t
	put_strn_fd(int fd, const char *str, size_t n)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (str_len < n)
		n = str_len;
	return (write(fd, str, n));
}
