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

	lin = NULL;
	//printf("lin--->\n %d\n ------ \n",lin == NULL); //////<----- ************>
	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	
	/*if (ft_findchar(txt,'\n') == 1)
	{
		txt = read_txt(txt, fd);
	}*/

	txt = read_txt(txt, fd);	
	//printf("lee txt = \n\n%s\n\n",txt);
	if (txt)
		lin = read_lin(&txt);
	return (lin);
}

char	*read_txt(char *txt, int fd)
{
	char	append_txt[BUFFER_SIZE + 1];
	int		nbytes;

	nbytes = read (fd, &append_txt, BUFFER_SIZE);
	while (nbytes > 0)
	{
		append_txt[nbytes] = '\0';
		txt = ft_strjoin(txt, append_txt);
		nbytes = read (fd, &append_txt, BUFFER_SIZE);
	}
	//printf("sale del loop\n");
	return (txt);
}

int	ft_min(i1,i2)
{
	if (i1 > i2)
		return(i2);
	return (i1);
}

char	*read_lin(char **txt)
{
	char	*lin;
	char	*txt_cpy;
	size_t	i;
	size_t	strlen;

	i = 0;
	txt_cpy = *txt;
	strlen = ft_strlen(*txt);
	
	if (!*txt[0])
		return (NULL);
	
	//printf("entra txt = %s \n",*txt);
	while (txt_cpy[i] && (txt_cpy[i+1] != '\n') && i < strlen)
		i++;

	//printf("strlen = %zu ; i = %zu\n",strlen, i);
	if (txt_cpy[i + 1] == '\n' && (i + 1) < strlen)
	{
		lin = ft_substr(*txt, 0, ft_min(i + 2, BUFFER_SIZE));
		*txt = *txt + i + 2;
		//printf("lin +%s+\n",lin);
		//printf("txt +%s+\n",*txt);
	}
	else /* end of file */
	{
		lin = ft_substr(*txt, 0, ft_min(i + 1, BUFFER_SIZE));
		//*txt = *txt + i + 1;
		*txt = NULL;
		//printf("lin -%s-\n",lin);
		//printf("txt -%s-\n",*txt);
	}
	//printf("i = %zu lin--->\n%s\n ------ \n",i,lin); //////<----- ************>
	/*if (strlen >= i + 1)
		txt_cpy = ft_substr(*txt, i + 1, strlen - i - 1);
	free(*txt);
	*txt = txt_cpy;*/
	//*txt = *txt + i;
	
	return (lin);
}
