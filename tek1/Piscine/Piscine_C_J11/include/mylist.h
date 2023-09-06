/*
** mylist.h for mylist in /home/baris_f/rendu/Piscine_C_J11
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 12 09:46:01 2015 Florent Baris
** Last update Tue Oct 13 19:21:42 2015 Florent Baris
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list
{
  void		*data;
  struct s_list	*next;
} t_list;

#endif /* !MYLIST_H_ */
