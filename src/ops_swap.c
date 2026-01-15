/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:33:01 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_stack(t_stack *s)
{
  int tmp;
  int next_idx;

  if (s->size < 2)
    return;
  next_idx = (s->head + 1) % s->capacity;
  tmp = s->data[s->head];
  s->data[s->head] = s->data[next_idx];
  s->data[next_idx] = tmp;
}

void sa(t_ps *ps, int print)
{
  swap_stack(&ps->a);
  if (print)
    ft_putstr("sa\n");
}

void sb(t_ps *ps, int print)
{
  swap_stack(&ps->b);
  if (print)
    ft_putstr("sb\n");
}

void ss(t_ps *ps, int print)
{
  swap_stack(&ps->a);
  swap_stack(&ps->b);
  if (print)
    ft_putstr("ss\n");
}
