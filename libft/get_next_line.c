/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:03:09 by alibaba           #+#    #+#             */
/*   Updated: 2024/07/08 15:32:22 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(int fd, char *left_src, char *buff)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
			return (free(left_src), NULL);
		else if (b_read == 0)
			break ;
		buff[b_read] = '\0';
		if (!left_src)
			left_src = ft_strdup("");
		temp = left_src;
		if (temp != NULL && buff != NULL)
			left_src = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (left_src);
}

static char	*set_line(char *line)
{
	char	*left_src;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	left_src = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_src == 0)
	{
		free(left_src);
		left_src = NULL;
	}
	line[i + 1] = '\0';
	return (left_src);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*left_src = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_src);
		left_src = NULL;
		return (NULL);
	}
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = fill(fd, left_src, buff);
	free(buff);
	buff = NULL;
	if (!line)
	{
		left_src = NULL;
		return (NULL);
	}
	left_src = set_line(line);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

void	read_file(const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("ligne: %s\n", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	read_file("test.txt");
	read_file("test2.txt");
	read_file("test3.txt");
	read_file("test4.txt");
} */
