#ifndef LIBFT_H
# define LIBFT_H
# include <wchar.h>
# include <stdlib.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *dest, int ch, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
