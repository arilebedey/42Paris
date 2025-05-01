#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 420
#endif

char  *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char  *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *s);
void  *ft_calloc(size_t count, size_t size);

#endif
