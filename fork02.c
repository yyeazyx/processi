#include <stdio.h>  // printf
#include <unistd.h> // getpid

int main()
{
    printf("\nAvvio del processo con pid=%d\n", getpid());
    fflush(stdout); // Forza la stampa a schermo immediata

    // Ciclo infinito per mantenere il processo attivo
    for(;;) {
        ;
    }

    return 0;
}
