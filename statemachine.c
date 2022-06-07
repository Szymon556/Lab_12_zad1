
#include <stdio.h>
#include <stdlib.h>
#include "statemachine.h"
#include "reader.h"
void exec()
{   char Buffor= 'a';
    
    while(Buffor!='q')
    {   
		
		printf("\nPodaj Znak: ");
	    Buffor= readChar();
		
		zly_exec(Buffor);
	}
	
}
void zly_exec(char dane)
 {  
	 static const Stan_t MaszynaStan[]={
		{ECHO,wypisz_na_ekran},
		 {WRITE,wypisz_plik}
		 };
  static StateDescriptor_t aktualny_stan = ECHO;//STAN POCZATKOwy static zeby pamietalo stan nawet po zakonczeniu programu

   for(int i = 0 ; i<sizeof(MaszynaStan)/sizeof(Stan_t);i++)
   {
	   if(MaszynaStan[i].stan==aktualny_stan)
	   {
		   aktualny_stan=MaszynaStan[i].obsluga(dane);
		   break;
	   }
   }
 }