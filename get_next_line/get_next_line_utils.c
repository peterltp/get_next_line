/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:40 by ple-              #+#    #+#             */
/*   Updated: 2022/11/27 14:31:00 by ple-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i1;
	int		i2;
	size_t	s1_len;
	size_t	s2_len;

	i1 = 0;
	i2 = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *) malloc(s1_len + s2_len + 1);
	if (!s1 || !s2 || !new_string)
		return (0);
	while (s1[i1] != '\0')
	{
		new_string[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
		new_string[i1++] = s2[i2++];
	new_string[i1] = '\0';
	return (new_string);
}

