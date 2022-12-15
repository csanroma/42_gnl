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

/* Compile using the folowing flags:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files>.c
where n is the buffer size (amount of time allowed for your computer to process 
the audio of your sound card or audio interface)
OPEN_MAX max No. open files for a single program <stdio.h>
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *txt;
	char		*lin;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = append_line(fd, txt);
	if (!txt)
		return (NULL);
	lin = extract_line(txt);
	txt = trim_source(txt);
	if (!txt)
	{
		free(txt);
	}
	if (!lin)
	{
		free(lin);
		return (NULL);
	}
	return (lin);
}

char	*extract_line(char *txt)
{
	int		i;
	char	*lin;

	i = 0;
	if (!txt)
		return (NULL);
	while (txt[i] && txt[i] != '\n')
		i++;
	lin = (char *)malloc(sizeof(char) * (i + 2));
	if (!lin)
		return (NULL);
	i = 0;
	while (txt[i] && txt[i] != '\n')
	{
		lin[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		lin[i] = txt[i];
		i++;
	}
	lin[i] = '\0';
	return (lin);
}

char	*trim_source(char *temp)
{
	int		i;
	int		j;
	char	*txt;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	txt = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i));
	if (!txt)
	{
		free (txt);
		return (NULL);
	}
	i++;
	j = 0;
	while (temp[i])
		txt[j++] = temp[i++];
	txt[j] = '\0';
	free(temp);
	return (txt);
}

char	*append_line(int fd, char *txt)
{
	char	*lin;
	int		i;

	i = 1;
	lin = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!lin)
		return (NULL);
	while (!ft_findchar(txt, '\n') && i != 0)
	{
		i = read(fd, lin, BUFFER_SIZE);
		if (i == -1)
		{
			free (txt);
			free (lin);
			return (NULL);
		}
		lin[i] = '\0';
		txt = ft_strjoin(txt, lin);
	}
	free (lin);
	return (txt);
}
