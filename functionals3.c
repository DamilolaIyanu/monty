#include "monty.h"
/**
 *pop_top- deletes the top
 *@stack: the structure
 *@lnum: the line number
 */
void pop_top(stack_t **stack, unsigned int lnum)
{
	stack_t *tmp;
	if(*stack == NULL)
		error_2(2.1, lnum);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 *swap_node- swaps the node
 *@stack: the stack
 *lnum: the line number
 */
void swap_node(stack_t **stack, unsigned int lnum)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		error_2(3.1, lnum, "swap");

	tmp = (*stack)->next;

	(*stack)->next = tmp->next;
	if (tmp->next != Null)
		tmp->next->prev = *stack;

	tmp->next = *stack;

	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 *div_nodes - divide nodes
 *stack: the stack
 *@lnum: the line number
 */
void div_nodes(stack_t **stack, unsigned int lnum)
{
	int div;
	if (*stack == NULL || (*stack)->next == NULL)
		error_2(3.1, lnum, "div");
	if ((*stack)->n == 0)
		error_2(4.1, lnum);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 *mul_nodes - multiplies the node
 *@stack: the stack
 *@lnum: the line number
 */
void mul_nodes(stack_t **stack, unsigned int lnum)
{
	int mul;
	if(*stack == NULL || (*stack)->next == NULL)
		error_2(3.1, lnum, "mul");
	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 *sub_nodes - subtracts the nodes
 *@stack: the stack
 *@lnum: the line number
 */
void sub_nodes(stack_t **stack, unsigned int lnum)
{
	int sub;
	if (*stack == NULL || (*stack)->next == NULL)
		error_2(3.1, lnum, "sub");
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
