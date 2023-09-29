/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:29:30 by seungule          #+#    #+#             */
/*   Updated: 2023/09/29 22:00:47 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
char		*gnl_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *string, int c);
char		*ft_strdup(const char *src);
char		*gnl_substr(char const *s, unsigned int start, size_t len);
int			gnl_strlen(const char *str, int ch);

#endif
