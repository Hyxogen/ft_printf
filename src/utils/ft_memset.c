#include <stdint.h>
#include <wchar.h>

static void
	*ft_memset_eightb(void *dest, int ch, size_t len)
{
	uint64_t	*array;
	uint64_t	val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	val |= val << 16;
	val |= val << 32;
	array = dest;
	while (len)
	{
		*array = val;
		len--;
		array++;
	}
	return (dest);
}

static void
	*ft_memset_fourb(void *dest, int ch, size_t len)
{
	uint32_t	*array;
	uint32_t	val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	val |= val << 16;
	array = dest;
	while (len)
	{
		*array = val;
		len--;
		array++;
	}
	return (dest);
}

static void
	*ft_memset_twob(void *dest, int ch, size_t len)
{
	uint16_t	*array;
	uint16_t	val;

	val = 0;
	val = (uint8_t) ch;
	val |= ((uint8_t) ch) << 8;
	array = dest;
	while (len)
	{
		*array = val;
		len--;
		array++;
	}
	return (dest);
}

void
	*ft_memset_singleb(void *dest, int ch, size_t len)
{
	unsigned char	*array;

	if (!len)
		return (dest);
	array = dest;
	while (len)
	{
		*array = (unsigned char) ch;
		len--;
		array++;
	}
	return (dest);
}
/*
void
	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char	*array;

	if (!len)
		return (dest);
	array = dest;
	while (len)
	{
		*array = (unsigned char) ch;
		len--;
		array++;
	}
	return (dest);
}
*/

void
	*ft_memset(void *dst, int ch, size_t len)
{
	unsigned char	*array;

	array = dst;
	if (len >> 3)
	{
		ft_memset_eightb(dst, ch, len >> 3);
		array += (len >> 3) << 3;
		len -= (len >> 3) << 3;
	}
	if (len >> 2)
	{
		ft_memset_fourb(array, ch, len >> 2);
		array += (len >> 2) << 2;
		len -= (len >> 2) << 2;
	}
	if (len >> 1)
	{
		ft_memset_twob(array, ch, len >> 1);
		array += (len >> 1) << 1;
		len -= (len >> 1) << 1;
	}
	if (len)
		ft_memset_singleb(array, ch, len);
	return (dst);
}
