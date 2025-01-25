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
void p1(){
    printf("+================================================================================================================+\n");
    printf("|   Konwersja miedzy typami FLOAT oraz DECIMAL odbywa sie wedlug standardu IEEE 754.                             |\n");
    printf("|   Liczba typu FLOAT jest zapisywana na 32 bitach, w postaci:                                                   |\n");
    printf("|   1 bit na znak, 8 bitow na ceche oraz 23 bity na mantyse                                                      |\n");
    printf("|   Przyklad dla liczby typu FLOAT = 1 10000101 00010111000000000000000:                                         |\n");
    printf("+================================================================================================================+\n");
    printf("|   Aby przekonwertowac liczbe typu FLOAT na liczbe typu DECIMAL, nalezy:                                        |\n");
    printf("|                                                                                                                |\n");
    printf("|   1. Rozdielic liczbe na znak, ceche i mantyse:                                                                |\n");
    printf("|       > znak = 1 (pierwszy bit)                                                                                |\n");
    printf("|       > cecha = 10000101 (nastepne 8 bitow)                                                                    |\n");
    printf("|       > mantysa = 00010111000000000000000 (ostatnie 23 bity)                                                   |\n");
    printf("|   2. Bit znaku wskazuje na wartosc ujemna: (-1)^1 = -1                                                         |\n");
    printf("|   3. Zamieniamy wartosc cechy zapisana binarnie na zapis dziesietny i obliczamy wartosc wykladnika:            |\n");
    printf("|       > 10000101 = 1*2^0 + 0*2^1 + 1*2^2 + 0*2^3 + 0*2^4 + 0*2^5 + 0*2^6 + 1*2^7 = 133                         |\n");
    printf("|       > wykladnik = cecha - bias (127) = 133 - 127 = 6                                                         |\n");
    printf("|   4. Zamieniamy wartosc mantysy zapisana binarnie na zapis dziesietny (konwersja ulamkowa) i dodajemy 1:       |\n");
    printf("|       > 00010111000000000000000b = 0*2^-1 + 0*2^-2 + 0*2^-3 + 1*2^-4 + ... + 0*2^-23 = 0.08984375d             |\n");
    printf("|       > 1 + 0.08984375 = 1.08984375                                                                            |\n");
    printf("|   5. Podkladamy pod wzor: znak * wartosc_mantysy * 2^wykladnik:                                                |\n");
    printf("|       > -1 * 1.08984375 * 2^6 = -69.75                                                                         |\n");
    printf("|   6. Wynik konwersji jest rowny uzyskanej liczbie: -69.75                                                      |\n");
    printf("|                                                                                                                |\n");
    printf("+================================================================================================================+\n");
    printf("|                Nacisnij spacje, aby przejsc dalej. Nacisnij ESC aby powrocic do menu glownego.                 |\n");
    printf("+================================================================================================================+\n");
}
void p2(){
    printf("+================================================================================================================+\n");
    printf("|   Konwersja miedzy typami FLOAT oraz DECIMAL odbywa sie wedlug standardu IEEE 754.                             |\n");
    printf("|   Liczba typu FLOAT jest zapisywana na 32 bitach, w postaci:                                                   |\n");
    printf("|   1 bit na znak, 8 bitow na ceche oraz 23 bity na mantyse                                                      |\n");
    printf("|   Przyklad dla liczby typu DECIMAL = 3.1415:                                                                   |\n");
    printf("+================================================================================================================+\n");
    printf("|   Aby przekonwertowac liczbe typu DECIMAL na liczbe typu FLOAT, nalezy:                                        |\n");
    printf("|                                                                                                                |\n");
    printf("|   1. Okreslic bit znaku (0 - liczba dodatnia, 1 - liczba ujemna):                                              |\n");
    printf("|       > 3.1415 > 0, wiec znak = 0 (pierwszy bit)                                                               |\n");
    printf("|   2. Zapisac wartosc w notacji u2 (wartosc musi zawierac sie pomiedzy 1 i 2):                                  |\n");
    printf("|       > 3.1415 = (-1)^0 * (1+czesc_ulamkowa) * 2^wykladnik                                                     |\n");
    printf("|       > 3.1415 / 2^wykladnik = 1+czesc_ulamkowa                                                                |\n");
    printf("|           : 3.1415 / 2^0 = 3.1415                                                                              |\n");
    printf("|           : 3.1415 / 2^1 = 1.57075 <- wieksze od 1 i mniejsze od 2                                             |\n");
    printf("|       > czesc_ulamkowa = 0.57075                                                                               |\n");
    printf("|   3. Okreslic ceche w postaci binarnej na podstawie wyliczonego wykladnika:                                    |\n");
    printf("|       > cecha = bias + wykladnik => 127 + 1 = 128d                                                             |\n");
    printf("|       > Dzielimy liczbe przez 2 do momentu, gdy wynik jest mniejszy od 1 i zapisujemy reszte:                  |\n");
    printf("|           :  128 / 2 | 0                                                                                       |\n");
    printf("|           :   64 / 2 | 0                                                                                       |\n");
    printf("|           :   32 / 2 | 0                                                                                       |\n");
    printf("|           :   16 / 2 | 0                                                                                       |\n");
    printf("|           :    8 / 2 | 0                                                                                       |\n");
    printf("|           :    4 / 2 | 0                                                                                       |\n");
    printf("|           :    2 / 2 | 0                                                                                       |\n");
    printf("|           :    1 / 2 | 1                                                                                       |\n");
    printf("|       > Zapisujemy wynik od konca: 128d = 10000000b                                                            |\n");
    printf("|   4. Wyznaczyc mantyse                                                                                         |\n");
    printf("|       > Czesc ulamkowa mnozymy przez 2. Jesli wynik jest wiekszy lub rowny 1, zapisujemy 1. Jesli wynik jest   |\n");
    printf("|         mniejszy od 1, zapisujemy 0. Czesc po przecinku wymnazamy przez 2 i powtarzamy proces do momentu, az   |\n");
    printf("|         uzyskamy 32 bity.                                                                                      |\n");
    printf("|           :  0.57075 * 2 = 1.1415 => 1                                                                         |\n");
    printf("|           :   0.1415 * 2 = 0.2830 => 0                                                                         |\n");
    printf("|           :   0.2830 * 2 = 0.5660 => 0                                                                         |\n");
    printf("|           :   ...                                                                                              |\n");
    printf("|           :    0.008 * 2 = 0.016  => 0                                                                         |\n");
    printf("|       > Zapisujemy otrzymane bity mantysy od gory: 10010010000111001010110                                     |\n");
    printf("|   5. Laczymy znak, ceche i mantyse: 0 10000000 10010010000111001010110                                         |\n");
    printf("+================================================================================================================+\n");
    printf("|         Nacisnij spacje, aby wrocic do poprzedniej strony. Nacisnij ESC aby powrocic do menu glownego.         |\n");
    printf("+================================================================================================================+\n");
}
void FloatDec(){
    system("cls");
    short i=1;
    char ch;
    p1();
    do{
        do{
            ch = getch();
        } while (ch != 32 && ch != 27);
        switch(ch){
            case 32:
                system("cls");
                if(i){
                    p2();
                    i=0;
                }else{
                    p1();
                    i=1;
                }
                break;
            case 27:
                system("cls");
                menu();
                break;
        }
    }while(ch!=27);
};
void OdejmowanieU2(){
    printf("Odejmowanie w U2\n");
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