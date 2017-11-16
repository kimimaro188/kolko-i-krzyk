/////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cstdio>
#include <sstream>
#include <conio.h>
#include <windows.h>

using namespace std;
char z[10],pole[10]={'1','2','3','4','5','6','7','8','9','10'};
int wybor,wybor1;
bool kolej;
char pionek,wygrany;
void gotoxy( const int x, const int y ){ ///funkcja ktora ustawia kursor na podanych wsp.
    COORD coord = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}


graczvskomputer(){ ///symulacja gry przeciwko komputerowi

//for(int o=1;;){
        for(int p=0;p<=8;p++){ ///zapasowe wartosci wszystkich pol
        z[p]=pole[p];
    }
srand( time( NULL ) );
wybor1=rand()%4; ///zmienna ktora inicjuje gre (sa 4rozne przypadki startu)


    for(int i=0;i<=10;i++){ ///glowna petla gry
    koniec:
    system("cls");

HANDLE kolor1,kolor2; ///zmiana koloru tabelki
kolor2 = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute( kolor2, 15 );


if(wybor1==0){ ///4 rozne przypadki na start gry
    cout<<"Kolej na komputer, ktory uzywa: kolka "<<endl;
    pionek='O';
    wygrany='X';
    wybor1=3;
}

else if(wybor1==1){
    cout<<"Kolej na gracza, ktory uzywa: kolka "<<endl;
    pionek='O';
    wygrany='X';
    wybor1=2;
}

else if(wybor1==2){
    cout<<"Kolej na komputer, ktory uzywa: krzyzyka "<<endl;
    pionek='X';
    wygrany='O';
    wybor1=1;
}

else if(wybor1==3){
    cout<<"Kolej na gracza, ktory uzywa: krzyzyka "<<endl;
    pionek='X';
    wygrany='O';
    wybor1=0;
}

    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;


//kolor = GetStdHandle( STD_OUTPUT_HANDLE );
//SetConsoleTextAttribute( kolor, 12 );
int g=0;
for(int o=0;o<3;o++){      ///podwojna petla zmieniajaca kolory dla 'X' i 'O'
    for(int p=0;p<3;p++){
        gotoxy(1+8*p,2+2*o);


        if(pole[g]=='X'){
                SetConsoleTextAttribute( kolor2, 9 );
                cout<<pole[g];
        }
        else if(pole[g]=='O'){
                SetConsoleTextAttribute( kolor2, 14 );
                cout<<pole[g];
        }
        else{
                SetConsoleTextAttribute( kolor2, 15 );
                cout<<pole[g];

    }
    g++;
    }
}
SetConsoleTextAttribute( kolor2, 15 );  ///powrot do wczesniejszego koloru

gotoxy(0,9);
///nizej warunek na sprawdzenie czy ktos wygral
if((pole[0]==pole[1]&&pole[1]==pole[2])||(pole[3]==pole[4]&&pole[4]==pole[5])||(pole[6]==pole[7]&&pole[7]==pole[8])||(pole[0]==pole[3]&&pole[3]==pole[6])||(pole[1]==pole[4]&&pole[4]==pole[7])||(pole[2]==pole[5]&&pole[5]==pole[8])||(pole[2]==pole[4]&&pole[4]==pole[6])||(pole[0]==pole[4]&&pole[4]==pole[8])||(pole[2]==pole[4]&&pole[4]==pole[6])){
    cout<<"Koniec!"<<endl;
    if((wybor1==0)||(wybor1==2))cout<<"Wygral komputer ktory uzywal '";
    else cout<<"Wygral gracz ktory uzywal '";
    cout<<wygrany<<"'"<<endl<<endl;
    cout<<"Po nacisnieciu dowolnego przycisku zostaniesz przeniesiony do menu"<<endl<<endl;
    getch();
    system("cls");
         for(int p=0;p<=8;p++){
        pole[p]=z[p];
        wybor1=rand()%4;

    }
    break;
}

    if(i==9){ ///warunek w przypadku remisu graczy
    cout << "REMIS!"<<endl;
    cout<<"Po nacisnieciu dowolnego przycisku zostaniesz przeniesiony do menu"<<endl<<endl;
    getch();
    system("cls");
    for(int p=0;p<=8;p++){
        pole[p]=z[p];
    }
    break;
}

if((wybor1==1)||(wybor1==3)){ ///symulacja ruchu bota
        Sleep(1000);
     int q,zastap=10;
///**************************************************************************************************************************///
         if((pole[0]==pionek)&&(pole[1]==pionek)){q=(pole[2]-48);if(q==3){zastap=q;}} ///ten segment odpowiada za sprawdzenie czy istnieje zwycieski ruch dla komputera
         if((pole[0]==pionek)&&(pole[2]==pionek)){q=(pole[1]-48);if(q==2){zastap=q;}}
         if((pole[1]==pionek)&&(pole[2]==pionek)){q=(pole[0]-48);if(q==1){zastap=q;}}
         if((pole[3]==pionek)&&(pole[4]==pionek)){q=(pole[5]-48);if(q==6){zastap=q;}}
         if((pole[3]==pionek)&&(pole[5]==pionek)){q=(pole[4]-48);if(q==5){zastap=q;}}
         if((pole[4]==pionek)&&(pole[5]==pionek)){q=(pole[3]-48);if(q==4){zastap=q;}}
         if((pole[6]==pionek)&&(pole[7]==pionek)){q=(pole[8]-48);if(q==9){zastap=q;}}
         if((pole[6]==pionek)&&(pole[8]==pionek)){q=(pole[7]-48);if(q==8){zastap=q;}}
         if((pole[7]==pionek)&&(pole[8]==pionek)){q=(pole[6]-48);if(q==7){zastap=q;}}
         if((pole[0]==pionek)&&(pole[3]==pionek)){q=(pole[6]-48);if(q==7){zastap=q;}}
         if((pole[0]==pionek)&&(pole[6]==pionek)){q=(pole[3]-48);if(q==4){zastap=q;}}
         if((pole[3]==pionek)&&(pole[6]==pionek)){q=(pole[0]-48);if(q==1){zastap=q;}}
         if((pole[1]==pionek)&&(pole[4]==pionek)){q=(pole[7]-48);if(q==8){zastap=q;}}
         if((pole[1]==pionek)&&(pole[7]==pionek)){q=(pole[4]-48);if(q==5){zastap=q;}}
         if((pole[4]==pionek)&&(pole[7]==pionek)){q=(pole[1]-48);if(q==2){zastap=q;}}
         if((pole[2]==pionek)&&(pole[5]==pionek)){q=(pole[8]-48);if(q==9){zastap=q;}}
         if((pole[2]==pionek)&&(pole[8]==pionek)){q=(pole[5]-48);if(q==6){zastap=q;}}
         if((pole[5]==pionek)&&(pole[8]==pionek)){q=(pole[2]-48);if(q==3){zastap=q;}}
         if((pole[0]==pionek)&&(pole[4]==pionek)){q=(pole[8]-48);if(q==9){zastap=q;}}
         if((pole[0]==pionek)&&(pole[8]==pionek)){q=(pole[4]-48);if(q==5){zastap=q;}}
         if((pole[4]==pionek)&&(pole[8]==pionek)){q=(pole[0]-48);if(q==1){zastap=q;}}
         if((pole[2]==pionek)&&(pole[4]==pionek)){q=(pole[6]-48);if(q==7){zastap=q;}}
         if((pole[2]==pionek)&&(pole[6]==pionek)){q=(pole[4]-48);if(q==5){zastap=q;}}
         if((pole[4]==pionek)&&(pole[6]==pionek)){q=(pole[2]-48);if(q==3){zastap=q;}}
         if(zastap<10){
            pole[zastap-1]=pionek;
            i++;
            //cout<<"Chcialem wygrac";
            //getch();
            goto koniec;
         }
///**************************************************************************************************************************///
        if((pole[0]==wygrany)&&(pole[1]==wygrany)){q=(pole[2]-48);if(q==3){zastap=q;}} ///jesli poprzedni segment jest pusty, ten odpowiada za zablokowanie ewentualnego zwyciestwa gracz
        if((pole[0]==wygrany)&&(pole[2]==wygrany)){q=(pole[1]-48);if(q==2){zastap=q;}}
        if((pole[1]==wygrany)&&(pole[2]==wygrany)){q=(pole[0]-48);if(q==1){zastap=q;}}
        if((pole[3]==wygrany)&&(pole[4]==wygrany)){q=(pole[5]-48);if(q==6){zastap=q;}}
        if((pole[3]==wygrany)&&(pole[5]==wygrany)){q=(pole[4]-48);if(q==5){zastap=q;}}
        if((pole[4]==wygrany)&&(pole[5]==wygrany)){q=(pole[3]-48);if(q==4){zastap=q;}}
        if((pole[6]==wygrany)&&(pole[7]==wygrany)){q=(pole[8]-48);if(q==9){zastap=q;}}
        if((pole[6]==wygrany)&&(pole[8]==wygrany)){q=(pole[7]-48);if(q==8){zastap=q;}}
        if((pole[7]==wygrany)&&(pole[8]==wygrany)){q=(pole[6]-48);if(q==7){zastap=q;}}
        if((pole[0]==wygrany)&&(pole[6]==wygrany)){q=(pole[3]-48);if(q==4){zastap=q;}}
        if((pole[3]==wygrany)&&(pole[6]==wygrany)){q=(pole[0]-48);if(q==1){zastap=q;}}
        if((pole[1]==wygrany)&&(pole[4]==wygrany)){q=(pole[7]-48);if(q==8){zastap=q;}}
        if((pole[1]==wygrany)&&(pole[7]==wygrany)){q=(pole[4]-48);if(q==5){zastap=q;}}
        if((pole[4]==wygrany)&&(pole[7]==wygrany)){q=(pole[1]-48);if(q==2){zastap=q;}}
        if((pole[2]==wygrany)&&(pole[5]==wygrany)){q=(pole[8]-48);if(q==9){zastap=q;}}
        if((pole[2]==wygrany)&&(pole[8]==wygrany)){q=(pole[5]-48);if(q==6){zastap=q;}}
        if((pole[5]==wygrany)&&(pole[8]==wygrany)){q=(pole[2]-48);if(q==3){zastap=q;}}
        if((pole[0]==wygrany)&&(pole[4]==wygrany)){q=(pole[8]-48);if(q==9){zastap=q;}}
        if((pole[0]==wygrany)&&(pole[8]==wygrany)){q=(pole[4]-48);if(q==5){zastap=q;}}
        if((pole[4]==wygrany)&&(pole[8]==wygrany)){q=(pole[0]-48);if(q==1){zastap=q;}}
        if((pole[2]==wygrany)&&(pole[4]==wygrany)){q=(pole[6]-48);if(q==7){zastap=q;}}
        if((pole[2]==wygrany)&&(pole[6]==wygrany)){q=(pole[4]-48);if(q==5){zastap=q;}}
        if((pole[4]==wygrany)&&(pole[6]==wygrany)){q=(pole[2]-48);if(q==3){zastap=q;}}
        if(zastap<10){
            pole[zastap-1]=pionek;
            i++;
           // cout<<"Chcialem nie przegrac";
           // getch();
            goto koniec;
        }

        else{ ///jesli poprzednie oba sgmenty nie przeszly tutaj nastepuje losowy ruch
             i++;
            int a,b;
            for(int i=0;;){
                a=rand()%9;
                b=pole[a];
                if((b-48)==(a+1)){
                    pole[a]=pionek;
                    goto koniec;
                }
            }
        }
///**************************************************************************************************************************///
}

else{ ///ruch gracza
    int b;
    for(int o=0;;){
    cin >> wybor;
    b=pole[wybor-1];
    if((b-48)!=wybor)cout<<endl<<"Podaj inna wartosc!";
    else{
            pole[wybor-1]=pionek;
            break;
    }
}
}
}
//getch();
//}
}

graczvsgracz(){ /// funkcja gry gracz vs gracz
    HANDLE kolor2; /// zmiana koloru tabelki
    kolor2 = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( kolor2, 15 );

    for(int p=0;p<10;p++){ /// kopia wartosci wyswietlanych w tabelce
        z[p]=pole[p];
    }

srand( time( NULL ) );
kolej=rand()%2; ///zmienna inicjalizujaca gre (2przypadki)
    for(int i=0;i<=10;i++){
    system("cls");



    cout<< "Kolej gracza, ktory uzywa: "; ///inicjalizacja gry
        if(kolej==1){
            pionek='X';
            wygrany='O';
            cout<<"krzyzyka"<<endl;}
        else{
            pionek='O';
            wygrany='X';
            cout<<"kolka"<<endl;}


    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;
    cout << "| ------- ------- |"<<endl;
    cout << "|-----------------|"<<endl;

int g=0;

for(int o=0;o<3;o++){ ///podwojna petla zmieniajaca kolory dla 'X' i 'O'
for(int p=0;p<3;p++){
    gotoxy(1+8*p,2+2*o);


    if(pole[g]=='X'){
            SetConsoleTextAttribute( kolor2, 9 );
            cout<<pole[g];
    }
    else if(pole[g]=='O'){
            SetConsoleTextAttribute( kolor2, 14 );
            cout<<pole[g];
    }
    else{
            SetConsoleTextAttribute( kolor2, 15 );
            cout<<pole[g];

    }
    g++;
    }
}

SetConsoleTextAttribute( kolor2, 15 ); ///powrot do odpowiedniego koloru
gotoxy(0,9);


if((pole[0]==pole[1]&&pole[1]==pole[2])||(pole[3]==pole[4]&&pole[4]==pole[5])||(pole[6]==pole[7]&&pole[7]==pole[8])||(pole[0]==pole[3]&&pole[3]==pole[6])||(pole[1]==pole[4]&&pole[4]==pole[7])||(pole[2]==pole[4]&&pole[4]==pole[6])||(pole[0]==pole[4]&&pole[4]==pole[8])||(pole[2]==pole[4]&&pole[4]==pole[6])){
    cout<<"Koniec!"<<endl;/// sprawdzenie czy ktorys z graczy nie wygral
    cout<<"Wygral gracz ktory uzywal '"<<wygrany<<"'"<<endl<<endl;
    cout<<"Po nacisnieciu dowolnego przycisku zostaniesz przeniesiony do menu"<<endl<<endl;
         for(int p=0;p<=8;p++){
         pole[p]=z[p];}
        kolej=rand()%2;

    break;
}

    if(i==9){ ///przypadek kiedy dochodzi do remisu
    cout << "REMIS!"<<endl;
    cout<<"Po nacisnieciu dowolnego przycisku zostaniesz przeniesiony do menu"<<endl<<endl;
    for(int p=0;p<=8;p++){
        pole[p]=z[p];
    }
    break;
}

    cin >> wybor;
pole[wybor-1]=pionek;
kolej=(kolej+1)%2;



}
getch();
}

instrukcja(){ ///instrukcja gry
    system("cls");
cout<<"Twoim zadaniem jest umieszczenie 3 jednakowych znakow w jednej linii"<<'\n'<<"Bot jest srednim poziomem trudnosci, da sie wygrac :)"<<'\n'<<'\n'<<"Powodzenia!";
getch();
}


int main()
{
HANDLE kolor2; ///odpowiedni kolor menu
kolor2 = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute( kolor2, 15 );

int wybor;
    int poprzedniWybor;
    bool wykonujPetle;
    start:

    ///pêtla g³ówna programu
    while( 1 )
    {
        wybor = 0;
        poprzedniWybor = wybor;
        wykonujPetle = true;

        ///rysowanie menu
        system( "cls" );
        gotoxy( 3, 1 );
        cout << "Gracz vs Komputer";
        gotoxy( 3, 3 );
        cout << "Gracz vs Gracz";
        gotoxy( 3, 5 );
        cout << "Instrukcja";
        gotoxy( 3, 7 );
        cout << "Exit";
        gotoxy( 46, 10 );
        cout<<"Artur Szczypta "<<char(1);
        gotoxy( 46, 11 );
        cout<<"Kontakt: szczypta.artur@gmail.com";
        gotoxy( 46, 1);
        cout<<"Nacisnij strzalke w prawo";

        ///przesuwanie strzalki
        while( wykonujPetle )
        {
            ///rysowanie strzalki wyboru
            gotoxy( 1, wybor * 2 + 1 );
            cout << static_cast < char >( 16 );

            ///obs³uga klawiatury
            poprzedniWybor = wybor;
            switch( getch() )
            {
            case 224: //STRZA£KI
                switch( getch() )
                {
                case 72: ///strza³ka w gore
                    if( 0 < wybor ) wybor--;
                    else wybor = 3;

                    break;

                case 80: ///strzalka w dol
                    if( wybor < 3 ) wybor++;
                    else wybor = 0;

                    break;

                case 77: ///strzalka w prawo
                    ///je¿eli wcisnieto strzalke w prawo, sprawdz wybrana opcje i wykonaj odpowiednia akcje
                    switch( wybor )
                    {
                    case 0:
                        graczvskomputer();
                        goto start;

                    case 1:
                        graczvsgracz();
                        goto start;

                    case 2:
                        instrukcja();
                        goto start;

                    case 3:
                        return 0;

                    }
                }
                break;
            }

            ///czyszczenie strza³ki wyboru
            gotoxy( 1, poprzedniWybor * 2 + 1 );
            cout << " ";
        }
    }
    return 0;
}
