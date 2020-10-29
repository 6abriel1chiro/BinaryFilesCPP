#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#define TAM 100
using namespace std;
///////////////1

typedef struct {

int dia,mes,anio;

} tipoFecha;

void leerFecha(tipoFecha &f)
{
cin>>f.dia>>f.mes>>f.anio;
}

void mostrarFecha(tipoFecha fecha)
{
cout<<fecha.dia<<"/"<<fecha.mes<<"/"<<fecha.anio<<endl;
}

void mostrarListaFechas(tipoFecha listaFechas[TAM],int n){
for(int i=0;i<n;i++)
{
    mostrarFecha(listaFechas[i]);
}
}
void crearArchivoFechas(int n)
{
    tipoFecha fecha;

ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoFechas.dat",ios::binary);
for(int i=0;i<n;i++){
    leerFecha(fecha);
    file.write((char *)&fecha,sizeof(fecha));

}
file.close();
}

void mostrarArchivoFecha()
{

    tipoFecha fecha;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoFechas.dat",ios::binary);
while(!file.eof() and file.read((char*)&fecha,sizeof(fecha)) )
{
    mostrarFecha(fecha);
}
file.close();
}


void FechasQuincena2Struct(tipoFecha listaFechas[TAM],int &i)
{
tipoFecha fecha;
i=0;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoFechas.dat",ios::binary);
while(!file.eof() and file.read((char*)&fecha,sizeof(fecha)) )
{
    if(fecha.dia<16){
    listaFechas[i]=fecha;
    i++;
    }
}
file.close();
}

void mostrarFechas2020()
{
    tipoFecha fecha;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoFechas.dat",ios::binary);
while(!file.eof() and file.read((char*)&fecha,sizeof(fecha)) )
{
    if(fecha.anio==2020)
    mostrarFecha(fecha);
}
file.close();


}


///////////////////2
typedef struct {
    char lastname[TAM];
    char name[TAM];
    char mail[TAM];
    char adress[TAM];
    char city[TAM];
    int phone;
    char whatsapp;
} tipoContacto;
void leerContacto(tipoContacto &contacto){
cout<<"Ap Paterno ";
cin>>contacto.lastname;

cout<<"Nombre ";
cin>>contacto.name;

cout<<"Mail ";
cin>>contacto.mail;

cout<<"Direccion ";
cin>>contacto.adress;

cout<<"Ciudad ";
cin>>contacto.city;

cout<<"Movil ";
cin>>contacto.phone;

cout<<"Tiene whatsapp ";
cin>>contacto.whatsapp;
}

void mostrarContacto(tipoContacto contacto)
{
cout<<" Ap Paterno ";
cout<<contacto.lastname<<endl;

cout<<" Nombre ";
cout<<contacto.name;

cout<<" Mail ";
cout<<contacto.mail<<endl;

cout<<" Direccion ";
cout<<contacto.adress<<endl;

cout<<" Ciudad ";
cout<<contacto.city<<endl;

cout<<" Movil ";
cout<<contacto.phone<<endl;

cout<<" Tiene whatsapp ";
cout<<contacto.whatsapp<<endl;
}

void crearArchivoContactos(int n)
{
    tipoContacto contacto;

ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat",ios::binary);
for(int i=0;i<n;i++){
    leerContacto(contacto);
    file.write((char *)&contacto,sizeof(contacto));

}
file.close();
}

void mostrarArchivoContacto()
{

    tipoContacto contacto;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat",ios::binary);
while(!file.eof() and file.read((char*)&contacto,sizeof(contacto)) )
{
    mostrarContacto(contacto);
}
file.close();
}


void addContact(int n){
tipoContacto contacto;
fstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat",ios::binary |ios::app |ios::out);
for(int i=0;i<n;i++){
    leerContacto(contacto);
    file.write((char *)&contacto,sizeof(contacto));

}
file.close();
}


void buscarContacto(char apellidoContacto[TAM])
{
tipoContacto contacto;
ifstream file;

file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat",ios::binary);


while(!file.eof() and file.read((char*)&contacto,sizeof(contacto)))
{
    if(strcmp(apellidoContacto,contacto.lastname)==0){
    mostrarContacto(contacto);
       }

}
file.close();
}

void modificarContacto(char nombre[TAM])
{
tipoContacto a;
fstream f;
int num;
int tamEstruc= sizeof(tipoContacto);
f.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat", ios::binary | ios::in | ios::out);




f.read((char *)&a, sizeof(a));
while (!f.eof()){
    if( strcmp(nombre,a.name) == 0 )
    {
cout<<"ingrese el numero numero de telefono "<<endl;
cin>>num;
a.phone=num;
f.seekp(-tamEstruc, ios::cur);
f.write((char *)&a,sizeof(a));
f.read((char *)&a, sizeof(a));
}
   }
f.close();

}

//////3

void guardarContactosCBBA()
{
tipoContacto contacto;
ifstream file;
ofstream fileCBBA;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/archivoContactos.dat",ios::binary);
fileCBBA.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/contactosCBBA.dat",ios::binary);

while(!file.eof() and file.read((char*)&contacto,sizeof(contacto)))
{

    if( strcmp("CBBA",contacto.city) == 0 )
        {
        fileCBBA.write((char *)&contacto,sizeof(contacto));
       }

}
file.close();
fileCBBA.close();
}


void mostrarContactosCBBA()
{
    tipoContacto contacto;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/contactosCBBA.dat",ios::binary);

while(!file.eof() and file.read((char*)&contacto,sizeof(contacto)) )
{
    mostrarContacto(contacto);

}
file.close();

}


//////////4 INFO SOBRE DISEÑOS ) Fecha, hora, nombre del diseñador, nombre del archivo que guarda su diseño

typedef struct
{
int hh,mm,ss;
}tipoHora;

void leerHora(tipoHora &hora)
{
cin>>hora.hh>>hora.mm>>hora.ss;
}
void mostrarHora(tipoHora hora)
{

    cout<<hora.hh<<":"<<hora.mm<<":"<<hora.ss<<endl;
}
typedef struct
{
    tipoFecha fecha;
    tipoHora hora;
    char nombre[TAM];
    char nomArch[TAM];
}tipoInfo;

void leerInfo(tipoInfo &info)
{
    cout<<"fecha "<<endl;
    leerFecha(info.fecha);
     cout<<"hora "<<endl;
    leerHora(info.hora);
    cout<<"nombre "<<endl;
    cin>>info.nombre;
    cout<<"nombre disenio "<<endl;
    cin>>info.nomArch;

}
void mostrarInfo(tipoInfo &info)
{
     cout<<"fecha "<<endl;
    mostrarFecha(info.fecha);
     cout<<"hora "<<endl;
    mostrarHora(info.hora);
    cout<<"nombre "<<endl;
    cout<<info.nombre<<endl;
    cout<<"nombre disenio "<<endl;
    cout<<info.nomArch<<endl;;
}

void crearArchivoInfo(int n)
{

tipoInfo info;
ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/gameInfo.dat",ios::binary);
for(int i=0;i<n;i++)
    {
    leerInfo(info);
    file.write((char *)&info,sizeof(info));

    }
file.close();
}

void mostrarInfoArchivo()
{
    tipoInfo info;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/gameInfo.dat",ios::binary);

while(!file.eof() and file.read((char*)&info,sizeof(info)) )
{
    mostrarInfo(info);

}
file.close();
}

void addInfo(int n){
tipoInfo info;
fstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/gameInfo.dat",ios::binary |ios::app |ios::out);
for(int i=0;i<n;i++){
    leerInfo(info);
    file.write((char *)&info,sizeof(info));

}
file.close();
}


void buscarInfo(char nombre[TAM])
{
tipoInfo info;
ifstream file;

file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/gameInfo.dat",ios::binary);


while(!file.eof() and file.read((char*)&info,sizeof(info)))
{
    if(strcmp(nombre,info.nombre)==0){
    mostrarInfo(info);
       }

}
file.close();
}

void modificarInfo(char nombre[TAM])
{
tipoInfo a;
fstream f;
char newName[TAM];
int tamEstruc= sizeof(tipoInfo);
f.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/binarios/files/gameInfo.dat", ios::binary | ios::in | ios::out);


f.read((char *)&a, sizeof(a));
while (!f.eof()){
        if( strcmp(nombre,a.nombre) == 0 )
    {
    cout<<"ingrese el nuevo nombre de archivo "<<endl;
cin>>newName;
strcpy(a.nombre,newName);
f.seekp(-tamEstruc, ios::cur);
f.write((char *)&a,sizeof(a));
f.read((char *)&a, sizeof(a));
}

}
f.close();

}

int main()
{

/////////1
/*
*/
    int nFechas;
    tipoFecha listaFechas[TAM];
    cout<<"cuantas fechas va a ingresar "<<endl;
    cin>>nFechas;
    crearArchivoFechas(nFechas);
    mostrarArchivoFecha();
    cout<<endl;
        cout<<"todas las fechas del 2020 "<<endl;
    mostrarFechas2020();
    nFechas=0;
cout<<"fechas de primera quincena "<<endl;
FechasQuincena2Struct(listaFechas,nFechas);
mostrarListaFechas(listaFechas,nFechas);

////////2
/*


*/

int nContactos,nuevos;
char apellido[TAM];

cout<<"cuantos contactos va a ingresar "<<endl;
cin>>nContactos;
crearArchivoContactos(nContactos);

cout<<"se guardaron los contactos "<<endl;
mostrarArchivoContacto();

cout<<"cuantos contactos desea añadir "<<endl;
cin>>nuevos;
addContact(nuevos);
cout<<"nueva lista de cotactos "<<endl;
mostrarArchivoContacto();
cout<<endl;
system("pause");
cout<<"ingrese un apellido a buscar"<<endl;
cin>>apellido;
buscarContacto(apellido);


char nombre[TAM];
cout<<"ingrese un nombre a modificar "<<endl;
cin>>nombre;
//modificarContacto(nombre);
cout<<"nueva lista de contactos "<<endl;
//mostrarArchivoContacto();




//////////3
guardarContactosCBBA();
cout<<"datos de CBBA "<<endl;
mostrarContactosCBBA();

/////4
char autor[TAM];
crearArchivoInfo(2);
mostrarInfoArchivo();
cout<<"ingrese un nombre a buscar"<<endl;
cin>>autor;
buscarInfo(autor);
cout<<"desea modificar el archivo "<<endl;
modificarInfo(autor);
cout<<"nueva info "<<endl;
mostrarInfoArchivo();

    return 0;

}
