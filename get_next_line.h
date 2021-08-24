/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:38:37 by nozakoya          #+#    #+#             */
/*   Updated: 2021/06/19 15:12:58 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include  <string.h>

int		read_result(int r, char **line, char **tmp);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		get_char(char *str, char c);
char	*get_before_str(char *buf);
char	*del(char *buf);
int		get_next_line(int fd, char **line);

#endif
