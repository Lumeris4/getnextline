/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:41:36 by lelanglo          #+#    #+#             */
/*   Updated: 2024/10/16 16:25:47 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	static ssize_t i;
	char *line;

	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	while (buffer[i] != '\n')
	{
		i++;
	}
	line = malloc(sizeof(char) * i);
	line = ft_strjoin(line ,buffer , i);
	return (line);
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
	char *result = get_next_line(fd);
	printf("%s\n",result);
	free(result);
	close(fd);
}
