#include "monty.h"
/**
* f_rotl- rotates the stack to the top
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}

/**
* f_rotr- rotates the stack to the bottom
* @stack: stack head
* @line_number: line_number
* Return: void
*/
void f_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
