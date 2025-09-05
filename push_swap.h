/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:59:59 by paulo             #+#    #+#             */
/*   Updated: 2025/09/05 09:56:28 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;


char		**split_str_array(int argc, char **argv, char sep);
void		add_node(t_node **root, int num);
void		print_linked_list(t_node **root);
void		ft_free_array(char **split_list);
long int	ft_simple_atoi(char *str);
void		init_stack_a(char **split_list, t_node **root_a);
void		ft_free_list(t_node **root);
int			is_valid_num(char *str);
int			verify_dup(t_node **root, int num);

#endif