// MySqlTest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <mysql.h>
#include <iostream>


#include "connMySQl.h"

using namespace std;

int main()
{
	int opt = 0;
	
	bool flagDo = true;

	while (flagDo)
	{
		cout << "Selecciona que deseas hacer: " << endl;
		cout << "1.- Insertar un usuario nuevo: " << endl;
		cout << "2.- Checar base de datos: " << endl;
		cout << "3.- Salir del programa: " << endl;

		cin >> opt;

		switch (opt) {

		case 1:
			insertUser();
			break;
		case 2:
			checkDB();
			break;
		case 3:
			flagDo = false;
			break;
		default:
			cout << "opción no disponible" << endl;
			cout << "Deseas volver a intentarlo S/N" << endl;

			cin >> opt;

			if (opt == 'N' || opt == 'n')
				flagDo = false;
		}


	}
	

	return 0;
}