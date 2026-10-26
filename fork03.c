/* fork03.c 
 * Creazione di un processo figlio.
 * All'interno del blocco if i processi padre e figlio eseguono codice differente.
 * Perché la fork restituisce 0 al codice del processo figlio e
 * un numero positivo al processo padre (corrisponde al PID del figlio).
 */

#include <stdio.h>  // printf
#include <unistd.h> // getpid, fork

int main() {
    printf("Codice eseguito padre! (pid: %d)\n", getpid());
    
    int pid = fork(); // viene creato il processo figlio

    if (pid == 0) {
        /* codice figlio */
        printf("Sono il figlio! (pid: %d) \n", getpid());
    } else if (pid > 0) {
        /* codice padre */
        printf("Sono il padre! (pid: %d)\n", getpid());
    } else { // pid < 0
        printf("Creazione del processo figlio fallita!\n");
    }

    // Se vogliamo differenziare il comportamento dei processi dobbiamo sfruttare il blocco if.
    // Il codice seguente viene eseguito da entrambi i processi.
    printf("Codice comune a padre e figlio! (pid: %d) \n", getpid());
    
    return 0;
}
