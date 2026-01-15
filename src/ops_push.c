/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:33:30 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_to(t_stack *dst, t_stack *src)
{
  int val;

  if (src->size == 0)
    return;
  val = src->data[src->head];
  src->head = (src->head + 1) % src->capacity;
  src->size--;
  dst->head = (dst->head - 1 + dst->capacity) % dst->capacity;
  dst->data[dst->head] = val;
  dst->size++;
}

void pa(t_ps *ps, int print)
{
  push_to(&ps->a, &ps->b);
  if (print)
    ft_putstr("pa\n");
}

void pb(t_ps *ps, int print)
{
  push_to(&ps->b, &ps->a);
  if (print)
    ft_putstr("pb\n");
}
