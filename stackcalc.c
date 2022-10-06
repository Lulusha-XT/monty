#include "monty.h"
/**
* f_add - adds the top two elements of the stack.
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*stack = temp->next;
	free(temp);
}

/**
* f_sub- sustraction
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sus, nodes;

	temp = *stack;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sus = temp->next->n - temp->n;
	temp->next->n = sus;
	*stack = temp->next;
	free(temp);
}

/**
* f_mul - multiplies the top two elements of the stack.
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
