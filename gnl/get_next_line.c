/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:41:36 by lelanglo          #+#    #+#             */
/*   Updated: 2024/10/16 11:54:29 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd)
{
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	ssize_t i;
	char *line;

	i = 0;
	line = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break;
	}
	while (buffer[i] != '\n')
	{
		line = ft_strjoin(line ,buffer);
	}
	return line;
}
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
    	perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
	}
	char *result = get_next_line(fd);
	printf("%s",result);
}