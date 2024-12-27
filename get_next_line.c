/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:07:28 by ainthana          #+#    #+#             */
/*   Updated: 2024/12/27 20:26:17 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *stash)
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
			return (NULL);
			free(buffer);
		}
		buffer[len_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*read_static(char *line)
{
	char	*stash;
	size_t	i;
	size_t	j;
	size_t	len_line;
	
	i = 0;
	j = 0;
	while (line && line[i] != '\n' && line[i])
		i++;
	if (line[i])
		i++;
	stash = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!stash)
		return (NULL);
	while (line[i])
	{
		stash[j] = line[i + j];
		line[i + j] = '\0';
		j++;
	}
	stash[j] = '\0';
	return (stash);		
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	size_t		i;
	
	i = 0;
	line = read_line(fd, stash);
	stash = read_static(line);
	return (line);
}

int	main()
{
	char	*str = NULL;
	int	fd;

	fd = open("file1.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}