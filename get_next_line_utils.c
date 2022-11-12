/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:38:19 by csanroma          #+#    #+#             */
/*   Updated: 2022/08/28 18:38:21 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return(-1);
	else
	{
		while (*(str + c))
			c++;
	}
	//printf("%zu",c);
	return (c);
}

/* The strchr() function locates the first occurrence of c (char)
 in the string pointed to by s.  The terminating null character is considered 
 to be part of the string; therefore if c is `\0', the functions locate the 
 terminating `\0'. */

int	ft_findchar(const char *s, int c)
{
	//printf("findchar = str %s \n",s);
	if (!s)
		return (-1);
	else
	{
		while (*s != (char)c)
			s++;
		return (1);
	}
}

/*The strdup() function allocates sufficient memory for a copy of the string 
s1, does the copy, and returns a pointer to it.  The pointer may subsequently 
be used as an  argument to the function free(3).*/

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (*(s1 + i) != 0)
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (s2 == '\0')
		return (0);
	*(s2 + i) = '\0';
	while (i + 1 > 0)
	{
		*(s2 + i) = *((char *)s1 + i);
		i--;
	}
	return (s2);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n_src;

	n_src = 0;
	while (*(src + n_src) != 0)
		n_src++;
	i = 1;
	while ((*src != 0) && i < size)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
	}	
	if (size != 0)
		*dest = '\0';
	return (n_src);
}

/*s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
	{
		s2 = malloc(sizeof(char));
		if (s2 != NULL)
			s2[0] = 0;
		return (s2);
	}
	if (len > str_len - start)
		len = str_len - start;
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}

/*s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		str = ft_strdup(s2);
		return (str);
	}
	lens1 = ft_strlen(s1);
	if (s2 == NULL)
		return (ft_strdup(s1));
	lens2 = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcpy(str + lens1, s2, lens2 + 1);
	return (str);
}
