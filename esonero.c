#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void){

  //inserimento della stringa

  printf("inserisci la stringa: ");
  char stringa[256];
  fgets(stringa, 256, stdin);

  int controllo = 1;

  while(controllo){

    //inserimento opzione

    int opzione;
    printf("Quale operazione vuoi eseguire? ");
    scanf(" %d", &opzione);

    switch(opzione){
        case 1:
          printf("\nOpzione 1\n");
          printf("Verificare se la stringa è una palindroma\n\n");

          //nella prima opzione la stringa dovra essere adattata.

          char nuovaStringa[256];
          char stringInversa[256];
          int i = 0, j = 0, t = 0;

          for(i = 0; stringa[i]; i++){
              if(isalpha(stringa[i])){
                  nuovaStringa[j++] = tolower(stringa[i]);
              }
          }
          nuovaStringa[j] = '\0';

          //dopo aver adattato la stinga devo creare una stringa inversa

          int lunghezzaNuova = strlen(nuovaStringa);

          for(int a = lunghezzaNuova - 1 ; a >= 0; a--){
              stringInversa[t++] = nuovaStringa[a];
          }
          stringInversa[strlen(nuovaStringa)] = '\0';

          //dopo aver creato la stringa inversa li confronto per vedere se sono uguali

          if(strcmp(nuovaStringa, stringInversa) == 0){
              printf("La stringa è palindroma\n");
          }else{
              printf("Non è palindroma\n\n");
          }

          char scelta;
          printf("vuoi continuare s/n ?: ");
          scanf(" %c", &scelta);

          //printf("%c\n", scelta);

          if(scelta == 's'){
              controllo = 1;
          }else{
              controllo = 0;
          }

          break;
        case 2:
          printf("\nOpzione 2\n");
          printf("Verificare se la stringa è una pangramma\n\n");

          //nella prima opzione la stringa dovra essere adattata.

          char nuovaStringa2[256];
          int ii = 0, jj = 0, tt = 0;

          for(ii = 0; stringa[ii]; ii++){
              if(isalpha(stringa[ii])){
                  nuovaStringa2[jj++] = tolower(stringa[ii]);
              }
          }
          nuovaStringa2[jj] = '\0';

          //dopo aver adattato la stringa devo controllare se è un pangramma

          int valore[26] = {0}, conto = 0;

          for(tt = 0; nuovaStringa2[tt]; tt++){
              if(nuovaStringa2[tt] >= 'a' && nuovaStringa2[tt] <= 'z'){
                  conto += !valore[nuovaStringa2[tt] - 'a'];
                  valore[nuovaStringa2[tt] - 'a'] = 1;
              }
          }

          //verifico se la frase è un pangramma inglese

          if(conto == 26){
              printf("La stringa è pangramma\n");
          }else{
              printf("La stringa non è un pangramma\n");
          }

          char scelta2;
          printf("vuoi continuare s/n ?: ");
          scanf(" %c", &scelta2);

          //printf("%c\n", scelta);

          if(scelta2 == 's'){
              controllo = 1;
          }else{
              controllo = 0;
          }

          break;
        case 3:
          printf("\nOpzione 3\n");
          printf("Verranno scambiate due lettere a caso dalla stringa\n");

          char nuovaStringa3[256];
          int iii = 0, jjj = 0;

          for(iii = 0; stringa[iii]; iii++){
              if(isalpha(stringa[iii])){
                  nuovaStringa3[jjj++] = tolower(stringa[iii]);
              }
          }
          nuovaStringa3[jjj] = '\0';

          //printf("%s\n", nuovaStringa3);
          //dopo aver adattato la stringa adesso sostituisco due lettere casuali

          srand(time(NULL));

          int n1,n2;

          n1 = rand() % strlen(nuovaStringa3);
          n2 = rand() % strlen(nuovaStringa3);

          char l1,l2;

          l1 = nuovaStringa3[n1];
          l2 = nuovaStringa3[n2];

          nuovaStringa3[n1] = l2;
          nuovaStringa3[n2] = l1;

          printf("la nuova stringa : %s\n", nuovaStringa3);
          printf("La nuova stringa lo abbiamo ottenuto sostuendo le lettere numero: %d e %d\n", n1, n2);

          char scelta3;
          printf("vuoi continuare s/n ?: ");
          scanf(" %c", &scelta3);

          //printf("%c\n", scelta);

          if(scelta3 == 's'){
              controllo = 1;
          }else{
              controllo = 0;
          }

          break;
        default:
          printf("Opzione sbagliata\n");
    }
  }
  return 0;
};
