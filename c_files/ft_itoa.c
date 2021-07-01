#include "so_long.h"

char	*ft_realloc_itoa(char *str, char c)
{
	char	*tmp;
	int	i;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	tmp[0] = c;
	tmp[i + 1] = '\0';
	i = 0;
	while (str[i])
	{
		tmp[i + 1] = str[i];
		i++;
	}
	free(str);
	return (tmp);
}

char	*ft_itoa(int nb)
{
	char	*res;
	int	m;

	res = malloc(sizeof(char));
	res[0] = '\0';
	while (nb >= 10)
	{
		m = nb % 10;
		nb = nb / 10;
		res = ft_realloc_itoa(res, (char)(m + 48));
	}
	res = ft_realloc_itoa(res, (char)(nb + 48));
	return (res);
}
