/* fork04.c
 * Creazione di un processo figlio.
 * Dimostrazione dell'ereditarietà delle variabili e del recupero dei PID (getpid, getppid).
 */

#include <stdio.h>  // printf
#include <unistd.h> // getpid, getppid, fork

int main() {
    int op1 = 10;
    int op2 = 20;
    int ris;

    printf("[INIZIO] Esiste solo il processo padre, il padre del padre e' la shell\n");
    printf("[INIZIO] Prima della fork pid processo = %d, pid padre = %d\n", getpid(), getppid());

    int pid = fork();

    if (pid > 0) {
        /* Codice del Padre */
        ris = op1 * op2;
        printf("[Padre]  pid = %d, pid padre = %d, pid figlio = %d\n", getpid(), getppid(), pid);
        printf("[Padre]  Il risultato della moltiplicazione di op1*op2 = %d\n", ris);
        printf("[FINE]   Termine del processo con pid = %d, ris = %d, padre = %d\n", getpid(), ris, getppid());
    } 
    else if (pid == 0) {
        /* Codice del Figlio */
        ris = op1 + op2;
        printf("[Figlio] Il risultato della somma di op1+op2 = %d\n", ris);
        printf("[Figlio] pid = %d, pid del processo padre = %d\n", getpid(), getppid());
        printf("[FINE]   Termine del processo con pid = %d, ris = %d, padre = %d\n", getpid(), ris, getppid());
    } 
    else {
        printf("Creazione del processo figlio fallita!\n");
    }

    return 0;
}
