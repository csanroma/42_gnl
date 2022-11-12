/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanroma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:25:33 by csanroma          #+#    #+#             */
/*   Updated: 2022/10/14 16:25:38 by csanroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_txt(char *txt, int fd);
char	*read_lin(char **txt);

size_t	ft_strlen(const char *str);
int		ft_findchar(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
