/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:32:48 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(int n)
{
  int bits;

  bits = 0;
  while ((n >> bits) != 0)
    bits++;
  return (bits);
}

static void sort_bit(t_ps *ps, int bit, int size)
{
  int i;
  int val;

  i = 0;
  while (i < size) 
  {
    val = ps->a.data[ps->a.head];
    if (((val >> bit) & 1) == 1)
      ra(ps, 1);
    else
      pb(ps, 1);
    i++;
  }
}

void sort(t_ps *ps)
{
  int max_bits;
  int bit;

  if (is_sorted(&ps->a))
    return;
  max_bits = get_max_bits(ps->a.size - 1);
  bit = 0;
  while (bit < max_bits) 
  {
    sort_bit(ps, bit, ps->a.size);
    while (ps->b.size > 0)
      pa(ps, 1);
    bit++;
  }
}
