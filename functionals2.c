#include "monty.h"
/**
 *add_to_stack - add a newnode to a stack
 *@newnode: the new node
 *@lnum: line number
 */
void add_to_stack(stack_t **newnode, _attribute_((unused)), unsigned int lnum)
{
	stack_t *tmp;
	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	tmp = head;
	head = *newnode;
	head->next = tmp;
	tmp->prev = head;
}
/**
 *add_nodes - adds nodes to the stack
 *@lnum: the line number
 *@stack: pointer to the stack
 */
void add_nodes(stack_t **stack, unsigned int lnum)
{
	int sum;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
		error_2(3.1, lnum, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack->prev->n);
	*stack->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *print_top - prints thetop of stack
 *@stack: pointer to the stack
 *@lnum: the line number
 */
void print_top(stack_t **stack, unsigned int lnum)
{
	if (*stack == NULL)
		error_2(1.1, lnum);
	printf("%d\n", (*stack)->n);
}
/**
 *print_stack - pointer to the stack
 *stack: pointer to the stack
 *@lnum: line number
 */
void print_stack(stack_t **stack, unsigned int lnum)
{
	stack_t *tmp;
	unsigned int lnum;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *nop - does nothing
 *@stack: pointer to the stack
 *@lnum: line number
 */
void nop(stack_t **stack, unsigned int lnum)
{
	(void)stack;
	(void)lnum;
}
