#include "stdafx.h"
#include ".\\lib\\h.h"
#include <windows.h>
#define MY_DLL __declspec(dllexport)

int main() {
	string archivo; 
	archivo = "PS0905JN";
	Muestra myMuestra = archivo;
	float prueba;
	prueba = myMuestra.promedioSimple("Fe");
	cout << "\n" + to_string(prueba) + "\n--------------------><-------------------- \n\n";
	cin.get();
	return 0;
}