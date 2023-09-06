/*
** kotalatchi.c for koalatchi in /home/baris_f/rendu/tek2/cpp_d01/ex07
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Wed Jan  4 21:01:20 2017 baris_f
** Last update Thu Jan  5 08:36:17 2017 baris_f
*/

#include <stdio.h>
#include <stdint.h>

int	prettyprint_message(uint32_t header, char const *content)
{
  int	error;

  error = 0;
  if ((header & 0xff000000) == 0x01000000)
    printf("Notification ");
  else if ((header & 0xff000000) == 0x02000000)
    printf("Request ");
  else if ((header & 0xff000000) == 0x04000000)
    printf("Error ");
  else
    error = 1;
  if (error == 0 && (header & 0xff0000) == 0x010000)
    {
      printf("Nutrition ");
      if ((header & 0xff000000) == 0x01000000)
	{
	  if ((header & 0xff) == 1)
	    printf("Eat");
	  else if ((header & 0xff) == 2)
	    printf("Defecate");
	  else
	    error = 1;
	}
      else if ((header & 0xff000000) == 0x02000000)
	{
	  if ((header & 0xff) == 1)
	    printf("Hungry");
	  else if ((header & 0xff) == 2)
	    printf("Thirsty");
	  else
	    error = 1;
	}
      else if ((header & 0xff000000) == 0x04000000)
	{
	  if ((header & 0xff) == 1)
	    printf("Indigestion");
	  else if ((header & 0xff) == 2)
	    printf("Starving");
	  else
	    error = 1;
	}
    }
  else if ((header & 0xff0000) == 0x020000)
    {
      printf("Entertainment ");
      if ((header & 0xff000000) == 0x01000000)
	{
	  if ((header & 0xff) == 1)
	    printf("Ball");
	  else if ((header & 0xff) == 2)
	    printf("Bite");
	  else
	    error = 1;
	}
      else if ((header & 0xff000000) == 0x02000000)
	{
	  if ((header & 0xff) == 1)
	    printf("NeedAffection");
	  else if ((header & 0xff) == 2)
	    printf("WannaPlay");
	  else if ((header & 0xff) == 3)
	    printf("Hug");
	  else
	    error = 1;
	}
      else if ((header & 0xff000000) == 0x04000000)
	    printf("Bored");
      else
	error = 1;
    }
  else if ((header & 0xff0000) == 0x040000)
    {
      printf("Education ");
      if ((header & 0xff000000) == 0x01000000)
	{
	  if ((header & 0xff) == 1)
	    printf("TeachCoding");
	  else if ((header & 0xff) == 2)
	    printf("BeAwesome");
	}
      else if ((header & 0xff000000) == 0x02000000)
	printf("FeelStupid");
      else if ((header & 0xff000000) == 0x04000000)
	printf("BrainDamage");
      else
	error = 1;
    }
  else
    error = 1;
  if (error == 1)
    {
      printf("Invalid message.\n");
      return (1);
    }
  if (content == NULL)
    printf("\n");
  else
    printf(" %s\n", content);
  return (0);
}
/*
int main (void)
{
   prettyprint_message(0x00C0FFEE, "Needed !");
   prettyprint_message(0x02010001, "\"Kreog !\"");
   prettyprint_message(0x01010001, "Eucalytpus");
   prettyprint_message(0x01010002 ,   "\"POO!\"");
   prettyprint_message(0x01010001, "Keytronic");
   prettyprint_message(0x04010001, NULL);
   prettyprint_message(0x02020001 , NULL);
   prettyprint_message(0x01040002 , NULL);
   prettyprint_message(0x01020002 , "\"KREOG!!!\"");
   prettyprint_message(0x01040001, "Brainfuck");
   prettyprint_message(0x04040001, "\"Dark Moon of the side...\"");
   return 0;
}*/
