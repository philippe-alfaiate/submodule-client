#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    char *s = NULL;
    const char *pipe_file = "/tmp/fifofile";

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <msg>\n", argv[0]);
        return 1;
    }
    s = argv[1]; 

    if ((fd = open(pipe_file, O_WRONLY)) < 0)
    {
        fprintf(stderr, "%s: failed to open FIFO %s\n", argv[0], pipe_file);
        return 1;
    }
    printf("%s: open successful\n", argv[0]);
    if (write(fd, s, strlen(s)) <= 0)
    {
        fprintf(stderr, "%s: failed to open FIFO %s\n", argv[0], pipe_file);
        return 1;
    }
    printf("%s: write successful\n", argv[0]);
    if (fd)
    {
        close(fd);
    }

    return 0;
}