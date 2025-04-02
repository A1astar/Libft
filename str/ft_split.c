/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:57:26 by alacroix          #+#    #+#             */
/*   Updated: 2025/04/02 13:38:37 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_freeme(char **tab, int nb)
// {
// 	int	i;

// 	i = 0;
// 	while (i < nb)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free (tab);
// }

// static int	ft_put_word(char **dest, char const *src, char c, int start)
// {
// 	int		end;
// 	char	*tab;
// 	int		i;

// 	i = 0;
// 	end = 0;
// 	tab = NULL;
// 	while (src[start] == c)
// 		start++;
// 	while (src[start + end] != c && src[start + end] != '\0')
// 		end++;
// 	tab = (char *)malloc((end + 1) * sizeof(char));
// 	if (tab == NULL)
// 		return (-1);
// 	tab[0] = '\0';
// 	while (src[start] != c && src[start] != '\0')
// 	{
// 		tab[i] = src[start];
// 		start++;
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	*dest = tab;
// 	return (start);
// }

// static int	ft_split_pt2(char **tab, char const *s, char c, int words)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < words)
// 	{
// 		j = ft_put_word(&tab[i], s, c, j);
// 		if (j == -1)
// 		{
// 			ft_freeme(tab, i);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// static int	ft_count_words(char const *str, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		words;

// 	if (s == NULL)
// 		return (NULL);
// 	tab = NULL;
// 	words = ft_count_words(s, c);
// 	tab = (char **) malloc ((words + 1) * sizeof(char *));
// 	if (tab == NULL)
// 		return (NULL);
// 	if (ft_split_pt2(tab, s, c, words) == -1)
// 	{
// 		free(tab);
// 		return (NULL);
// 	}
// 	tab[words] = NULL;
// 	return (tab);
// }

// static int	ft_split_pt2(char **tab, char const *s, char c, int words)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < words)
// 	{
// 		j = ft_put_word(&tab[i], s, c, j);
// 		if (j == -1)
// 		{
// 			ft_freeme(tab, i);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static char *put_word(char const *str, char const *sep_set, size_t *index)
{
	char 		*copy;
	size_t		word_len;;

	word_len = 0;
	copy = NULL;
	while(str[*index] && is_separator(str[*index], sep_set))
		(*index)++;
	while(str[*index + word_len] && !is_separator(str[*index + word_len], sep_set))
		word_len++;
	copy = ft_strndup(&str[*index], word_len);
	if (!copy)
		return (NULL);
	*index += word_len;
	return (copy);
}

static bool is_separator(char c, char const *sep_set)
{
	while (*sep_set)
	{
		if (*sep_set == c)
			return (true);
		sep_set++;
	}
	return (false);
}

static int	words_count(char const *str, char const *sep_set)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while(*str && is_separator(*str, sep_set))
			str++;
		if(*str && !is_separator(*str, sep_set))
		{
			count++;
			while(*str && !is_separator(*str, sep_set))
				str++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char const *sep_set)
{
	char	**tab;
	size_t	words;
	size_t	tab_i;
	size_t	str_i;

	if (!str)
		return (NULL);
	tab_i = 0;
	str_i = 0;
	words = words_count(str, sep_set);
	tab = ft_calloc((words + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while(tab_i < words)
	{
		tab[tab_i] = put_word(str, sep_set, &str_i);
		if(!tab[tab_i])
			return (ft_free_tab((void **)tab), NULL);
		tab_i++;
	}
	return (tab);
}
