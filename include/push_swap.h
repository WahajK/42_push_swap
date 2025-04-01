/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 02:13:10 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:16:34 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

int		check_dupes(t_list **a, char **arr);
int		check_error(char *arr[]);
int		ft_nan(char *num);
int		is_sorted(t_list **a);
void	sx(t_node **a, char ch, bool flag);
void	ss(t_node **a, t_node **b);
void	px(t_list **x, t_list **swap, char ch);
void	rx(t_list **x, char ch, bool flag);
void	rr(t_list **a, t_list **b);
void	rrx(t_list **x, char ch, bool flag);
void	rrr(t_list **a, t_list **b);
void	target_to_top(t_list **a, t_node *target, char stack);
void	move_b_to_a(t_list **a, t_list **b);
void	min_to_top(t_list **a);
void	calculate_cost_a(t_node *a, t_node *b);
void	set_target_a(t_node *a, t_node *b);
void	set_cheapest(t_node *head);
void	init_nodes_a(t_list **a, t_list **b);
void	rev_rr_both(t_list **a, t_list **b, t_node *cheapest);
void	move_a_to_b(t_list **a, t_list **b);
void	set_target_b(t_node *a, t_node *b);
void	init_nodes_b(t_list **a, t_list **b);
void	destructor(char **arr);
void	free_stack(t_list **a);
void	set_index_median(t_node *head);
void	rr_both(t_list **a, t_list **b, t_node *cheapest);
t_node	*get_cheapest(t_node *head);
t_node	*find_min(t_node *head);
t_node	*find_max(t_node *head);
char	**parse_input(int argc, char *argv[]);
#endif