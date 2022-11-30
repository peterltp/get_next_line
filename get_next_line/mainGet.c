#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
char	*get_next_line(int fd);
int	main()
{
	int	fd;
	char	*line;

	int	i;

	i = 0;
	fd = open ("tests/text.txt", O_RDONLY);
	while (i <= fd)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line)
			printf("it's there");
	//	printf ("%s ", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
