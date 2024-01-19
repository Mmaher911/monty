#include "monty.h"

/**
 * mulnodes - Add top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void mulnodes(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, linenumber, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modnodes - Add top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @linenumber: the line number of of the opcode.
 */
void modnodes(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, linenumber, "mod");


	if ((*stack)->n == 0)
		more_error(9, linenumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
