#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
// cc -I/home/mshulgin/Projects/getnextline get_next_line.c get_next_line_utils.c /home/mshulgin/Projects/gnltest/gnltest.c

//TODO: add Flip's test for bonus part

void test_get_next_line(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *line;

	if (fd < 0)
	{
		printf("Oops. Couldn't read\n");
		return;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		//printf("%s", line);
		free(line);
	}
	close(fd);
}

void simple_test(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *result = get_next_line(fd);
	if (fd < 0)
	{
		printf("Oops. Couldn't read\n");
		return;
	}
	if (result)
	{
		//printf("%s", result);
		free(result);
	}
	result = get_next_line(fd);
	if (result)
	{
		//printf("%s", result);
		free(result);
	}
	while ((result = get_next_line(fd)) != NULL)
		free(result);
	close(fd);
}


int main()
{
	printf("basic test, ergo sum, if you catch my meaning\n");
	simple_test("ergosum.txt");
	printf("ergo, indeed, sum. lessgo!\n");
	printf("empty file\n");
	test_get_next_line("empty.txt");
	printf("...empty file okay\n");
	printf("Checking that thicc boi\n");
	test_get_next_line("controlthedie.txt");
	printf("...thicc okey\n");
	printf("whacky file\n");
	test_get_next_line("multinewline.txt");
	printf("...which is also okay\n");
	printf("file ends with no newline\n");
	test_get_next_line("nonewline.txt");
	printf("...and it's okay\n");
	printf("and a one-liner, like that fanfic you wrote on tumblr once\n");
	test_get_next_line("oneline.txt");
	printf("...fanfic okay\n");
	return 0;
}


//main from my orig gnl

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int file = open("empty.txt", O_RDONLY);
// 	char *result = get_next_line(file);

// 	while ((result = get_next_line(file)) != NULL)
// 	{
// 		printf("%s", result);
// 	}
// 	// result = get_next_line(file);
// 	// printf("%s", result);
// 	// while ((result = get_next_line(file)) != NULL)
// 	// 	free(result);
// 	close(file);
// 	return 0;
// }