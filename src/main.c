/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:33:52 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int parse_input(int argc, char **argv, int **out_vals)
{
  int i;
  int *vals;

  vals = (int *)malloc(sizeof(int) * (argc - 1));
  if (!vals)
    return (0);
  i = 0;
  while (i < argc - 1) 
  {
    vals[i] = ft_exit_atoi(argv[i + 1]);
    i++;
  }
  *out_vals = vals;
  return (argc - 1);
}

static void load_stack(t_ps *ps, int *ranks, int n)
{
  int i;

  i = 0;
  while (i < n) 
  {
    ps->a.data[i] = ranks[i];
    i++;
  }
  ps->a.head = 0;
  ps->a.size = n;
  ps->b.head = 0;
  ps->b.size = 0;
}

static int clean_exit(int *arr, int ret)
{
  free(arr);
  return (ret);
}

int main(int argc, char **argv)
{
  t_ps ps;
  int *vals;
  int *ranks;
  int n;

  if (argc < 2)
    return (0);
  n = parse_input(argc, argv, &vals);
  if (!vals)
    return (1);
  ranks = compress_args(vals, n);
  free(vals);
  if (!ranks)
    error_exit();
  if (!ps_init(&ps, n))
    return (clean_exit(ranks, 1));
  load_stack(&ps, ranks, n);
  free(ranks);
  sort(&ps);
  ps_free(&ps);
  return (0);
}
