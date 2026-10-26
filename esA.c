#include <stdio.h> // printf
#include <unistd.h> // getpid

int main()
{
    printf("\nAvvio del processo con pid=%d\n", getpid());
}

