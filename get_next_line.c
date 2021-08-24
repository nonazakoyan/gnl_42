/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:28:09 by nozakoya          #+#    #+#             */
/*   Updated: 2021/07/27 20:33:11 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_result(int r, char **line, char **tmp)
{
	if (r < 0)
		return (-1);
	*line = get_before_str(*tmp);
	*tmp = del(*tmp);
	if (r == 0 && !*tmp)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				r;
	char			*buffer;
	static char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return (-1);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buffer[r] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (get_char(tmp, '\n') || get_char(tmp, '\0'))
			break ;
	}
	free(buffer);
	return (read_result(r, line, &tmp));
}

int main()
{
	int		fd;
	char	**line;
	int i = 0;
	fd = open("test.txt", O_RDONLY);
    while(i < 3)
	    {
            get_next_line(fd, line);
			printf("%s\n", *line);
            ++i;
		}
}
