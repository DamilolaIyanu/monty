#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

int main(int ac, char *av[]);
void error_1(int error_code, ...);
int tokenize(char *buf, int lnum, int format);
void readFile(FILE *fd);
void openFile(char *fileName);
void wchFunc(char *opcode, char *value, int lnum, int format);
void freeNodes(void);
stack_t *create_node(int n);
void funccall(op_func func, char *op, char *val, int lnum, int format);
void print_stack(stack_t **stack, unsigned int lnum);
void print_top(stack_t **stack, unsigned int lnum);
void add_to_stack(stack_t **newnode, _attribute_((unused)), unsigned int lnum);
void add_nodes(stack_t **stack, unsigned int lnum);
void nop(stack_t **stack, unsigned int lnum);



#endif
