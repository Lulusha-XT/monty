#include "monty.h"
/**
* f_pall - prints the stack
* @stack: stack head
* @line_number: unused
* Return: void
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* f_pint - prints the top
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* f_pop - prints the top
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}

/**
* f_swap - swaps the top two elements of the stack.
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}


/**
* f_nop- nothing
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
