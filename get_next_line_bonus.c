#include "get_next_line_bonus.h"

static int	get_line(int read_byte, char **read_line, char **line)
{
	char	*temp;

	if (read_byte == 0 && *read_line == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (ft_strchr(*read_line, '\n'))
	{
		*line = ft_substr(*read_line, 0, ft_strchr(*read_line, '\n') \
														- *read_line);
		temp = ft_strdup(*read_line + (ft_strlen(*line) + 1));
		if (!temp)
			return (-1);
		free(*read_line);
		*read_line = temp;
	}
	else
	{
		*line = ft_strdup(*read_line);
		free(*read_line);
		*read_line = NULL;
		return (0);
	}
	return (1);
}

static int	read_buffer(int fd, char *buffer, char **read_line, char **line)
{
	char	*temp;
	int		read_byte;

	read_byte = read(fd, buffer, BUFFER_SIZE);
	while (read_byte)
	{
		buffer[read_byte] = '\0';
		if (!read_line[fd])
			read_line[fd] = ft_strdup("");
		temp = ft_strjoin(read_line[fd], buffer);
		if (!temp)
			return (-1);
		free(read_line[fd]);
		read_line[fd] = temp;
		if (ft_strchr(read_line[fd], '\n'))
			break ;
		read_byte = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_byte < 0)
		return (-1);
	return (get_line(read_byte, &read_line[fd], line));
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*read_line[1024];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, 0, 0) < 0))
		return (-1);
	return (read_buffer(fd, buffer, &read_line[fd], line));
}
