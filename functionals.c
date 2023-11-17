#include "monty.h"
/**
 *create_node - streates a node
 *@n: the number of node
 *Return: returns the node
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		error_1(3);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 *freeNode - frees nodes
 */
void freeNode(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
	}
}

/**
 *funccall - calls the function
 *@func: the function
 *@op: operator
 *@val: pointer to the value
 *@lnum: the line number
 *@format: either stack or queue
 */
void funccall(op_func func, char *op, char *val, int lnum, int format)
{
	int i, flag;
	stack_t *node;

	flag = 1;

	if (strcmp(op, "push") == 0)
	{
		if (val[0] == '-' && val != NULL)
		{
			val += 1;
			flag = -1;
		}
		if (val == NULL)
			error_1(4, lnum);
		i = 0;

		while (val[i] != '\0')
		{
			i++;
			if (isdigit(val[i]) == 0)
				error_1(4, lnum);
		}
		node = create_node(atoi(val) * flag);

		if (format == 1)
			add_to_queue(&node, lnum);
		if (format == 0)
			func(&node, lnum);
	}
	else
		func(&head, lnum);
}
