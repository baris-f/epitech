/*
** log.c for log in /home/baris_f/rendu/tek2/cpp_d01/ex08
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 17:45:51 2017 baris_f
** Last update Thu Jan  5 08:50:57 2017 baris_f
*/

#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include "log.h"

enum	LogLevel	currentLogLevel = Error;
FILE *	fp;

enum	LogLevel	get_log_level(void)
{
  return (currentLogLevel);
}

enum	LogLevel	set_log_level(enum LogLevel level)
{
  if (level >= Error && level <= Debug)
    currentLogLevel = level;
  return (currentLogLevel);
}

int	set_log_file(char const* name)
{
  if (fp && fclose(fp) != 0)
    return (1);
  fp = fopen(name, "a");
  return (0);
}

int	close_log_file(void)
{
  if (fp && fclose(fp) != 0)
    return (1);
  fp = stderr;
  return (0);
}

int	log_to_stdout(void)
{
  if (fp && fclose(fp) != 0)
    return (1);
  fp = stdout;
  return (0);
}

int	log_to_stderr(void)
{
  if (fp && fclose(fp) != 0)
    return (1);
  fp = stderr;
  return (0);
}

void	log_msg(enum LogLevel curlvl, char const *fmt, ...)
{
  va_list	ap;
  time_t	tim;
  char		*s[] = {"Error", "Warning", "Notice", "Info", "Debug"};

  tim = time(NULL);
  va_start(ap, fmt);
  if (fp == NULL)
    fp = stderr;
  if (curlvl >= Error && curlvl <= Debug)
    {
      fprintf(fp, "%.24s [%s]", ctime(&tim), s[curlvl]);
      vfprintf(fp, fmt, ap);
    }
  if (curlvl <= currentLogLevel)
    {
      printf("%.24s [%s]", ctime(&tim), s[curlvl]);
      vprintf(fmt, ap);
    }
}
/*
int	main()
{
    set_log_file("out.log");
    set_log_level(Debug);
    log_msg (Debug, "This is debug\n") ;
    log_msg (42, " Thisshldner i n t e d \n" ) ;
    log_msg (Warning , " T h i s i s a wa rn ing \n" ) ;
    set_log_level( Warning ) ;
    log_msg (Info, " T h i s i s i n f o \n" ) ;
    log_msg (Error, "KREOG!\n") ;
    close_log_file() ;
    return (0);
    }
*/
