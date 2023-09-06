/*
** my_add_list_to_list.c for my_add_list_to_list in /home/baris_f/rendu/Piscine_C_J11/ex_09
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 17:25:56 2015 Florent Baris
** Last update Mon Oct 12 18:00:10 2015 Florent Baris
*/

int		my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	tmp;

  tmp = *begin1;
  while (tmp != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = begin2;
}
