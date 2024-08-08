#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// get_next_line.c
char	*ft_free_and_add(char *s_buffer, char *buffer);
char	*ft_read_file(int fd, char *s_buffer);
char	*ft_add_clean(char *buffer);
char	*ft_re_buffer(char *buffer);
char	*get_next_line(int fd);

// get_next_line_utils.c
size_t	ft_strchr(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str, char c);

#endif