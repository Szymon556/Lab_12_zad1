#pragma once



typedef enum StateDescriptor {
 ECHO ,
 WRITE 
 
 }StateDescriptor_t;
 typedef StateDescriptor_t (*EventHandler)(char znaki);//w ten sposod definiujemy kilka funkcji bo pod Event handel możemy sobie dac x,y,x i wszytkie te funkcje będą typu StateDesriptor
 typedef struct Stan
 {
      StateDescriptor_t stan;
      EventHandler obsluga;    // odpowiedzialna z obsluge zdarzen
 }Stan_t;
 
char readChar();
 StateDescriptor_t wypisz_na_ekran(char znaki); //stan echo
 StateDescriptor_t wypisz_plik(char znaki); //stan write
