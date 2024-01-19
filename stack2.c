#include "monty.h"

/**
 * nope - Do nothing.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void nope(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}


/**
 * swapnodes - Swaps top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void swapnodes(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, linenumber, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * addnodes - Add top two elements of stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */

void addnodes(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, linenumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subnodes - Add top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void subnodes(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, linenumber, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divnodes - Add top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void divnodes(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, linenumber, "div");

	if ((*stack)->n == 0)
		more_error(9, linenumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
