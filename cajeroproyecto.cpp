//Por naturaleza del programa, este no se presta a hacer elimninaciones o cambios en los ficheros dentro de su ejecución.

//Bibliotecas necesarias para el funcionamiento del programa
#include <iostream>    //Algoritmos estandar.
#include <stdlib.h>    //Biblioteca estandar para le manejo de funciones, procesos en general.
#include <stdio.h>     //Bibloteca de entrada y salida.
#include <time.h>      //Marca el tiempo desde su ejecucion, se puede usar para conocer el tiempo del ordenador.
#include <fstream>     //Permite manipular archivos desde el programa, podemos escribir en ellos y leer su contenido.
#include <string>      //Muestra objetos de secuencia de caracteres.

using namespace std;

//Estructura de arreglos.

struct RegistroCajero
{
    char ni[50];
    char ai[50];
    int digitos;
    int clave;
    int recordarClaveR;
    int recordarClaveI;
    int cd;
    int cr;
    int saldoD;
    int saldoR;
    int saldo_base = 1000;
}registro[20];

//Variables globales

int suma_resta= 0;
int i= 0;

//Protipos de funciones

void imprimir(); //Imprime los resultados de ingresos y egresos
void menu();    //Menu de opciones del sistema
void limpiar(); //Limpieza de entradas y salidas
void tiempo();  //Muestra el tiempo y fecha real del ordenador
void ingreso(); //Permite depositar cantidad de dinero en su cuenta
void retiro();  //Permite retirar cantidad de dinero de su cuenta
void login();   //Inicio de sesión del usuario
void salir();   //Permite salir del sistema (cerrar sesion)

//Función principal
int main(){
    system("color 70");     //Cambio de color a la consola.
    login();
}

//Menu de opciones

void menu()
{
    int opc;
    system("cls"); //Limpiar pantalla
    tiempo();

    cout<<"\t\t\t-------------------------------------\n";
    cout<<"\t\t\t| Bienvenido a su Cajero automatico |\n";
    cout<<"\t\t\t-------------------------------------\n";

    cout<<"\n1- Ingreso";
    cout<<"\n2- Retiro";
    cout<<"\n3- Consulta e Historial";
    cout<<"\n4- Cerrar sesion";
    cout<<"\nSeleccione una opcion: ";
    cin >> opc;
    system("cls");

    switch(opc)
    {
        case 1:
            ingreso();
                    break;
        case 2:
            retiro();
                    break;
        case 3:
            imprimir();
                    break;
        case 4:
            salir();
                    break;
        default:
            cout<<"Opcion incorrecta. Intente seleccionar una opcion del 1 - 4"<<endl;
            system("pause");
            };
            menu();
}

//Inicio de sesion y registro de usuario

void login()
{
    int j;
    tiempo();

    ofstream archivo("DatosUsuario.txt"); //Apertura del fichero para escribir en él

    for(int j=1; j<4;j++){

    cout << "\t\t\t--------------------\n";
    cout << "\t\t\t|    Iniciando...  |\n";
    cout << "\t\t\t--------------------\n";

        cout<<"\t\t\t-Iniciar sesion-\n"<<endl;

        cout<<"\nIngrese su nombre: ";
        limpiar();
        cin>>registro[i].ni;
        archivo<<"Nombre: "<<registro[i].ni;        //Registro de nombre en ficherp

        cout<<"\nIngrese su apellido: ";
        limpiar();
        cin>>registro[i].ai;                        //Registro de apellido en ficherp

        archivo<<endl<<"Apellido: "<<registro[i].ai;

        archivo.close();                   //Cerrar el fichero

            cout << "\t\t\t----------------------------\n";
            cout << "\t\t\t|  Ingrese su clave        |\n";
            cout << "\t\t\t----------------------------\n";
            cin>>registro[i].recordarClaveR;
            cout << "\t\t\t-----------------------------\n";
            cout << "\t\t\t| Ingrese su clave nuevamente\n";
            cout << "\t\t\t-----------------------------\n";
            cin>>registro[i].recordarClaveI;

        if(registro[i].recordarClaveR==registro[i].recordarClaveI){
        menu();
        }

        else{
            if(registro[i].recordarClaveR!=registro[i].recordarClaveI){
        cout << "Clave incorrecta. Porfavor intente iniciar sesion nuevamente... " << endl;
        system("pause");
        system("cls");
        }
    }
             if(j == 3){
                cout << "Ha realizado 3 intentos, por seguridad el sistema se cerrara..." << endl; //Esto hace que solo pueda intentar entrar 3 veces
                exit(0);
}
}
}


//Función para ingresar dinero a su cuenta haciendo uso del fichero

void ingreso()
{
    system("cls");
    tiempo();

    ofstream archivo("DatosUsuario.txt", ios::app); //Apertura del fichero

    suma_resta = suma_resta + registro[i].cd;
    cout<<"Usted solo puede depositar 3 veces por dia.."<<endl;
    cout<<"La cantidad disponible es "<<registro[i].saldo_base + suma_resta;
    cout<<"\nIngrese la cantidad a depositar: ";
    cin>>registro[i].cd;

    registro[i].saldoD = registro[i].saldo_base + registro[i].cd;
    system("cls");

    cout<<"\nEl saldo final de la cuenta es: "<<registro[i].saldoD + suma_resta<< endl;
    cout<< "---------------------------------------" << endl;
    cout<< "Deposito realizado..." << endl;

    archivo<<endl<<"Deposito: "<<registro[i].cd<<endl; //Se guardan los datos ingresados en el fichero
    archivo<<"Saldo total: "<<registro[i].saldoD + suma_resta<<endl;
    archivo.close();                                   //Cerrar el fichero

    system("pause");
    system("cls");
    menu();
}

//Función para ingresar dinero a su cuenta haciendo uso del fichero

void retiro()
{
    system("cls");
    tiempo();

    ofstream archivo("DatosUsuario.txt", ios::app); //Apertura del ficher

    cout<<"Usted solo puede retirar 3 veces por dia.."<<endl;
    cout<<"La cantidad disponible es "<<registro[i].saldoD;
    cout<<"\nIngrese cantidad a retirar: ";
    cin>>registro[i].cr;
    registro[i].saldoR = registro[i].saldoD - registro[i].cr;
    system("cls");
    cout<<"\nEl saldo final de la cuenta es: "<<registro[i].saldoR<< endl;
    cout<< "---------------------------------------" << endl;
    cout<< "Retiro realizado..." << endl;


    archivo<<endl<<"Retiro: "<<registro[i].cr<<endl;    //Se guardan los datos retirados en el fichero
    archivo<<"Saldo total: "<<registro[i].saldoR<<endl;
    archivo.close();                                    //Cerrar el fichero

    system("pause");
    system("cls");

    menu();



}

//Función que imprime en pantalla los datos anteriormente ingresdos y guarda en el fichero

void imprimir()
{
     tiempo();

    ifstream archivo ("DatosUsuario.txt"); //Apertura del fichero para leer sus datos

    string informacion;

    while (!archivo.eof())    //Mientras no sea el final del archivo
    {
        getline(archivo,informacion);
        cout << informacion << endl;    //Salida de datos ingresados anteriormente

    }

    archivo.close();    //Cerrar el fichero
    system("pause");


    cout <<"Datos impresos correctamente "<<endl;
    system("pause");
    menu();

}

//Funcion para cerrar sesion y salir del programa

void salir()
{
    tiempo();
    cout << "\nGracias por usar nuestro cajero..." << endl << endl;
    system("pause");
    exit(0);
}

//Funcion para tomar la fecha y hora del ordenador, y mostrarla en pantalla

void tiempo()
{
    time_t t,i;
	char *p;        //Punteros - *p variable cuya direccion esta almacenada en p
	i = time (&t);  //Punteros - &t la dirección de t
	p = ctime (&i); //Punteros - &i la dirección de i

	cout<< "\t\t\t\t\t\t\t\t\t\t\t"<<p;     //impresion de direccion de memoria
}

//Función para eliminar los buffers que quedan al dar un enter o espacio

void limpiar()
{
    fflush(stdin);
    fflush(stdout);
}

