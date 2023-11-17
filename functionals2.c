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

