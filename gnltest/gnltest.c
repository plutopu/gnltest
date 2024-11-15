#include <fcntl.h>
#include <stdio.h>

int main()
{
	int file = open("ergosum.txt", O_RDONLY);
	char *result = get_next_line(file);
	if (result)
	{
		printf("%s", result);
		free(result);
	}
	result = get_next_line(file);
	if (result)
	{
		printf("%s", result);
		free(result);
	}
	while ((result = get_next_line(file)) != NULL)
		free(result);
	close(file);
	return 0;
}
