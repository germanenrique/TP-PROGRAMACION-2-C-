#include "stdafx.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
using namespace System;
using namespace System::IO;


public class Persona
{
protected:
	char nombre[20];
	char apellido[20];
	char posicion[20];
	char phabil[10];


public:

	void establecer();
	virtual double Valor(double jugador);
	virtual void mostrar();
	char* guardados1();
	char* guardados2();
	char* guardados3();
	char* guardados4();


};

double Persona::Valor(double b)
{
	return 0;
}

void Persona::mostrar()
{

}

void Persona::establecer()
{
	cout << "Ingrese el nombre del jugador\n";
	cin >> nombre;
	cout << "Ingrese el apellido del jugador\n";
	cin >> apellido;
	cout << "Ingrese la posicion del jugador\n";
	cin >> posicion;
	cout << "Ingrese la pierna habil del jugador\n";
	cin >> phabil;

}

char* Persona::guardados1()
{

	return nombre;

}

char* Persona::guardados2()
{

	return apellido;
}

char* Persona::guardados3()
{

	return posicion;
}

char* Persona::guardados4()
{

	return phabil;
}

class PrimeraA : public Persona
{
private:

	;
public:
	virtual double valor(double jugador);
	virtual void mostrar();

};

class PrimeraB : public Persona
{
private:


public:
	virtual double valor(double jugador);
	virtual void mostrar();

};

void PrimeraA::mostrar()
{
	cout << "Jugador de primera A, su nombre es ";
	cout << nombre;
	cout << "y juega de  ";
	cout << posicion;

}
void PrimeraB::mostrar()
{
	cout << "Jugador de primera B, su nombre es ";
	cout << nombre;
	cout << "y juega de  ";
	cout << posicion;

}

Double PrimeraA::valor(double jugador)
{
	double valor;
	valor = jugador * 2;
	return valor;
}
Double PrimeraB::valor(double jugador)
{
	double valor;
	valor = jugador * 1.25;
	return valor;
}

//void leerArchivo1()
//{
//	archivo.open("datos.txt", ios::in);
//
//		if (archivo.is_open() ) {
//			string linea;
//			while (getline(archivo, linea))
//			{
//				cout << linea << endl;
//			}
//			archivo.close();
//		}
//		else
//		{
//			cout << "No se puedo abrir el archivo";
//		}
//		
//}



int main()
{
	cout << "-----------------------------------------------------------------\n";

	cout << "BIENVENIDO AL SISTEMA DE CARGA DE JUGADORES DE PRIMERA A Y B\n";

	cout << "-----------------------------------------------------------------\n";

	cout << "IMPORTANTE: A LOS JUGADORES DE PRIMERA A EL VALOR SE AUMENTARA UN 100 % Y A LOS JUGADORESDE PRIMERA B UN 25 %\n";

	string usuario;


	cout << "Ingrese el codigo para utilizar el sistema\n";
	cin >> usuario;
	if (usuario == "messi")
	{
	
	


		int decision = 0;
		int primerwhile = 0;
		int segundowhile = 0;
		int tercerwhile = 0;

		char nombres[20] = "";
		char apellido[20] = "";
		char posicion[20] = "";
		char phabil[20] = "";

		double valor = 0;

		int capturardatos = 0;

		char guardado[400] = "";

		double valorfinal = 0;

		Persona Jugador;
		fstream archivo;


		while (primerwhile == 0)
		{
			cout << "Ingresa la divison del jugador: 1 para primera A / 2 para primera B/ 3 para listado de jugadores \n";
			cin >> decision;

			cout << "-----------------------------------------------------------------------------------------\n";
			if (decision == 1)
			{
				PrimeraA jugadorA;

				while (segundowhile == 0)
				{
					cout << "Que desea hacer? (1) Agregar / (2) Listar / (3) Valorar / (4) Salir  \n";;
					cout << "-----------------------------------------------------------------------------------------\n";
					cin >> decision;

					switch (decision)
					{
					case 1:
						jugadorA.establecer();
						capturardatos = 1;
						break;

					case 2:
						if (capturardatos == 0)
						{
							cout << "Ingrese los datos\n";

						}
						else
						{
							jugadorA.mostrar();
						}
						break;
					case 3:
						if (capturardatos == 0)
						{
							cout << "Ingrese los datos\n";
						}
						else
						{

							cout << "Ingrese el valor del jugador \n";
							cin >> valor;
							valorfinal = jugadorA.valor(valor);
							archivo.open("Jugadores.txt", ofstream::app);
							archivo << "Nombre: " << jugadorA.guardados1();
							archivo << " Apellido: " << jugadorA.guardados2();
							archivo << "Posicion: " << jugadorA.guardados3();
							archivo << "PiernaHabil: " << jugadorA.guardados4();
							archivo << " Monto: " << valorfinal;
							archivo << " Tipo: Jugador A" << endl;
							archivo.close();


						}
						break;
					case 4:
						segundowhile = 1;
						break;
					}
					cout << "Salir? (2) si / (0) no \n";
					cin >> segundowhile;
					decision = 0;
				}
			}

			if (decision == 2)
			{
				PrimeraB jugadorB;
				while (segundowhile == 0)
				{
					cout << "Que desea hacer? (1) Agregar / (2) Listar / (3) Valorar / (4) Salir  \n";

					cin >> decision;
					cout << "-----------------------------------------------------------------------------------------\n";
					switch (decision)
					{
					case 1:
						jugadorB.establecer();

						capturardatos = 1;
						break;
					case 2:
						if (capturardatos == 0)
						{
							cout << "Ingrese los datos\n";
						}
						else
						{
							jugadorB.mostrar();
						}
						break;
					case 3:
						if (capturardatos == 0)
						{
							cout << "Primero debe ingresar los datos\n";
						}
						else
						{
							cout << "Ingrese el valor \n";
							cin >> valor;
							valorfinal = jugadorB.valor(valor);

							archivo.open("Jugadores.txt", ofstream::app);





							archivo << "Nombre: " << jugadorB.guardados1();
							archivo << " Apellido: " << jugadorB.guardados2();
							archivo << " Posicion : " << jugadorB.guardados3();
							archivo << " PiernaHabil: " << jugadorB.guardados4();
							archivo << " Valor: " << valorfinal;

							archivo << " Tipo: Jugador B" << endl;



							archivo.close();

						}


						break;
					case 4:
						segundowhile = 1;
						break;
					}
					cout << "Salir? (2) si / (0) no\n";
					cout << "-----------------------------------------------------------------------------------------\n";
					cin >> segundowhile;
					decision = 0;

				}
			}
			if (decision == 3)
			{
				String^ archivo = "Jugadores.txt";
				try
				{
					Console::WriteLine("Cagargando el archivo {0}...", archivo);
					cout << "-----------------------------------------------------------------------------------------\n";
					StreamReader^ din = File::OpenText(archivo);
					String^ str;

					while ((str = din->ReadLine()) != nullptr)
					{
						Console::WriteLine("{0}", str);
					}
				}
				catch (Exception^ e)
				{
					Console::WriteLine("Problemas leyendo el archivo'{0}'", archivo);
				}
				cout << "Presione cualquier tecla para continuar\n";
				Console::ReadKey();
			}
			cout << "Desea finalizar? (0) no / (1) si\n";
			cout << "-----------------------------------------------------------------------------------------\n";
			cin >> primerwhile;
			if (primerwhile == 0)
			{
				segundowhile = 0;
			}
		}
	}
	else
	{
		cout << "";
		cout << "CONTRASEÑA INCORRECTA EL SISTEMA SE CERRARA\n";

		exit(0);
	}
	/*leerArchivo1();*/
	system("pause");
}