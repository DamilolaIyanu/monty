#include "monty.h"
/**
 *tokenize - parses the line
 *@buf: stores the line
 *@lnum: the line number
 *@format: the file format
 *Return: returns the format number
 */

int tokenize(char *buf, int lnum, int format)
{
	char *opcode, *value;
	const char *delimeter = "\n";

	if (buf == NULL)
		error_1(5);
	opcode = strtok(buf, delimeter);
	if (opcode == NULL)
		return (format);
	value = strtok(buf, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (-1);

	findFunc(opcode, value, lnum, format);
	return (format);
}
