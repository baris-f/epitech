/*
** request.c for request in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Sun May 21 23:02:24 2017 baris_f
** Last update Sun May 21 23:03:07 2017 baris_f
*/

#include "function.h"

t_func cmdList[10] = {
  {"USER", &user},
  {"PASS", &pass},
  {"QUIT", &quit},
  {"NOOP", &noop},
  {"PWD", &pwd},
  {"CWD", &cwd},
  {"CDUP", &cdup},
  {"DELE", &delete},
  {"HELP", &help},
  {NULL, 0},
};

void request(struct_client *clt){
  int i = -1;
  int cmd = FALSE;
  xread(clt);
  while (cmdList[++i].cmd != NULL)
    if (strncmp(cmdList[i].cmd, clt->buff, strlen(cmdList[i].cmd)) == 0){
      cmd = TRUE;
      cmdList[i].fct(clt);
    }
  if (cmd == FALSE)
    xwrite(clt, "502 Command not implemented\r\n");
}
