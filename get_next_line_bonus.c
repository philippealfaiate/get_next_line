/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:55:17 by phialfai          #+#    #+#             */
/*   Updated: 2023/01/02 16:45:32 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * 
*/
char	*get_next_line(int fd)
{
	char			*line;
	int				readed_bytes;
	static char		buffer[1024][BUFFER_SIZE];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			readed_bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (readed_bytes == -1)
				return (free(line), NULL);
			if (readed_bytes == 0)
				return (line);
		}
		line = ft_new_line(line, buffer[fd]);
		ft_clean_buffer(buffer[fd]);
		if (line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	return (line);
}
