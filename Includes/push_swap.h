#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Inclusion de la bibliothèque libft
# include "../Libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*target_node;
	int				index;
	int				targ_index;
	int				lst_size;
	int				median;
	int				med_index;
	int				targ_med_index;
	int				is_o_med;
	int				push_cost;
	int rank; // New field for optimization
}					t_stack;

// Original functions
int					lst_print(t_stack *head);
t_stack				*lstnew(int content);
void				lstadd_front(t_stack **lst, t_stack *new);
t_stack				*lstlast(t_stack *lst);
void				lstadd_back(t_stack **lst, t_stack *new);
int					lst_size(t_stack *head);
int					pushTo(t_stack **head_from, t_stack **head_to);
int					rotate(t_stack **head_to_rotate);
int					revers_rotate(t_stack **head_to_rotate);
int					swap(t_stack **head_to_swap);
void				do_pa(t_stack **head_a, t_stack **head_b);
void				do_pb(t_stack **head_a, t_stack **head_b);
void				do_sa(t_stack **head_a);
void				do_sb(t_stack **head_b);
void				do_ss(t_stack **head_a, t_stack **head_b);
void				do_ra(t_stack **head_a);
void				do_rb(t_stack **head_b);
void				do_rr(t_stack **head_a, t_stack **head_b);
void				do_rra(t_stack **head_a);
void				do_rrb(t_stack **head_b);
void				do_rrr(t_stack **head_a, t_stack **head_b);
int					is_List_In_Order(t_stack *HeadofList);
t_stack				*Find_Highest(t_stack *head_to_find);
int					mini_sort(t_stack **head_to_sort);
t_stack				*find_smallest(t_stack *head_to_find);
void				set_target_node(t_stack *head_a, t_stack *head_b);
void				set_index(t_stack *head);
void				set_target_index(t_stack *head);
void				set_median(t_stack *head);
void				set_index_median(t_stack *head);
void				set_targ_med(t_stack *head);
void				set_push_cost(t_stack *head_a, t_stack *head_b);
t_stack				*find_cheapest(t_stack *head_b);
void				set_node(t_stack *head_a, t_stack *head_b);
void				move_node(t_stack *cheapest, t_stack **head_b,
						t_stack **head_a);
void				print_all_data(t_stack *head);
void				print_debug(t_stack *head);
void				push_swap(t_stack **head_a, t_stack **head_b);
int					check_arg(t_stack *head_a);
void				free_stack(t_stack **head);
int 				find_best_chunk_element(t_stack *head_a, int chunk_start, int chunk_end);
void				optimized_push_swap(t_stack **head_a, t_stack **head_b);
int					get_chunk_count(int size);
void				push_in_chunks(t_stack **head_a, t_stack **head_b);
t_stack				*find_best_element(t_stack *head, int start_rank,
						int end_rank);
void				optimized_push_cost(t_stack *head_a, t_stack *head_b);
void				assign_ranks(t_stack *head);
void				move_to_top(t_stack **stack, int pos, int size,
						int is_stack_a);
int 				get_rotate_cost(int pos, int size);
void 				final_positioning(t_stack *cheapest, t_stack **head_a, t_stack **head_b);
void 				calculate_move_costs(t_stack *head_a, t_stack *head_b, int *costs);
void 				execute_move(t_stack **head_a, t_stack **head_b, int pos_b);
void 				push_chunk_to_b(t_stack **head_a, t_stack **head_b, int chunk_start, int chunk_end);
int 				get_element_position(t_stack *stack, int value);
#endif