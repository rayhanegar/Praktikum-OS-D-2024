#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char c[42];

    int fd1 = open("sample.txt", O_RDONLY, 0);
    // int fd2 = open("sample2.txt", O_RDONLY, 0);

    read(fd1, &c, 42);
    // read(fd2, &c, 3);

    for (int i = 0; i < sizeof(c); i++)
    {
        printf("%c ", c[i]);
    }
    printf("\n");

    exit(0);
}