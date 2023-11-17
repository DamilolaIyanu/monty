#include "monty.h"
/**
 *readFile - reads the file
 *@fd: pointer to the file to be read
 */
void readFile(FILE *fd)
{
	int lnum, format = 0;
	char *buf = NULL;
	size_t len = 0;

	lnum = 1;
	while ((getline(&buf, &len, fd) != -1))
	{
		lnum++;
		format = tokenize(buf, lnum, format);
	}
	free(buf);
}

/**
 *openFile - opens file with read permission
 *@fileName: the pointer to the file to be opened
 */
void openFile(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (fd == NULL || fileName == NULL)
		error_1(2, fileName);
	readFile(fd);
}

/**
 *main - the entrance to the prog
 *@ac: argument count
 *@av: argument vector
 *Return: returns 0
 */

int main(int ac, char *av[])
{
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty files");
		exit(EXIT_FAILURE);
	}
	openFile(av[1]);
	freeNode();
	return (0);
}
