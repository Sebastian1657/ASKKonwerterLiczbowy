#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void menu();


void KonwersjaBinINT(){                     //dodać sprawdzenie czy liczba jest w zakresie intów, funkcjonalność dla liczb ujemnych, zabezpieczenie poprawności wprowadzanych danych
    printf("Konwersja binarna INT\n");
    int liczba, liczbacpy;
    char liczbaBin[33]="";
    char temp;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    liczbacpy=liczba;
    while(liczba>0){
        if(liczba%2==1){
            strcat(liczbaBin,"1");
            liczba--;
            liczba/=2;
        }else{
            strcat(liczbaBin,"0");
            liczba/=2;
        }
    }
    for(int i=strlen(liczbaBin)-1;i>=strlen(liczbaBin)/2;i--){
        temp=liczbaBin[i];
        liczbaBin[i]=liczbaBin[strlen(liczbaBin)-1-i];
        liczbaBin[strlen(liczbaBin)-1-i]=temp;
    }
    printf("%d (dec) = %s (bin)\n",liczbacpy,liczbaBin);
}
void KonwersjaBinFLOAT(){
    printf("Konwersja binarna FLOAT\n");
}
void KonwersjaBinDOUBLE(){
    printf("Konwersja binarna DOUBLE\n");
}
void MenuPostacBinarna(){
    char ch;
    printf("+================================================+\n");
    printf("I   Podaj typ danych, które chcesz wprowadzić:   I\n");
    printf("I   1. INT                                       I\n");
    printf("I   2. FLOAT                                     I\n");
    printf("I   3. DOUBLE                                    I\n");
    printf("I   4. Powrot do menu glownego                   I\n");
    printf("I   5. Wyjdz z programu                          I\n");
    printf("I                                                I\n");
    printf("+================================================+\n");
    do{
        ch = getch();
    }while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!=27);
    switch(ch){
        case '1':
            system("cls");
            KonwersjaBinINT();
            break;
        case '2':
            system("cls");
            KonwersjaBinFLOAT();
            break;
        case '3':
            system("cls");
            KonwersjaBinDOUBLE();
            break;
        case '4':
            system("cls");
            menu();
            break;
        case ('5'||27):
            exit(0);
    }
};
void MenuPostacBajtowa(){
    printf("Postac bajtowa danych\n");
}
void OdejmowanieU2(){
    printf("Odejmowanie w U2\n");
};
void FloatDec(){
    printf("Konwersja FLOAT to DEC\n");
};

void menu(void){
    char ch;
    printf("+=====================================+\n");
    printf("I           Wybierz akcje:            I\n");
    printf("I   1. Drukuj postac bajtowa danych   I\n");
    printf("I   2. Drukuj postac binarna danych   I\n");
    printf("I   3. Zasady odejmowania w U2        I\n");
    printf("I   4. Konwersja FLOAT <-> DEC        I\n");
    printf("I   5. Wyjdz z programu               I\n");
    printf("I                                     I\n");
    printf("+=====================================+\n");
    do{
        ch = getch();
    }while(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!=27);
    switch(ch){
        case '1':
            system("cls");
            MenuPostacBajtowa();
            break;
        case '2':
            system("cls");
            MenuPostacBinarna();
            break;
        case '3':
            system("cls");
            OdejmowanieU2();
            break;
        case '4':
            system("cls");
            FloatDec();
            break;
        case ('5'||27):
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