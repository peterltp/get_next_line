/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:56:30 by ple-              #+#    #+#             */
/*   Updated: 2022/11/26 16:23:22 by ple-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buff;
	
	while (!found_new_line(*stash) && *readed_ptr != 0)
	{
		buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		*readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && *readed_ptr == 0) || *reader_ptr == -1)
		{
			free(buff);
			return 0;
		}
		buff[*readed_ptr] = '\0';
		add_stash(stash, buff, *readed_ptr);
		free(buff);
	}
}
/*looks for a newline character in the given linked list */
int	found_new_line()
{
	int	i;
	t_list	*current;

	if (!stash)
		return (0);
	current = ft_last_node;
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] = '\n')
			return (1);
		i++;
	}
	return (0);
}
/*return a pointer to the last node in stash */
t_list	*ft_last_node(t_list *stash)
{
	t_list	*current;

	currnet = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}
/*add the content of buffer to the end of stash */
void	add_stash(t_list **stash, char *buff, int readed)
{
	int	i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = malloc (sizeof (char) * (readed + 1));
	if (new_node->content == NULL)
		return (NULL);
	i = 0;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return (NULL);
	}
	last = ft_last_node(*stash);
	last->next = new_node;
}
/*extract all characters from stash and stores in out line. 
 * stopping after the first \n in encounters */
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return (NULL);
	generate_line(line, stash)



}
/*calculate th number of chars in the current line,
 * including the trailing \n if there is one, and allocates memory accordingly */
void	generate_line(char **line, t_list *stash)
{




}
