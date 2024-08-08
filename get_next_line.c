#include "get_next_line.h"

char	*ft_free_and_add(char *s_buffer, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(s_buffer, buffer);
	free(s_buffer);
	return (tmp);
}

char	*ft_read_file(int fd, char *s_buffer)
{
	char	*buffer;
	int		r;

	if (!s_buffer)
		s_buffer = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = (int)read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		s_buffer = ft_free_and_add(s_buffer, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (s_buffer);
}

char	*ft_add_clean(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer[0])
		return (NULL);
	line = ft_calloc(sizeof(char), ft_strlen(buffer, '\n') + 2);
	if (!line)
		return (NULL);
	line[ft_strlen(buffer, '\n') + 1] = '\0';
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (line);
}

char	*ft_re_buffer(char *buffer)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = ft_strlen(buffer, '\n');
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), ft_strlen(buffer, '\0') - i + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
	{
		tmp[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_add_clean(buffer);
	buffer = ft_re_buffer(buffer);
	return (line);
}
