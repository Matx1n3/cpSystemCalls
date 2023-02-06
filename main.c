#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char *argv[])
{
	char buf;
	int fd_one, fd_two;

    //  if argc != 3 reject
    if (argc != 3){
        printf("syntax: copySC fileFrom fileTo\n");
        return;
    }

	fd_one = open(argv[1], O_RDONLY);

    //Check that the first file can be opened
	if (fd_one == -1)
	{
		printf("Error opening first_file\n");
		close(fd_one);
		return;
	}

    //  Open the second file
	fd_two = open(argv[2],O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    //  Copy
	while(read(fd_one, &buf, 1))
	{
		write(fd_two, &buf, 1);
	}

    //  Operation successful
	printf("Successful copy\n");

    //  Close files
	close(fd_one);
	close(fd_two);
}