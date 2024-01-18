#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void swap_top_elements(stack_t **head, unsigned int counter);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void print_stack(stack_t **head, unsigned int number);
void do_nothing(stack_t **head, unsigned int counter);
void print_top_element(stack_t **head, unsigned int number);
void pop_top_element(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void add_top_two_elements(stack_t **stack, unsigned int line_number);
void subtract_top_elements(stack_t **head, unsigned int counter);
void divide_top_two_elements(stack_t **head, unsigned int counter);
void add_node_to_stack(stack_t **head, int n);
void push_node(stack_t **head, unsigned int number);
void multiply_top_two_elements(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void print_char_at_top(stack_t **head, unsigned int counter);
void print_string_from_top(stack_t **head, unsigned int counter);
void queue_top(stack_t **head, unsigned int counter);
void rotate_stack_left(stack_t **head, unsigned int counter);
void add_queue_node(stack_t **head, int n);
void print_stack_top(stack_t **head, unsigned int counter);
int execute_opcode(char *content, stack_t **head, unsigned int counter, FILE *file);
void rotate_stack_right(stack_t **head, __attribute__((unused)) unsigned int counter);
#endif
