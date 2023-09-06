#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1024)

char	*get_next_line(const int fd);
void	my_read(int fd, char *buf, size_t count);
void    my_memset(char *str, int size);
char    *my_realloc(char *str, int newsize);
int     my_memsetlencat(char *str, int size, int opt, char *src);

#endif /* READ_SIZE */
#endif /* !GET_NEXT_LINE_H_ */
