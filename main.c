#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main()
{
	int 	fd;
	char	*str;

	fd = open ("test.txt", O_RDONLY);
	//printf("%d\n", fd);
	str = get_next_line(fd);
	//printf("|%s|\n", str);
	int i = 0;
	while(str != NULL && i< 10)
	{
		printf("|%s|\n", str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
}