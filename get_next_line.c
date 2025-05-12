/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:47:47 by danoguer          #+#    #+#             */
/*   Updated: 2025/05/10 13:46:13 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *stash);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);

char	*get_next_line(int fd) {
	static char *stash = NULL;
	char buffer[BUFFER_SIZE + 1];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, buffer, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);

	return (line);
}

char	*read_line(int fd, char *buffer, char *stash) {
	int bytes_read;

	while (!ft_strchr(stash, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) 
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	int i = 0;
	char *line;

	if (!stash || !*stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);

	i = 0;
	while (stash[i] && stash[i] != '\n') {
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';

	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int	i = 0;
	int	j = 0;
	char *new_stash;

	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i]) 
	{
		free(stash);
		return (NULL);
	}

	new_stash = malloc(ft_strlen(stash) - i);
	if (!new_stash)
		return (NULL);

	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];

	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}