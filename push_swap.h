#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

//Swap (sa, sb, ss)
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

//Push (pa, pb, )
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

//Rotate (ra, rb, rr)
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

//Reverse rotate (rra, rrb, rrr)
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);

#endif