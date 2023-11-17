#include "monty.h"
/**
 *mod_nodes - modulus op
 *@stack: the stack
 *@lnum: the line number
 */
void mod_nodes(stack_t **stack, unsigned int lnum)
{
	int mod;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(3.1, lnum, "mod");
	if ((*stack)->n == 0)
		error_2(4.1, lnum, "mod");
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *print_char - prints character
 *@stack: the stack
 *@lnum: the line number
 */
void print_char(stack_t **stack, unsigned int lnum)
{
	int ascii;
	if (stack == NULL || *stack == NULL)
		error_2(6.1, lnum);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		error_2(5.1, lnum);
	printf("%c\n", ascii);
}

/**
 *print_str - prints strings
 *@stack: the stack
 *@lnum: the line number
 */
void print_str(stack_t **stack, _attribute_((unused)) unsigned int lnum)
{
	int ascii;
	stack_t *tmp;
	if(stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii < 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
