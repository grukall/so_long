/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:29:44 by seungule          #+#    #+#             */
/*   Updated: 2023/05/21 21:25:47 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_this(char **temp, char **temp_sub)
{
	free(*temp);
	free(*temp_sub);
}

int	check_buffer(char **buffer, char **result, char **backup, int fd)
{
	ssize_t	size;
	char	*temp;
	int		end_n;
	char	*temp_sub;
	int		sub_int;

	while (1)
	{
		size = read(fd, *buffer, BUFFER_SIZE);
		if (size <= 0)
			return (size);
		end_n = gnl_strlen(*buffer, '\n');
		sub_int = size;
		if (end_n != -1 && size != end_n)
			*backup = gnl_substr(*buffer, end_n, size - end_n);
		if (end_n != -1)
			sub_int = end_n;
		temp = *result;
		temp_sub = gnl_substr(*buffer, 0, sub_int);
		*result = gnl_strjoin(temp, temp_sub);
		free_this(&temp, &temp_sub);
		if (end_n != -1 || size < BUFFER_SIZE)
			break ;
	}
	return (1);
}

int	check_result(char **result, char **backup)
{
	int		end_n;
	int		end_0;
	char	*temp;

	if (!*result || !**result)
		return (1);
	end_n = gnl_strlen(*result, '\n');
	end_0 = gnl_strlen(*result, '\0');
	if (end_n != -1 && end_n <= end_0)
	{
		temp = *result;
		*backup = gnl_substr(temp, end_n, BUFFER_SIZE);
		*result = gnl_substr(temp, 0, end_n);
		free(temp);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*buffer;
	static char	*backup;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	result = gnl_strjoin(NULL, backup);
	free(backup);
	backup = NULL;
	if (!(check_result(&result, &backup)))
	{
		free(buffer);
		return (result);
	}
	if (check_buffer(&buffer, &result, &backup, fd) == -1 || result == NULL)
	{
		free(result);
		result = NULL;
	}
	free(buffer);
	return (result);
}
