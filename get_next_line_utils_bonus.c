#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (*(s + i))
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dest + i + j) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*temp;

	if (!*s1 && !s1)
		return (NULL);
	temp = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(temp + i) = *(s1 + i);
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s && !*s)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		dest = (char *)malloc(sizeof(char));
		if (!dest)
			return (NULL);
		*(dest + i) = '\0';
	}
	else
	{
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (NULL);
		while (i < len && *(s + start))
			*(dest + i++) = *(s + start++);
		*(dest + i) = '\0';
	}
	return (dest);
}
