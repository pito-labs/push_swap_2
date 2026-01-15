/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 16:48:15 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
  int *data;
  int head;
  int size;
  int capacity;
  char id;
} t_stack;

typedef struct s_ps {
  t_stack a;
  t_stack b;
} t_ps;

/* ops_swap.c */
void sa(t_ps *ps, int print);
void sb(t_ps *ps, int print);
void ss(t_ps *ps, int print);

/* ops_push.c */
void pa(t_ps *ps, int print);
void pb(t_ps *ps, int print);

/* ops_rotate.c */
void ra(t_ps *ps, int print);
void rb(t_ps *ps, int print);
void rr(t_ps *ps, int print);

/* ops_rev_rotate.c */
void rra(t_ps *ps, int print);
void rrb(t_ps *ps, int print);
void rrr(t_ps *ps, int print);

/* stack_init.c */
int stack_init(t_stack *stack, int capacity, char id);
void stack_free(t_stack *stack);
int ps_init(t_ps *ps, int capacity);
void ps_free(t_ps *ps);

/* utils.c */
void ft_putstr(const char *s);
void error_exit(void);
long ft_exit_atoi(const char *str);
int is_sorted(t_stack *s);

/* sort.c */
void sort(t_ps *ps);

/* compress.c */
int *compress_args(int *raw, int n);

#endif
