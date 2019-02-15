/*Id.Programa: Galaxian.cpp
Autor........: Nicolás Darío Felicetti
Fecha........: marzo-2018
Comentario...: Primer intento de video juego manipulando caracteres en C++
*/

 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<windows.h>
 using namespace std;


  struct sDisparo{
  short fila,
     columna;
  bool disparado;

 };

 struct sDisparoEnemy{
  short fila,
        columna;
  bool disparado;
 };


 struct sMovNave{
  short fila,
     columna;
  bool exit;
  sDisparo disparo;
  short vidas;
  int   puntos;
 };

 struct sMovEnemy{
  short fila,
     columna;
  bool movant;
  sDisparoEnemy disparo;
 };


 void MovimientoNaveyDisparo(sMovNave&rMovNave){
 char comando;
 if(kbhit()){

    comando=getch();
    switch(comando){
        case 'a':
            if(rMovNave.columna!=1)
                rMovNave.columna-=1;

        break;

        case 'd':
            if(rMovNave.columna!=27)
                rMovNave.columna+=1;
            break;
        case 'l':
        if(rMovNave.disparo.disparado==false){
        rMovNave.disparo.columna=rMovNave.columna+2;
        rMovNave.disparo.fila=rMovNave.fila-1;
        rMovNave.disparo.disparado=true;
        }
        break;

        case 'e':

            rMovNave.exit=true;
            break;
    }
 }
 }//Comandos de la nave



 void MovimientoEnemigoyDisparo(sMovEnemy&rMovEnemy,sMovNave rMovNave){
  if(rMovEnemy.movant==true){
    rMovEnemy.columna+=1;
    if(rMovEnemy.columna==27)
        rMovEnemy.movant=false;
  }
  else{
    rMovEnemy.columna-=1;
    if(rMovEnemy.columna==1)
        rMovEnemy.movant=true;
  }
 if(rMovEnemy.columna==rMovNave.columna){
    if(rMovEnemy.disparo.disparado==false){
    rMovEnemy.disparo.disparado=true;
    rMovEnemy.disparo.columna=rMovEnemy.columna+2;
    rMovEnemy.disparo.fila=3;
 }

 }//Movimiento y distaro de la nave
 }
void DisparoNave(sMovNave&rMovNave){

 if(rMovNave.disparo.fila!=2)
    rMovNave.disparo.fila-=1;
    if(rMovNave.disparo.fila==2)
        rMovNave.disparo.disparado=false;

}//Movimiento del disparo de la Nave

void DisparoEnemy(sMovEnemy&rMovEnemy){
 if(rMovEnemy.disparo.fila!=19){
    rMovEnemy.disparo.fila+=1;
    if(rMovEnemy.disparo.fila==19)
        rMovEnemy.disparo.disparado=false;

}

}

void AnimacionDestruct(int columna,int fila){
short i;
Beep(300,1000);
gotoxy(columna,fila);cout<<"  * ";
gotoxy(columna,fila+1);cout<<"  * ";
Sleep(1000);
clreol();
gotoxy(columna,fila);cout<<" ***";
gotoxy(columna,fila+1);cout<<" ***";
Sleep(1000);
clreol();
gotoxy(columna,fila);cout<<"  * ";
gotoxy(columna,fila+1);cout<<"  * ";
Sleep(1000);
clreol();
gotoxy(columna,fila);cout<<"* * *";
gotoxy(columna,fila+1);cout<<"* * *";
Sleep(1000);
clreol();
}

int Destruct(sMovEnemy rMovEnemy,sMovNave rMovNave){
 if((rMovNave.fila==rMovEnemy.disparo.fila&&rMovNave.columna+2==rMovEnemy.disparo.columna)||
    (rMovNave.fila+1==rMovEnemy.disparo.fila&&rMovNave.columna==rMovEnemy.disparo.columna)||
    (rMovNave.fila+1==rMovEnemy.disparo.fila&&rMovNave.columna+1==rMovEnemy.disparo.columna)||
    (rMovNave.fila+1==rMovEnemy.disparo.fila&&rMovNave.columna+2==rMovEnemy.disparo.columna)||
    (rMovNave.fila+1==rMovEnemy.disparo.fila&&rMovNave.columna+3==rMovEnemy.disparo.columna)||
    (rMovNave.fila+1==rMovEnemy.disparo.fila&&rMovNave.columna+4==rMovEnemy.disparo.columna))
        return 1;
 if((rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna==rMovNave.disparo.columna)||
    (rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna+1==rMovNave.disparo.columna)||
    (rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna+2==rMovNave.disparo.columna)||
    (rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna+3==rMovNave.disparo.columna)||
    (rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna+4==rMovNave.disparo.columna)||
    (rMovEnemy.fila==rMovNave.disparo.fila&&rMovEnemy.columna+5==rMovNave.disparo.columna))
     return 2;

     return 0;

}

 void Inicializar(sMovNave&rMovNave,sMovEnemy&rMovEnemy){
 rMovNave.fila=17;
 rMovNave.columna=15;
 rMovEnemy.fila=3;
 rMovEnemy.columna=1;
 rMovNave.disparo.fila=2;
 rMovEnemy.disparo.fila=19;
 rMovEnemy.movant=true;
 rMovEnemy.disparo.disparado=false;
 rMovNave.disparo.disparado=false;
 rMovNave.exit=false;
 }

  void Imprimirmovimiento(sMovNave&rMovNave,sMovEnemy&rMovEnemy){
    gotoxy(1,1);cout<<"Vidas: "<<rMovNave.vidas;
    gotoxy(15,1);cout<<"Puntos: "<<rMovNave.puntos;
    if(Destruct(rMovEnemy,rMovNave)==2){
        AnimacionDestruct(rMovEnemy.columna,rMovEnemy.fila);
        Inicializar(rMovNave,rMovEnemy);
        rMovNave.puntos+=10;
    }
    else
    gotoxy(rMovEnemy.columna,rMovEnemy.fila); cout<<"[-o-]";

    if(Destruct(rMovEnemy,rMovNave)==1){
        AnimacionDestruct(rMovNave.columna,rMovNave.fila);
        Inicializar(rMovNave,rMovEnemy);
        rMovNave.vidas-=1;
    }
    else{
    gotoxy(rMovNave.columna,rMovNave.fila);     cout<<"  | ";
    gotoxy(rMovNave.columna,rMovNave.fila+1);   cout<<">-O-<"<<endl;
    }

    if(rMovNave.disparo.fila!=2){
        gotoxy(rMovNave.disparo.columna,rMovNave.disparo.fila);cout<<"*";

    }
    if(rMovEnemy.disparo.fila!=19){
        gotoxy(rMovEnemy.disparo.columna,rMovEnemy.disparo.fila); cout<<"*";
    }

  }

 void Main(){
  sMovNave rMovNave;
 sMovEnemy rMovEnemy;

 _setcursortype(_NOCURSOR);
 Inicializar(rMovNave,rMovEnemy);
 rMovNave.vidas=3;
 rMovNave.puntos=0;
 gotoxy(1,1);cout<<"Vidas: "<<rMovNave.vidas;
 gotoxy(15,1);cout<<"Puntos: "<<rMovNave.puntos;
 gotoxy(9,12);cout<<"STAR EXPLORER";
 gotoxy(6,13);cout<<"Enter para comenzar";
 getch();
 clrscr();
   Imprimirmovimiento(rMovNave,rMovEnemy);
 while(rMovNave.exit==false&&rMovNave.vidas!=0){

   MovimientoNaveyDisparo(rMovNave);
   MovimientoEnemigoyDisparo(rMovEnemy,rMovNave);
   DisparoNave(rMovNave);
   DisparoEnemy(rMovEnemy),
   Sleep(60);
   clrscr();
   Imprimirmovimiento(rMovNave,rMovEnemy);

 }
 clrscr();
 gotoxy(9,9);cout<<"GAME OVER";

 }



