/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:32:11 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_init(t_stack *stack, int capacity, char id)
{
  stack->data = (int *)malloc(sizeof(int) * capacity);
  if (!stack->data)
    return (0);
  stack->head = 0;
  stack->size = 0;
  stack->capacity = capacity;
  stack->id = id;
  return (1);
}

void stack_free(t_stack *stack)
{
  if (stack->data)
    free(stack->data);
  stack->data = NULL;
  stack->size = 0;
  stack->capacity = 0;
}

int ps_init(t_ps *ps, int capacity)
{
  if (!stack_init(&ps->a, capacity, 'a'))
    return (0);
  if (!stack_init(&ps->b, capacity, 'b')) 
  {
    stack_free(&ps->a);
    return (0);
  }
  return (1);
}

void ps_free(t_ps *ps)
{
  stack_free(&ps->a);
  stack_free(&ps->b);
}
