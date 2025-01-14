#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void PostacBajtowa(){
    printf("Postac bajtowa danych\n");
};
void PostacBinarna(){
    printf("Postac binarna danych\n");
};
void OdejmowanieU2(){
    printf("Odejmowanie w U2\n");
};
void FloatToDec(){
    printf("Konwersja FLOAT to DEC\n");
};
void DecToFloat(){
    printf("Konwersja DEC to FLOAT\n");
};

void menu(void){
    char ch;
    printf("+=====================================+\n");
    printf("I           Wybierz akcje:            I\n");
    printf("I   1. Drukuj postac bajtowa danych   I\n");
    printf("I   2. Drukuj postac binarna danych   I\n");
    printf("I   3. Zasady odejmowania w U2        I\n");
    printf("I   4. Konwersja FLOAT to DEC         I\n");
    printf("I   5. Konwersja DEC to FLOAT         I\n");
    printf("I   6. Wyjdz z programu               I\n");
    printf("I                                     I\n");
    printf("+=====================================+\n");
    do{
        ch = getch();
    }while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!=27);
    switch(ch){
        case '1':
            system("cls");
            PostacBajtowa();
            break;
        case '2':
            system("cls");
            PostacBinarna();
            break;
        case '3':
            system("cls");
            OdejmowanieU2();
            break;
        case '4':
            system("cls");
            FloatToDec();
            break;
        case '5':
            system("cls");
            DecToFloat();
            break;
        case ('6'||27):
            exit(0);
    }
};

int main(){
    system("color 2");
    while(1){
        menu();
        return 0;
    }
}