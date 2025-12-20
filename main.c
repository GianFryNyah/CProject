#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice = 0;
    printf("\nMenu Principale:\n");
    printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n");

    do{
        printf("Seleziona una delle opzioni del menu [1-2]: ");

        char buff[2];
        int success;
        char konamicode[] = "wwssadadba ";
        int len = sizeof(konamicode) / sizeof(konamicode[0]);
        

        /*do// INPUT HANDLER (strtol())
        {
            if(!fgets(buff, 2, stdin)){
                return 1;
            }
            char *endptr;
            choice = strtol(buff, &endptr, 10);
            if(endptr == buff){
                success = 0;
            }
            else if(*endptr && *endptr != '\n'){
                success = 0;
            }
            else{
                success = 1;
            }
        } while (!success);*/

        scanf("%d", &choice);

        switch (choice){
            case 1:
                //Crea un nuovo salvataggio
                //Iniziera' una nuova partita dove all’avvio verra' creato l’eroe della storia, che iniziera' con
                //20 punti vita, 0 monete, 0 oggetti, 0 missioni completate.
                //Vedi la Sezione 3 per lo svolgimento e le regole del gioco.
                break;
            case 2:
                //mostra i salvataggi da poter caricare
                break;
            case 3:
                //trucchi
                //accessibile con Konami's code
                break;
            default:
                break;
        }
    }while(choice != 0);
}