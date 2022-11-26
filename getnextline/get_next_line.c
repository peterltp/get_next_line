/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:55:28 by ple-              #+#    #+#             */
/*   Updated: 2022/11/26 16:23:26 by ple-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line   = NULL;
	stash  = NULL;
	// read from fd and save it in stash
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	//2. extract from stash to line 
	extract_line(stash, &line);
	//3. clean up stash 
	return (line);
}
