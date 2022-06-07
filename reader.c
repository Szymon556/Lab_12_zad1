#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "statemachine.h"

static void plik(char znak)
{   FILE *fptr;
    fptr = fopen("output.txt","a+");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fprintf(fptr,"%c",znak);
   fclose(fptr);

}


char readChar() {
	char character;
	while ((character = getchar()) == '\n' || character == EOF) {}
	return character;
}
 StateDescriptor_t wypisz_na_ekran(char znaki) //obsluga zdarzenia kiedy na wejscie jest podawane co kolwiek oraz e
 {
	 printf("\nwypisuje na ekran\t%c",znaki);
	 return znaki == 'W' ? WRITE : ECHO;
 }
  StateDescriptor_t wypisz_plik(char znaki) //obsluga zdarzenia kiedy na wejscie jest podawane w
 {   plik(znaki);
	 if(znaki=='E')
	 {
		return ECHO;
	  }
	 
     return WRITE;
 }
