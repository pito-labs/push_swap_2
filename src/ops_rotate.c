/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:33:11 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_stack(t_stack *s)
{
  int val;
  int tail_idx;

  if (s->size < 2)
    return;
  val = s->data[s->head];
  tail_idx = (s->head + s->size) % s->capacity;
  s->data[tail_idx] = val;
  s->head = (s->head + 1) % s->capacity;
}

void ra(t_ps *ps, int print)
{
  rotate_stack(&ps->a);
  if (print)
    ft_putstr("ra\n");
}

void rb(t_ps *ps, int print)
{
  rotate_stack(&ps->b);
  if (print)
    ft_putstr("rb\n");
}

void rr(t_ps *ps, int print)
{
  rotate_stack(&ps->a);
  rotate_stack(&ps->b);
  if (print)
    ft_putstr("rr\n");
}
