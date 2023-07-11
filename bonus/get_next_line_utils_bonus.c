/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:39:30 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:23:22 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

char	*true_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{	
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	new_s = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_s[i + j] = (char)s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	return (new_s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int 	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
