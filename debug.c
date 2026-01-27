#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
   char test[] = "Test success trashtrash";
   printf("%s\n", test);
   char container[13] = "\0";
   for(int i = 0; i < 12; i++){
    container[i] = test[i];
   }
   printf("%s\n", container);
}