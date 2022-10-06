#include "monty.h"
/**
* f_pchar - prints the char at the top of the stack,
* followed by a new line
* @stack: stack head
* @line_number: line_number
* Return: no return
*/
void f_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}


/**
* f_pstr - prints the string starting at the top of the stack,
* followed by a new line
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}


/**
* f_stack - sets the flag
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 0;
}

/**
* f_queue - sets the flag
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}
