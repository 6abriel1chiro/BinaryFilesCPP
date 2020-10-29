#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#define COLORNORMAL 7
#define TAM 100
using namespace std;

void gotoxy(short x, short y)
{
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(WORD col)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}


typedef struct
{

    int posicionx,posiciony,dimension,color;
    char caracterDibujo, codigo;

}tipoFigura;

typedef struct
{

    tipoFigura listaFiguras[TAM];
    int cantFiguras;

}tipoDisenio;


void dibujaLineaHorizontal(int n,int posx,int posy,char paint,char pen)
//dibuja una linea con el car de un tamanio del color pintura, a partir de la posx,posy
{
    color(11);
    for (int i=0;i<n;i++)
    {
        gotoxy(posx+i,posy);
        cout<<pen;
    }
    color(COLORNORMAL);

}

void dibujaLineaVertical(int n,int posx,int posy,char paint,char pen)
{
        color(11);
        for (int j=0;j<n;j++){
        cout<<pen<<endl;

            }
             color(COLORNORMAL);
}

 void mostrarCuadrado(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
        figura.posiciony++;

    }
 }



 void mostrarTriangulo(tipoFigura figura){
    for (int i=0;i<figura.dimension+1;i++)
    {
        dibujaLineaHorizontal(i,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
        figura.posiciony++;
    }

 }

 void mostrarRectangulo(tipoFigura figura){
     for(int i = 0;i<figura.dimension+(figura.dimension/2);i++){
         dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
       figura.posiciony++;
    }
 }
 void mostrarRombo(tipoFigura figura){
 int i,j,k;
 color(11);
for (i = 1; i <= figura.dimension; i++)

    {

          for (j = 0; j < (figura.dimension - i); j++)
            cout << " ";
          for (j = 1; j <= i; j++)
            cout << figura.caracterDibujo;
          for (k = 1; k < i; k++)
               cout << figura.caracterDibujo;
          cout << "\n";

    }



    for (i = figura.dimension - 1; i >= 1; i--)

    {

          for (j = 0; j < (figura.dimension - i); j++)
                cout << " ";
          for (j = 1; j <= i; j++)
                cout << figura.caracterDibujo;
          for (k = 1; k < i; k++)
                cout << figura.caracterDibujo;
          cout << "\n";
    }
    cout << "\n";
color(COLORNORMAL);
 }

 void mostrarFigura(tipoFigura figura)
{

if(figura.codigo=='c'){
mostrarCuadrado(figura);
}

if(figura.codigo=='t'){

mostrarTriangulo(figura);
}
if(figura.codigo=='r'){

mostrarRectangulo(figura);

}
if(figura.codigo=='o'){
mostrarRombo(figura);
}
}


 bool comprobar(char respuesta){

 if(respuesta=='s' or respuesta=='S'){
    return true;

 }
 else if(respuesta=='n' or respuesta=='N'){

        return false;

 }
 else{
    cout<<"respuesta no valida "<<endl;
 }
 return false;
 }


  void guardarDibujo(char dibujo[TAM],string file_name)
 {
ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/" + file_name + ".txt");
file<<dibujo;
file.close();
}

 void cargarDibujo(string file_name)
{
    tipoFigura a;
ifstream arch;
arch.open("E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/" + file_name + ".txt");
arch.read((char *)&a, sizeof(a));
while (not arch.eof())
{
cout<<"dibujo"<<endl;
}
arch.close();
}


 void guardarDisenio(tipoDisenio disenio, string file_name)
 {
ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/" + file_name + ".dat",ios::binary);
    file.write((char *)&disenio,sizeof(disenio));

file.close();
 }


 void cargarDisenio(string file_name, tipoDisenio &a)
{

ifstream arch;
arch.open("E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/" + file_name + ".dat",ios::binary);
arch.read((char *)&a, sizeof(a));
//mostrarDisenio(a);

arch.close();
}


void mostrarDisenio(tipoDisenio disenio)
{
    for(int i=0;i<disenio.cantFiguras;i++)
    {

        mostrarFigura(disenio.listaFiguras[i]);
    }


}


int main(){

char dibujo[TAM];
int opcion;
bool continuar=true;
string file_name;
tipoDisenio disenio2;

char figura,Rsalida,siono;
    tipoFigura cuadrado={0,0,4,0,'*','c'};
    tipoFigura triangulo={20,0,4,0,'*','t'};
    tipoFigura rectangulo={40,0,4,0,'*','r'};
    tipoFigura rombo={60,0,4,0,'*','o'};

    tipoDisenio miDibujo;
    miDibujo.cantFiguras=4;
    miDibujo.listaFiguras[0]=cuadrado;
    miDibujo.listaFiguras[1]=triangulo;
    miDibujo.listaFiguras[2]=rectangulo;
    miDibujo.listaFiguras[3]=rombo;




    while(continuar){
cout<<" hola, ingresa el modo de uso "<<endl;

cout<<"1. dibujo libre"<<endl;
cout<<"2. elegir figuras predefinidas "<<endl;
cout<<"3. cargar un diseño "<<endl;
cout<<"4. salir"<<endl;
cin>>opcion;



switch(opcion){

case 1:
    cout<<" dibujo libre "<<endl;
    cout<<"ingrese su dibujo "<<endl;
    cin>>dibujo;

    cout<<"desea guardar su diseño: "<<dibujo<<endl;
     cout<<dibujo<<endl;
    cin>>siono;
    if(comprobar(siono)){
        guardarDibujo(dibujo,file_name);
        cout<<"se guardo su dibijo "<<endl;
    }

    break;
case 2:
      cout<<" elija una figura "<<endl;
      cin>>figura;
      if(figura=='c'){
mostrarFigura(cuadrado);
}

if(figura=='t'){

mostrarFigura(triangulo);
}
if(figura=='r'){

mostrarFigura(rectangulo);

}
if(figura=='o'){
mostrarFigura(rombo);
}
cout<<"desea guardar su dusenio "<<endl;
cin>>siono;
if(comprobar(siono))
    guardarDisenio(miDibujo,"figura");
    break;
case 3:
      cout<<" cargar un dibujo "<<endl;
      cargarDibujo(file_name);


    break;
case 4:
      cout<<" cargar un diseño "<<endl;

cargarDisenio("figura",disenio2);
system("cls");
cout<<"se cargo el diseño: "<<endl;
mostrarDisenio(disenio2);
    break;

case 5:
  cout<<" gracias por usar la aplicacion "<<endl;
    break;

}

cout<<"desea seguir  usando la app ?(s/n) "<<endl;
cin>>Rsalida;
continuar=comprobar(Rsalida);
}

    return 0;
}

