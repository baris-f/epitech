#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef void(*t_fct)(char *);

void    print_normal(char *str);
void    print_reverse(char *str);
void    print_upper(char *str);
void    print_42(char *str);
void    do_action(t_action action, char *str);

#endif /* !FUNC_PTR_H_ */
