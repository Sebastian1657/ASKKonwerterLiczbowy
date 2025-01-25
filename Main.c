#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void menu();
void KonwersjaBinINT(){
    int liczba, liczba2, k;
    char bin[32];
    printf("Konwersja binarna INT\n");
    do{
        printf("Podaj liczbe: ");
        k=scanf("%d",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    }while (k==0);
    liczba2 = liczba;
    printf("%d (DEC) = ",liczba);
    for(int i=0;i<32;i++){
        if(liczba2&1)bin[i]='1';
        else bin[i]='0';
        liczba2=liczba2>>1;
    }
    if (liczba>0){
        int i = 31;
        while(bin[i]=='0'&&i>0)i--;
        for(int j=i;j>=0;j--){
            printf("%c",bin[j]);
        }
    }else{
        printf("-");
        for(int i=31;i>=0;i--)printf("%c",bin[i]);
    }
    printf(" (BIN)\n");
}
void KonwersjaBinFLOAT(){
    float liczba;
    int k;
    printf("Konwersja binarna FLOAT\n");
    do{
        printf("Podaj liczbe: ");
        k=scanf("%f",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    } while (k==0);
    int* bin = (int*)&liczba;
    int znak = (*bin>>31)&1;
    int cecha = (*bin>>23)&0xFF;
    int mantysa = (*bin&0x7FFFFF);
    printf("%f (DEC) = %d ",liczba,znak);
    for(int i=7;i>=0;i--){
        printf("%d",(cecha>>i)&1);
    }
    printf(" ");
    for(int i=22;i>=0;i--){
        printf("%d",(mantysa>>i)&1);
    }
    printf(" (BIN IEEE 754)\n");
}
void KonwersjaBinDOUBLE(){
    double liczba;
    int k;
    printf("Konwersja binarna DOUBLE\n");
    do{
        printf("Podaj liczbe: ");
        k=scanf("%lf",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    } while (k==0);
    long long int* bin = (long long int*)&liczba;
    int znak = (*bin>>63)&1;
    long long int cecha = (*bin>>52)&0x7FF;
    long long int mantysa = (*bin&0xFFFFFFFFFFFFF);
    printf("%lf (DEC) = %d ",liczba,znak);
    for(int i=10;i>=0;i--){
        printf("%d",(int)(cecha>>i)&1);
    }
    printf(" ");
    for(int i=51;i>=0;i--){
        printf("%d",(int)(mantysa>>i)&1);
    }
    printf(" (BIN IEEE 754)\n");
}
void KonwersjaBajtINT(){
    int liczba=1, k, endian=1; //1-big endian, 0-little endian
    unsigned char *endianBajt = (unsigned char*)&liczba;
    if(*endianBajt==1)endian=0;
    do{
        printf("Podaj liczbe: ");
        k=scanf("%d",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    }while (k==0);
    unsigned char *bajt = (unsigned char*)&liczba;
    printf("%d (DEC) = 0x",liczba);
    if(endian==0){
        for(int i=0;i<sizeof(int);i++){
            printf("%02X",bajt[i]);
        }
    }else{
        for(int i=sizeof(int)-1;i>=0;i--){
            printf("%02X",bajt[i]);
        }
    }
    printf(" (HEX)\n");
}
void KonwersjaBajtFLOAT(){
    int e=1, k, endian=1; //1-big endian, 0-little endian
    unsigned char *endianBajt = (unsigned char*)&e;
    if(*endianBajt==1)endian=0;
    float liczba;
    do{
        printf("Podaj liczbe: ");
        k=scanf("%f",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    }while (k==0);
    unsigned char *bajt = (unsigned char*)&liczba;
    printf("%f (DEC) = 0x",liczba);
    if(endian==0){
        for(int i=0;i<sizeof(float);i++){
            printf("%02X",bajt[i]);
        }
    }else{
        for(int i=sizeof(float)-1;i>=0;i--){
            printf("%02X",bajt[i]);
        }
    }
    printf(" (HEX)\n");
}
void KonwersjaBajtDOUBLE(){
    int e=1, k, endian=1; //1-big endian, 0-little endian
    unsigned char *endianBajt = (unsigned char*)&e;
    if(*endianBajt==1)endian=0;
    double liczba;
    do{
        printf("Podaj liczbe: ");
        k=scanf("%lf",&liczba);
        if (k==0)printf("\nBlad formatu!\n");
        while(getchar()!='\n');
    }while (k==0);
    unsigned char *bajt = (unsigned char*)&liczba;
    printf("%lf (DEC) = 0x",liczba);
    if(endian==0){
        for(int i=0;i<sizeof(double);i++){
            printf("%02X",bajt[i]);
        }
    }else{
        for(int i=sizeof(double)-1;i>=0;i--){
            printf("%02X",bajt[i]);
        }
    }
    printf(" (HEX)\n");
}
void FloatDec(){
    printf("+===========================================================================================================+\n");
    printf("|   Konwersja miedzy typami FLOAT oraz DECIMAL odbywa sie wedlug standardu IEEE 754.                        |\n");
    printf("|   Liczba typu FLOAT jest zapisywana na 32 bitach, w postaci:                                              |\n");
    printf("|   1 bit na znak, 8 bitow na ceche oraz 23 bity na mantyse                                                 |\n");
    printf("|   Przyklad dla liczby typu FLOAT = 1 10000101 00010100011111100101110:                                    |\n");
    printf("+===========================================================================================================+\n");
    printf("|   Aby przekonwertowac liczbe typu FLOAT na liczbe typu DECIMAL, nalezy:                                   |\n");
    printf("|                                                                                                           |\n");
    printf("|   1. Rozdielic liczbe na znak, ceche i mantyse:                                                           |\n");
    printf("|       > znak = 1 (pierwszy bit)                                                                           |\n");
    printf("|       > cecha = 10000101 (nastepne 8 bitow)                                                               |\n");
    printf("|       > mantysa = 00010100011111100101110 (ostatnie 23 bity)                                              |\n");
    printf("|   2. Bit znaku wskazuje na wartosc ujemna: (-1)\u2074                                                     |\n");

            
};
void OdejmowanieU2(){
    printf("Odejmowanie w U2\n");
};
void MenuPostac(short typ){
    char ch;
    printf("+================================================+\n");
    printf("I   Podaj typ danych, ktore chcesz wprowadzic:   I\n");
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
            if(typ==16)KonwersjaBajtINT();
            else if(typ==2)KonwersjaBinINT();
            break;
        case '2':
            system("cls");
            if(typ==16)KonwersjaBajtFLOAT();
            else if(typ==2)KonwersjaBinFLOAT();
            break;
        case '3':
            system("cls");
            if(typ==16)KonwersjaBajtDOUBLE();
            else if(typ==2)KonwersjaBinDOUBLE();
            break;
        case '4':
            system("cls");
            menu();
            break;
        case ('5'||27):
            exit(0);
    }
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
            MenuPostac(16);
            break;
        case '2':
            system("cls");
            MenuPostac(2);
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