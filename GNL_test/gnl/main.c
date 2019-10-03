#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int i;
    int fd;
    char *line;
    
    if (argc == 1)
    {
        return (0);
    }
    argv++;
    while (*argv)
    {
        fd = open(*argv++, O_RDONLY);
        while ((i = get_next_line(fd, &line)) > 0)
        {
            printf("->:%s\n", line);
            ft_strdel(&line);
        }
        printf("%d\n", i);
    }
    return (0);
}