/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:33:22 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate_stack(t_stack *s)
{
  int val;
  int tail_idx;

  if (s->size < 2)
    return;
  tail_idx = (s->head + s->size - 1) % s->capacity;
  val = s->data[tail_idx];
  s->head = (s->head - 1 + s->capacity) % s->capacity;
  s->data[s->head] = val;
}

void rra(t_ps *ps, int print)
{
  rev_rotate_stack(&ps->a);
  if (print)
    ft_putstr("rra\n");
}

void rrb(t_ps *ps, int print)
{
  rev_rotate_stack(&ps->b);
  if (print)
    ft_putstr("rrb\n");
}

void rrr(t_ps *ps, int print)
{
  rev_rotate_stack(&ps->a);
  rev_rotate_stack(&ps->b);
  if (print)
    ft_putstr("rrr\n");
}
