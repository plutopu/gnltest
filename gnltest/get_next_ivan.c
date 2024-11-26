#include "get_next_line.h"
#include <stdio.h>
int ft_store_place_helper(char **store_place)
{
    if (*store_place == NULL)
    {
        *store_place = ft_calloc(1, 1);
        if (*store_place == NULL)
            return (1);
        return (0);
    }
    return (0);
}
char    *ft_store_place(int fd, char *store_place)
{
    char    *store_holder;
    char    *temp;
    int     read_bytes;
    if (ft_store_place_helper(&store_place))
        return (NULL);
    store_holder = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (store_holder == NULL)
        return (ft_free(&store_place), NULL);
    read_bytes = 1;
    while (read_bytes > 0 && (ft_strchr(store_holder, '\n') == 0))
    {
        read_bytes = read(fd, store_holder, BUFFER_SIZE);
        if (read_bytes == -1)
            return (ft_free(&store_holder), ft_free(&store_place), NULL);
        store_holder[read_bytes] = 0;
        temp = ft_strjoin(store_place, store_holder);
        if (temp == NULL)
            return (ft_free(&store_holder), ft_free(&store_place), NULL);
        ft_free(&store_place);
        store_place = temp;
    }
    ft_free(&store_holder);
    return (store_place);
}
char    *ft_line_to_print(char *store_place)
{
    int     i;
    char    *line;
    i = 0;
    if (!store_place[i])
        return (NULL);
    while (store_place[i] != '\0' && store_place[i] != '\n')
        i++;
    if (store_place[i] == '\n')
        line = ft_calloc(i + 2, sizeof(char));
    else
        line = ft_calloc(i + 1, sizeof(char));
    if (line == NULL)
        return (NULL);
    i = 0;
    while (store_place[i] != '\0' && store_place[i] != '\n')
    {
        line[i] = store_place[i];
        i++;
    }
    if (store_place[i] != '\0' && store_place[i] == '\n')
        line[i++] = '\n';
    return (line);
}
char    *ft_update_store_place(char *store_place)
{
    char    *update_store;
    int     i;
    int     j;
    i = 0;
    while (store_place[i] != '\0' && store_place[i] != '\n')
        i++;
    if (!store_place[i])
        return (ft_free(&store_place), store_place = NULL, NULL);
    update_store = ft_calloc((ft_strlen(store_place) - i + 1), sizeof(char));
    if (update_store == NULL)
        return (ft_free(&store_place), NULL);
    j = 0;
    i += 1;
    while (store_place[i] != '\0')
        update_store[j++] = store_place[i++];
    ft_free(&store_place);
    return (update_store);
}
char    *get_next_line(int fd)
{
    static char *store_place;
    char        *line_to_print;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(store_place), store_place = NULL, NULL);
    store_place = ft_store_place(fd, store_place);
    if (!store_place)
        return (NULL);
    line_to_print = ft_line_to_print(store_place);
    if (!line_to_print)
        return (ft_free(&store_place), NULL);
    store_place = ft_update_store_place(store_place);
    return (line_to_print);
}