#ifndef DEQUE_H
# define DEQUE_H

# include "defines.h"

t_deque		*deque_init(size_t size);
void		dq_push_front(t_deque *dque, void *data);
void		dq_push_rear(t_deque *dque, void *data);
void		*dq_pop_front(t_deque *dque);
void		*dq_pop_rear(t_deque *dque);
void		*dq_peek_front(const t_deque *dque);
void		*dq_peek_rear(const t_deque *dque);
void		dq_free(const t_deque *dque);
void		dq_clear(t_deque *dque);

#endif