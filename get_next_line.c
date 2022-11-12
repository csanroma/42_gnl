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
	txt = read_txt(txt, fd);
	//write(1,&txt[0],1);
	//printf(" --- %d\n",txt[0]);
	//printf("find char ---> %d\n",ft_findchar(txt,'\n')); //////<----- ************>
	//if (ft_findchar(txt,'\n') == 1)
	if (*txt != 0)
		lin = read_lin(&txt);
	//printf("lin--->%d ------ \n",lin == NULL); //////<----- ************>
	return (lin);
}

char	*read_txt(char *txt, int fd)
{
	char	append_txt[BUFFER_SIZE + 1];
	int		nbytes;

	nbytes = read (fd, &append_txt, BUFFER_SIZE);
	//printf("nbytes = %d\n",nbytes); //////<----- ************>
	while (nbytes > 0)
	{
		append_txt[nbytes] = '\0';
		//printf("txt %s\n",txt); //////<----- ************>
		//printf("append text %s\n",append_txt); //////<----- ************>
		txt = ft_strjoin(txt, append_txt);
		//printf("txt ---\n%s\n",txt); //////<----- ************>
		nbytes = read (fd, &append_txt, BUFFER_SIZE);
		//printf("nbytes = %d\n",nbytes); //////<----- ************>
	}
	//printf("sale del loop\n");
	return (txt);
}

char	*read_lin(char **txt)
{
	char	*lin;
	char	*txt_cpy;
	size_t	i;
	size_t	strlen;

	i = 0;
	//printf("---> entra en readlin\n"); //////<----- ************>
	txt_cpy = *txt;
	//printf("txt---> %s ------ \n",*txt); //////<----- ************>
	//printf("txt cpy--->\n %s\n ------ \n",txt_cpy); //////<----- ************>
	strlen = ft_strlen(*txt);
	//printf("strlen = %zu\n",strlen);  //////<----- ************>
	if (!*txt)
		return (NULL);
	
	while (txt_cpy[i] && (txt_cpy[i+1] != '\n'))
		i++;
	//printf("i = %zu\n",i); //////<----- ************>
	if (txt_cpy[i + 1] == '\n')
	{
		lin = ft_substr(*txt, 0, i + 2);
		*txt = *txt + i + 2;
		//printf("txt---> %s ------ \n",*txt); //////<----- ************>
	}
	else /* end of file */
	{
		lin = ft_substr(*txt, 0, i + 1);
		*txt = *txt + i + 1;
		//*txt = NULL;
	}
	//printf("i = %zu lin--->\n%s\n ------ \n",i,lin); //////<----- ************>
	/*if (strlen >= i + 1)
		txt_cpy = ft_substr(*txt, i + 1, strlen - i - 1);
	free(*txt);
	*txt = txt_cpy;*/
	//*txt = *txt + i;
	
	return (lin);
}
