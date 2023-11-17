#include "monty.h"
/**
 *error_1 - handles error
 *@error_code:  the list of codes
 */
void error_1(int error_code, ...)
{
	va_list arg;
	char *op;
	int num;

	va_start(arg, error_code);

	if (1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (2)
	{
		fprintf(stderr, "Error: can't open file %s\n", va_arg(arg, char *));
	}
	else if (3)
	{
		fprintf(stderr, "Error: malloc failed\n")
	}
	else if (4)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
	}
	else if (5)
	{
		num = va_arg(arg, int);
		op = va_arg(arg, char *);
		fprintf(stderr, "L%d: Unknown instruction %s\n", num, op);
	}
	free_node();
	exit(EXIT_FAILURE);

}
/**
 *error_2 - handles error
 *@error_code: the error codes
 */

void error_2(int error_code, ...)
{
	va_list arg;
	char *op;
	int num;

	va_start(arg, error_code);

	if (1.1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
	}
	else if (2.1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
	}
	else if (3.1)
	{
		num = va_arg(arg, unsigned int);
		op = va_arg(arg, char *);
		fprintf(stderr, "L%d: can't swap, stack too short\n", num, op);
	}
	else if (4.1)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(arg, unsigned int));
	}
	else if (5.1)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
	}
	else if (6.1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num)
	}
	free_node();
	exit(EXIT_FAILURE);

}
