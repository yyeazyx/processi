/* esercizio_b.c
 * Esercizio b - Slide 42
 * Il padre calcola l'area del rettangolo, il figlio calcola il perimetro.
 */

#include <stdio.h>  // printf
#include <unistd.h> // getpid, fork

int main() {
    // Il processo padre inizializza le tre variabili intere
    int base = 8;
    int altezza = 5;
    int risultato = 0;

    printf("[INIZIO] Processo padre avviato (PID: %d)\n", getpid());

    // Creazione del processo figlio
    int pid = fork();

    if (pid == 0) {
        /* Processo FIGLIO: calcola e stampa il PERIMETRO */
        risultato = 2 * (base + altezza);
        printf("[Figlio - PID: %d, PPID: %d] Perimetro del rettangolo (2 * (%d + %d)) = %d\n", 
               getpid(), getppid(), base, altezza, risultato);
    } 
    else if (pid > 0) {
        /* Processo PADRE: calcola e stampa l'AREA */
        risultato = base * altezza;
        printf("[Padre  - PID: %d, PID figlio: %d] Area del rettangolo (%d * %d) = %d\n", 
               getpid(), pid, base, altezza, risultato);
    } 
    else {
        // Gestione di un eventuale errore nella fork
        printf("Errore nella creazione del processo figlio!\n");
    }

    return 0;
}
