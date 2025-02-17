/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:07:28 by ainthana          #+#    #+#             */
/*   Updated: 2025/02/17 16:38:08 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	char	*line;
	char	*buffer;
	int		len_bytes;

	line = stash;
	len_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (len_bytes != 0 && ft_new_line(line) != 1)
	{
		len_bytes = read(fd, buffer, BUFFER_SIZE);
		if (len_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len_bytes] = '\0';
		line = ft_strjoin(line, buffer, len_bytes);
	}
	free(buffer);
	return (line);
}

char	*read_static(char *line)
{
	char	*stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line && line[i] != '\n' && line[i])
		i++;
	if (line[i] && line[i + 1] && line[i] == '\n')
	{
		i++;
		stash = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
		if (!stash)
			return (NULL);
		while (line[i])
		{
			stash[j++] = line[i];
			line[i++] = '\0';
		}
		stash[j] = '\0';
		return (stash);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, stash);
	if (!line)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = read_static(line);
	return (line);
}

// int	main()
// {
// 	char	*str = NULL;
// 	int			fd;
// 	size_t		i;

// 	i = 0;
// 	fd = open("bible.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// }
