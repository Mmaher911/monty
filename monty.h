#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

/*file operations*/
void openfile(char *filename);
int parseline(char *buffer, int line_number, int format);
void readfile(FILE *);
int lenchars(FILE *);
void findfunc(char *, char *, int, int);

/*Stack operations*/
stack_t *createnode(int n);
void freenodes(void);
void printstack(stack_t **, unsigned int);
void add_to_st(stack_t **, unsigned int);
void add_to_que(stack_t **, unsigned int);

void callfun(op_func, char *, char *, int, int);

void printtop(stack_t **, unsigned int);
void poptop(stack_t **, unsigned int);
void nope(stack_t **, unsigned int);
void swapnodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void addnodes(stack_t **, unsigned int);
void subnodes(stack_t **, unsigned int);
void divnodes(stack_t **, unsigned int);
void mulnodes(stack_t **, unsigned int);
void modnodes(stack_t **, unsigned int);

/*String operations*/
void printchar(stack_t **, unsigned int);
void printstr(stack_t **, unsigned int);
void rotleft(stack_t **, unsigned int);

/*Error hanlding*/
void error(int error_cod, ...);
void more_error(int error_cod, ...);
void string_error(int error_cod, ...);
void rotright(stack_t **, unsigned int);

#endif
