#include <unistd.h>

size_t
	put_chr_fd(int fd, int c)
{
	return (write(fd, &c, 1));
}
