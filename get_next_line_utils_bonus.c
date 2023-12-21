/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:35:17 by phialfai          #+#    #+#             */
/*   Updated: 2023/01/02 16:35:27 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * 
*/
size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * 
*/
size_t	ft_useful_bytes_to_nl(char *buffer)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < BUFFER_SIZE && buffer[bytes] != 10 && buffer[bytes] != '\0')
		bytes++;
	if (buffer[bytes] == 10)
		bytes++;
	return (bytes);
}

/**
 * 
*/
void	ft_clean_buffer(char *buffer)
{
	size_t	i;
	size_t	bytes;

	i = 0;
	bytes = ft_useful_bytes_to_nl(buffer);
	while (i < BUFFER_SIZE - bytes && buffer[i] != '\0')
	{
		buffer[i] = buffer[bytes + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

/**
 * 
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *) dest;
	csrc = (char *) src;
	i = 0;
	while (i < n)
	{
		*(cdest + i) = *(csrc + i);
		i++;
	}
	return (dest);
}

/**
 * 
*/
char	*ft_new_line(char *line, char *buffer)
{
	size_t	ubytes;
	size_t	line_len;
	char	*new_line;

	if (line == NULL && *buffer == '\0')
		return (NULL);
	new_line = NULL;
	line_len = ft_strlen(line);
	ubytes = ft_useful_bytes_to_nl(buffer);
	if (ubytes > 0 || line_len > 0)
	{
		line_len = ft_strlen(line);
		new_line = malloc(sizeof(char) * (line_len + ubytes + 1));
		if (new_line == NULL)
			return (NULL);
		if (line != NULL)
			ft_memcpy(new_line, line, line_len);
		ft_memcpy((new_line + line_len), buffer, ubytes);
		new_line[line_len + ubytes] = '\0';
	}
	free(line);
	return (new_line);
}
