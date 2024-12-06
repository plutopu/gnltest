#include "get_next_line.h"
#include <sys/types.h>
 #include <sys/stat.h>
       #include <fcntl.h>

#include <stdio.h>

int main(void)
{
	int fd1 = open("controlthedie.txt", O_RDONLY);
	int fd2 = open("shrek.txt", O_RDONLY);
	char *str;
	int i = 0;
	while (i < 20)
	{
		str = get_next_line(fd1);
		printf("1: %s", str);
		free(str);
		str = NULL;

		str = get_next_line(fd2);
		printf("2: %s", str);
		free(str);
		str = NULL;
		i++;
	}
	close(fd1);
	close(fd2);
}