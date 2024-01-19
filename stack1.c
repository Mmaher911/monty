#include "monty.h"


/**
 * add_to_st - Adds a node to stack.
 * @newnode: Pointer to new node.
 * @ln: Interger representing line number of of the opcode.
 */

void add_to_st(stack_t **newnode, __attribute__((unused))unsigned int ln)
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
 * printstack - Adds a node to stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of  the opcode.
 */

void printstack(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	(void) linenumber;
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
 * poptop - Adds a node to stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: Interger representing line number of the opcode.
 */

void poptop(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_error(7, linenumber);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printtop - Prints top node of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */

void printtop(stack_t **stack, unsigned int linenumber)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, linenumber);
	printf("%d\n", (*stack)->n);
}
