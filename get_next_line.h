/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:31:21 by phialfai          #+#    #+#             */
/*   Updated: 2023/01/02 16:31:54 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
void	ft_clean_buffer(char *buffer);
char	*ft_get_line(int fd, char *line);
size_t	ft_useful_bytes_to_nl(char *buffer);
char	*ft_new_line(char *line, char *buffer);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
