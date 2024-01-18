#include "monty.h"

/**
 * error - Prints appropiate error messages determined.
 * @error_cod: The following error codes are:
 * (1) => The user does not give any file.
 * (2) => The file provided can not be opened or read.
 * (3) => The file contains an invalid instruction.
 * (4) => When the program is unable to malloc any more memory.
 * (5) => When the parameter is not an int.
 * (6) => When stack it empty for pint.
 * (7) => When stack it empty for pop.
 * (8) => When stack is too short for the operation.
 */
void error(int error_cod, ...)
{
	va_list agg;
	char *opp;
	int l_num;

	va_start(agg, error_cod);
	switch (error_cod)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agg, char *));
			break;
		case 3:
			l_num = va_arg(agg, int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles more errors.
 * @error_cod: error codes are as following:
 * (6) => When stack it empty for pint.
 * (7) => When stack it empty for pop.
 * (8) => When the stack is too short for operation.
 * (9) => Division by zero
 */

void more_error(int error_cod, ...)
{
	va_list agg;
	char *opp;
	int l_num;

	va_start(agg, error_cod);
	switch (error_cod)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agg, int));
			break;
		case 8:
			l_num = va_arg(agg, unsigned int);
			opp = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles string errors.
 * @error_cod: error codes are as following:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> stack is empty.
 */
void string_error(int error_cod, ...)
{
	va_list agg;
	int l_num;

	va_start(agg, error_cod);
	l_num = va_arg(agg, int);
	switch (error_cod)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
