#include <iostream>
#include <fstream>
#define TAM 100
using namespace std;

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
//////////////7

typedef struct {

int ci;
char nombre[TAM];
int nota;

tipoFecha fechaExamen;

} tipoAlumno;
void leerAlumno(tipoAlumno &alumno)
{
    cout<<"ci: ";
    cin>>alumno.ci;
    cout<<"nombre: ";
     cin>>alumno.nombre;
    cout<<"nota: ";
     cin>>alumno.nota;
    cout<<"fecha examen : ";
    leerFecha(alumno.fechaExamen);

}

void mostrarAlumno(tipoAlumno alumno)
{
    cout<<"ci: "; cout<<alumno.ci<<endl;
    cout<<"nombre: "; cout<<alumno.nombre<<endl;
    cout<<"nota: "; cout<<alumno.nota<<endl;
    cout<<"fecha examen : "; mostrarFecha(alumno.fechaExamen);
    cout<<endl;
}


void crearArchivoAlumnos(int n)
{
    tipoAlumno alumno;

ofstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
for(int i=0;i<n;i++){
    leerAlumno(alumno);
    file.write((char *)&alumno,sizeof(alumno));

}
file.close();
}

void mostrarArchivoAlumnos()
{

    tipoAlumno alumno;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    mostrarAlumno(alumno);
}
file.close();
}

float calcularPromedio(int numCi)
{
    tipoAlumno alumno;
ifstream file;
float suma=0,cont=0,promedio;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    if(alumno.ci==numCi){
   suma=suma+alumno.nota;
   cont++;
   }
}
promedio=suma/cont;
file.close();
return promedio;

}

int contarNotasAltas()
{
    tipoAlumno alumno;
ifstream file;
int cont=0;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    if(alumno.nota==100){
   cont++;
   }
}
file.close();
return cont;

}


void crearArchivosDeResultados()
{
    ofstream archAprobados;
    ofstream archReprobados;
    ifstream file;
        tipoAlumno alumno;

    file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
    archAprobados.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnosAprobados.dat",ios::binary);
    archReprobados.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnosReprobados.dat",ios::binary);

while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)))
{

    if(alumno.nota>50)
        {
        archAprobados.write((char *)&alumno,sizeof(alumno));
       }
       else
        {
            archReprobados.write((char *)&alumno,sizeof(alumno));
        }

}

archAprobados.close();
archReprobados.close();
file.close();

}


void mostrarArchivoAlumnosAprobados()
{

    tipoAlumno alumno;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnosAprobados.dat",ios::binary);
while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    mostrarAlumno(alumno);
}
file.close();
}

void mostrarArchivoAlumnosReprobados()
{

    tipoAlumno alumno;
ifstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnosReprobados.dat",ios::binary);
while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    mostrarAlumno(alumno);
}
file.close();
}

void ordenarInsercionDirecta(tipoAlumno vec[],int n){
int posPrimDes, elemAins, o;
for (posPrimDes=1;posPrimDes<n;posPrimDes++){
elemAins=vec[posPrimDes].nota;
//INSERTAR elemAins en los ordenados
o=posPrimDes-1;
//o es el indice que recorrera los ordenados
while (elemAins <vec[o].nota && o>-1){
vec[o+1].nota=vec[o].nota;
o=o-1;
}
vec[o+1].nota=elemAins;
}
}


void ordenarXinsercion()
{

        tipoAlumno alumnos[TAM];
        tipoAlumno alumno;
        int n=0;
fstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);


while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    alumnos[n]=alumno;
    n++;
}
file.close();

ordenarInsercionDirecta(alumnos,n);

file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
for(int i=0;i<n;i++){
    file.write((char *)&alumnos[i],sizeof(alumnos[i]));
}
file.close();

}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(tipoAlumno arr[], int n)
{
    int i, j, min_idx;

    // recorrido del vector desordenado
    for (i = 0; i < n-1; i++)
    {
        // hallar el minimo
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j].nota < arr[min_idx].nota)
            min_idx = j;

        // intercambiar el menor y el primero
        swap(&arr[min_idx].nota, &arr[i].nota);
    }
}


void ordenarXSeleccion()
{

        tipoAlumno alumnos[TAM];
        tipoAlumno alumno;
        int n=0;
fstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);


while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    alumnos[n]=alumno;
    n++;
}
file.close();

selectionSort(alumnos,n);

file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
for(int i=0;i<n;i++){
    file.write((char *)&alumnos[i],sizeof(alumnos[i]));
}
file.close();

}


void bubbleSort(tipoAlumno arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j].nota > arr[j+1].nota)
            swap(&arr[j].nota, &arr[j+1].nota);
}

void ordenarXburbuja()
{

        tipoAlumno alumnos[TAM];
        tipoAlumno alumno;
        int n=0;
fstream file;
file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);


while(!file.eof() and file.read((char*)&alumno,sizeof(alumno)) )
{
    alumnos[n]=alumno;
    n++;
}
file.close();

bubbleSort(alumnos,n);

file.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat",ios::binary);
for(int i=0;i<n;i++){
    file.write((char *)&alumnos[i],sizeof(alumnos[i]));
}
file.close();

}


void mostrarArchivoAlumnosInvertido()
{


 ifstream f2;
f2.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnos.dat", ios::ate );
int tamEnBytes = f2.tellg();
int cantRegs=tamEnBytes/sizeof(tipoAlumno);
f2.close();
tipoAlumno a; ifstream f1;
f1.open("E:/clases +/SEM II/PROGRA1/Trabajos/archivos binarios/practica archivos binarios/ejercicio7/files/archivoAlumnosInvertido.dat", ios::binary);
f1.seekg(0, ios::end);
int tamEstruc= sizeof(tipoAlumno);
f1.seekg(-tamEstruc, ios::cur);
for (int i=cantRegs-1 ; i>=0;i--){
f1.read((char *)&a, sizeof(a));
mostrarAlumno(a);
f1.seekg(-tamEstruc*2, ios::cur);
}
f1.close();




}

int main()
{
    int nAlumnos;
      int ci;

    cout<<"cuantos alumnos va a ingresar? "; cin>>nAlumnos;
    crearArchivoAlumnos(nAlumnos);

    cout<<"se creo el siguiente archivo "<<endl;
    mostrarArchivoAlumnos();
    cout<<"ingrese un CI "<<endl;
    cin>>ci;
    cout<<"promedio: ";
    cout<<calcularPromedio(ci)<<endl;
    cout<<"hubieron "<<contarNotasAltas()<<" examenes de 100" <<endl;


crearArchivosDeResultados();
cout<<"alumnos aprobados "<<endl;
mostrarArchivoAlumnosAprobados();
cout<<"alumnos reprobados: "<<endl;
mostrarArchivoAlumnosReprobados();


ordenarXinsercion();
ordenarXSeleccion();
ordenarXburbuja();
cout<<"alumnos ordenados "<<endl;
mostrarArchivoAlumnos();


mostrarArchivoAlumnosInvertido();

    return 0;
}
