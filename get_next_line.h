/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:07:37 by ainthana          #+#    #+#             */
/*   Updated: 2024/12/27 20:09:18 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_new_line(char *str);

char	*get_next_line(int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif