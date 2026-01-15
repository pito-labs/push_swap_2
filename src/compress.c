/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:34:04 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_int_tab(int *tab, int size)
{
  int i;
  int j;
  int tmp;

  i = 0;
  while (i < size) 
  {
    j = i + 1;
    while (j < size) {
      if (tab[i] > tab[j]) 
      {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
      }
      j++;
    }
    i++;
  }
}

static int get_rank(int val, int *sorted, int n)
{
  int l;
  int r;
  int mid;

  l = 0;
  r = n - 1;
  while (l <= r) 
  {
    mid = l + (r - l) / 2;
    if (sorted[mid] == val)
      return (mid);
    if (sorted[mid] < val)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return (-1);
}

static int *free_and_ret_null(int *a, int *b)
{
  if (a)
    free(a);
  if (b)
    free(b);
  return (NULL);
}

int *compress_args(int *raw, int n)
{
  int *sorted;
  int *ranks;
  int i;

  sorted = (int *)malloc(sizeof(int) * n);
  ranks = (int *)malloc(sizeof(int) * n);
  if (!sorted || !ranks)
    return (free_and_ret_null(sorted, ranks));
  i = -1;
  while (++i < n)
    sorted[i] = raw[i];
  ft_sort_int_tab(sorted, n);
  i = -1;
  while (++i < n) 
  {
    if (i > 0 && sorted[i] == sorted[i - 1])
      return (free_and_ret_null(sorted, ranks));
    ranks[i] = get_rank(raw[i], sorted, n);
  }
  free(sorted);
  return (ranks);
}
