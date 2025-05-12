/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danoguer <danoguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:22:00 by danoguer          #+#    #+#             */
/*   Updated: 2025/05/10 13:37:02 by danoguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s) {
    size_t len = 0;
    while (s && *s++) // Iteración sin for
        len++;
    return len;
}

char	*ft_strchr(const char *s, int c) {
    if (!s)
        return NULL;
    while (*s) {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return (*s == c) ? (char *)s : NULL;
}

char	*ft_strdup(const char *s) {
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    if (!dup)
        return NULL;

    size_t i = 0;
    while (s[i]) { // Sin usar `for`
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char	*ft_strjoin(char *s1, char *s2) {
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *joined = malloc(len1 + len2 + 1);
    if (!joined)
        return NULL;

    size_t i = 0;
    while (s1 && s1[i]) { // Copia sin `for`
        joined[i] = s1[i];
        i++;
    }

    size_t j = 0;
    while (s2 && s2[j]) { // Copia sin `for`
        joined[i++] = s2[j++];
    }

    joined[i] = '\0';
    free(s1); // Liberación correcta de memoria
    return joined;
}