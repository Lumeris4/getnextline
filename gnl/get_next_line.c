/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:41:36 by lelanglo          #+#    #+#             */
/*   Updated: 2024/10/17 16:54:57 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_new_buffer(char *buffer, int index_line)
{
	char	*result;

	result = ft_substr(buffer, index_line + 1, ft_strlen(buffer) - index_line - 1);
	free(buffer);
	buffer = result;
}

char	*get_next_line(int fd)
{
	int				bytes_read;
	static char		*buffer = NULL;
	int				index_line;
	char			*line;
	char			second_buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index_line = newline((const char *)buffer);
	while (index_line == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, second_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		second_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, second_buffer);
	}
	if (index_line != -1)
	{
		line = ft_substr(buffer, 0, index_line + 1);
		ft_new_buffer(buffer, index_line);
		return (line);
	}
	if (bytes_read == 0 && buffer != NULL)
	{
		line = ft_substr(buffer, 0, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
		return (line);
	}
	return (NULL);
}


#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("text.text", O_RDONLY);
	if (fd == -1) {
		perror("Erreur lors de l'ouverture du fichier");
		exit(EXIT_FAILURE);
	}
	char *result;
	int i = 0;
	while (i < 5)
	{
		result = get_next_line(fd);
		printf("%s\n",result);
		i++;
	}
	free(result);
	close(fd);
}
