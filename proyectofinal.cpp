// ProyectoFinal.cpp : Defines the entry point for the console application.
//


/*
Noe Amador Campos Castillo 	A00820323
Angel Odiel Treviño Villanueva	A01336559
21 de noviembre 2016
LOC:
*/

#include "stdafx.h"
#include <iostream>

using namespace std;




void Quitar(int iFelix[35][35]) {
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			if (iFelix[i][j] == 0) {
				cout << ' ';
			}
			else {
				cout << iFelix[i][j];
			}
		}
		cout << endl;
	}
}

void DesplegarOriginal(int iFelix[35][35]) {
	Quitar(iFelix);
	cout << endl;
}

void RotarDerecha(int iFelix[35][35], int iDireccion[35][35]) {
	int iR = 0;
	int iC = 34;
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			iDireccion[iR][iC] = iFelix[i][j];
			iR++;
		}
		iC--;
		iR = 0;
	}
	Quitar(iDireccion);
}

void RotarIzquierda(int iFelix[35][35], int iDireccion[35][35]) {
	int iR = 34;
	int iC = 0;
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			iDireccion[iR][iC] = iFelix[i][j];
			iR--;
		}
		iC++;
		iR = 34;
	}
	Quitar(iDireccion);
}

void FlipHorizontal(int iFelix[35][35], int iDireccion[35][35]) {
	int iR = 34;
	int iC = 0;
	for (int j = 0; j < 35; j++) {
		for (int i = 0; i < 35; i++) {
			iDireccion[iR][iC] = iFelix[i][j];
			iR--;
		}
		iC++;
		iR = 34;
	}
	Quitar(iDireccion);
}

void FlipVertical(int iFelix[35][35], int iDireccion[35][35]) {//flip a la izquierda, no se como hice esto
	int iR = 0;
	int iC = 34;
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			iDireccion[iR][iC] = iFelix[j][i];
			iR++;
		}
		iC--;
		iR = 0;
	}

	Quitar(iDireccion);

}

void Negativo(int iFelix[35][35], int iDireccion[35][35]) {
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			if (iFelix[i][j] == 0)
				iDireccion[i][j] = 1;
			else if (iFelix[i][j] == 1)
				iDireccion[i][j] = 0;

		}
	}
	Quitar(iDireccion);
}

void RepararFelix(int iFelix[35][35], int iDireccion[35][35]) {
	for (int i = 0; i < 35; i++) {
		for (int j = 0; j < 35; j++) {
			iDireccion[i][j] = iFelix[i][j];
		}
	}
}

void MirrorHorizontal(int iFelix[35][35], int iDireccion[35][35]) {
	int iR = 34;
	int iC = 0;
	for (int j = 0; j < 35; j++) {
		for (int i = 0; i < 35 / 2; i++) {
			iDireccion[iR][iC] = iFelix[i][j];
			iR--;
		}
		iC++;
		iR = 34;
	}
	Quitar(iDireccion);
}

void MirrorVertical(int iFelix[35][35], int iDireccion[35][35]) {
	int iR = 0;
	int iC = 34;
	for (int j = 0; j < 35 / 2; j++) {
		for (int i = 0; i < 35; i++) {
			iDireccion[iR][iC] = iFelix[i][j];
			iR++;
		}
		iC--;
		iR = 0;
	}
	Quitar(iDireccion);

}

void Menu(int iFelix[35][35], int iDireccion[35][35])
{
	char cUsuario, cGiro;
	cout << "*****************************************" << endl;
	cout << "Noe Amador Campos Castillo \tA00820323" << endl;
	cout << "Angel Odiel Treviño Villanueva \tA01336559" << endl;
	cout << "*****************************************" << endl;
	cout << endl;

	cout << "El es el Gato Felix!" << endl;
	cout << endl;
	DesplegarOriginal(iFelix);

	do {
		cout << "Como lo quieres girar?" << endl;

		cout << "\n   Tipo de Giro                    Clave " << endl;
		cout << "*****************************************" << endl;
		cout << "*     Derecha                       A   *" << endl;
		cout << "*    Izquierda                      B   *" << endl;
		cout << "* Flip Horizontal                   C   *" << endl;
		cout << "*  Flip Vertical                    D   *" << endl;
		cout << "*    Negativo                       E   *" << endl;
		cout << "* Mirror Horizontal                 F   *" << endl;
		cout << "* Mirror Vertical                   G   *" << endl;
		cout << "*****************************************" << endl;
		cout << "Clave = ";
		cin >> cGiro;

		cout << endl;
		switch (toupper(cGiro))
		{
		case 'A':  RotarDerecha(iFelix, iDireccion); break;
		case 'B':  RotarIzquierda(iFelix, iDireccion); break;
		case 'C':  FlipHorizontal(iFelix, iDireccion); break;
		case 'D':  FlipVertical(iFelix, iDireccion); break;
		case 'E':  Negativo(iFelix, iDireccion); break;
		case 'F':  RepararFelix(iFelix, iDireccion); MirrorHorizontal(iFelix, iDireccion); break;
		case 'G':  RepararFelix(iFelix, iDireccion); MirrorVertical(iFelix, iDireccion); break;
		}
		cout << endl;

		cout << "\nQuieres volver a intentarlo? (S/N) ";
		cin >> cUsuario;
		cout << endl;

	} while (toupper(cUsuario) == 'S');

	cout << "Adios! Hasta Luego!" << endl;
}


int main() {
	// Proyecto Final...
	// Para realizar tu Proyecto, por favor copia este código en tu programa
	// Esta será la definición inicial de la imagen de la matriz para trabajar
	int iDireccion[35][35];
	int iFelix[35][35] = { { 1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1 },
	{ 1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1 },
	{ 1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1 },
	{ 1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,1 },
	{ 1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1 },
	{ 1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,0 },
	{ 1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0 },
	{ 1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0 },
	{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1,0 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,0 },
	{ 1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0 },
	{ 1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,0,0 },
	{ 1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1 },
	{ 1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1 },
	{ 1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1 },
	{ 1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1 },
	{ 1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1 },
	{ 1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 } };

	Menu(iFelix, iDireccion);
	//system("pause");

	return 0;
}
