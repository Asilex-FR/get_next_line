/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:07:28 by ainthana          #+#    #+#             */
/*   Updated: 2024/12/28 16:07:46 by ainthana         ###   ########.fr       */
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
	
	i = 0;
	j = 0;
	while (line && line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n' && line[i + 1])
		i++;
	stash = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!stash)
		return (NULL);
	while (line[i])
	{
		stash[j] = line[i];
		// line[i] = '\0';
		j++;
		i++;
	}
	stash[j] = '\0';
	return (stash);		
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = read_line(fd, stash);
	// printf("la ligne est : %s\n", line);
	stash = read_static(line);
	// printf("la stash est : %s\n", stash);
	return (line);
}

// int	main()
// {
// 	char	*str = NULL;
// 	int			fd;
// 	size_t		i;

// 	i = 0;
// 	fd = open("file1.txt", O_RDONLY);
// 	while (i < 2)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// }

// int	main(void)
// {
// 	char	*st;

// 	st = "salut\nyone";
// 	printf("%s\n",read_static(st));
// 	return (0);
// }