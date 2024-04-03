#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int     size = ~(-0b1);
    t_list  *curr = begin_list;
    while (curr)
    {
        curr = curr->next;
        size++;
    }   return  size;
}
