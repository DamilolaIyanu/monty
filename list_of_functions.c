#include "monty.h"
/**
 *wchFunc - finds the function to perform
 *@opcode: pointer to the op
 *@value: pointer to the value contained in the opcode
 *@lnum: the line number
 *@format: the format
 */
void wchFunc(char *opcode, char *value, int lnum, int format)
{
	int i, flag;

	instruction_t funcList[] = {
		{"push", add_to stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"nop", nop},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL},
	};
	if (opcode[0] == '#')
		return;

	i = 0;
	flag = 1;
	while (funcList[i].opcode != NULL)
	{
		i++;
		if (strcmp(opcode, funcList[i].opcode) == 0)
		{
			funccall(funcList[i].f, opcode, value, lnum, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_1(5, lnum, opcode);
}
