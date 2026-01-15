/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 17:32:37 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(const char *s)
{
  int i;

  i = 0;
  if (!s)
    return;
  while (s[i])
    i++;
  write(1, s, i);
}

void error_exit(void)
{
  write(2, "Error\n", 6);
  exit(1);
}

static int ft_check_sign(const char *str, int *i)
{
  int sign;

  sign = 1;
  if (str[*i] == '-' || str[*i] == '+') 
  {
    if (str[*i] == '-')
      sign = -1;
    (*i)++;
  }
  return (sign);
}

long ft_exit_atoi(const char *str)
{
  long res;
  int sign;
  int i;

  res = 0;
  i = 0;
  while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  sign = ft_check_sign(str, &i);
  if (!str[i])
    error_exit();
  while (str[i]) 
  {
    if (str[i] < '0' || str[i] > '9')
      error_exit();
    res = res * 10 + (str[i] - '0');
    i++;
  }
  return (res * sign);
}

int is_sorted(t_stack *s)
{
  int i;
  int prev;
  int curr;

  if (s->size < 2)
    return (1);
  i = 0;
  prev = s->data[s->head];
  while (i < s->size - 1) 
  {
    curr = s->data[(s->head + i + 1) % s->capacity];
    if (prev > curr)
      return (0);
    prev = curr;
    i++;
  }
  return (1);
}
