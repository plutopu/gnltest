#include <stdio.h>
#include <stdlib.h>

void i_control_the_die(const char *filename, const char *line_content, size_t line_count)
{
	FILE *file = fopen(filename, "w");
	if (!file) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 1; i < line_count; i++) {
		fprintf(file, line_content, i);
	}

	fclose(file);
	}

int main() {
	const char	*filename = "controlthedie.txt";
	const char	*line_content = "I do not control the speed at which \033[0;38;5;161mlobster\033[0;37m №%zu dies\n";
	size_t lobsters = 1000001;

	i_control_the_die(filename, line_content, lobsters);
	printf("Large file '%s' created with %zu lines.\n", filename, lobsters);

	return 0;
}