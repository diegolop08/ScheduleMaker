#include <iostream>
#include <string>
#include <array>
#include <sstream>

using namespace std;

/*
***TO DO LIST***
-Encontrar manera de hallar tamanho de arreglos de punteros para materias.
-Para una materia con dos o mas opciones solo muestra el primer codigo depronto es lo mismo que arriba;
*/

void Input(int**** materias,int nmat,string*** strmat) {
	int nop = 0, ndias = 0;
	string wd = " ",name=" ";

	cout << "Suministre la siguiente informacion en orden de importancia por materia\n" << endl;
	for (int i = 0; i < nmat; i++) {
		cout << "Digite nombre de la materia #" << i + 1 << " (Sin espacios): "; cin >> name; cout << endl;
		cout << "================== " << name << " ==================\n"; cout << endl;
		cout << "Digite numero de dias que ve " << name << ": "; cin >> ndias; cout << endl;
		cout << "Digite numero de opciones para " << name << ": "; cin >> nop; cout << endl;
		materias[i] = new int** [nop];
		strmat[i] = new string* [nop];
		for (int j = 0; j < nop; j++) {
			materias[i][j] = new int* [ndias];
			strmat[i][j] = new string [3];
			strmat[i][j][0] = name;
			cout << "====================\nOpcion #" << j + 1<<"\n" << endl;
			cout << "Digite nombre de profesor para esta opcion: "; cin >> strmat[i][j][1]; cout << endl;
			cout << "Digite codigo de esta opcion: "; cin >> strmat[i][j][2]; cout << endl;
			for (int k = 0; k < ndias; k++) {
				materias[i][j][k] = new int[3];
				cout << "==========\nDia #" << k+1 << ":\n" << endl;
				cout << "1)Lunes\n2)Martes\n3)Miercoles\n4)Jueves\n5)Viernes\n\nDigite: "; cin >> materias[i][j][k][0]; cout << endl;
				switch (materias[i][j][k][0])
				{
				case 1:
					wd = "Lunes";
					break;
				case 2:
					wd = "Martes";
					break;
				case 3:
					wd = "Miercoles";
					break;
				case 4:
					wd = "Jueves";
					break;
				case 5:
					wd = "Viernes";
					break;
				default:
					break;
				}
				cout << "Digite hora de comienzo para el " << wd << ": "; cin >> materias[i][j][k][1]; cout << endl;
				cout << "Digite hora de finalizacion para el " << wd << ": "; cin >> materias[i][j][k][2]; cout << endl;
				
			}
		}
		cout << "==========================================================================" << endl;
	}
	cout << "=======================================================================================\n" << endl;
}

void codeInfo(int**** materias, string*** strmat, int nmat) {
	string codigo=" ";
	int mat = 0, op = 0, ni = 0;;
	bool v=false,another=false;

	do
	{
		another = false;
		cout << "Ingrese codigo de la materia: "; cin >> codigo; cout << endl;

		for (int i = 0; i < nmat; i++) {
			for (int j = 0; j < (sizeof(strmat[i]) / sizeof(strmat[i][0])); j++) {
				if (strmat[i][j][2] == codigo) {
					mat = i;
					op = j;
					v = true;
					break;
				}
				if (v)
					break;
			}
		}

		if (v) {
			cout << "===============\nCodigo: " << strmat[mat][op][2]; cout << endl;
			cout << "Nombre materia: " << strmat[mat][op][0] << endl;
			cout << "Nombre profesor: " << strmat[mat][op][1] << endl;
			cout << "\nHorario:" << endl;

			cout << sizeof(materias[mat][op]) << endl;
			cout << sizeof(materias[mat][op][0]) << endl;
			cout << sizeof(materias[mat][op]) / sizeof(materias[mat][op][0]) << endl;

			for (int k = 0; k < (sizeof(materias[mat][op]) / sizeof(materias[mat][op][0])); k++)
			{
				switch (materias[mat][op][k][0])
				{
				case 1:
					cout << "Lunes: ";
					break;
				case 2:
					cout << "Martes: ";
					break;
				case 3:
					cout << "Miercoles: ";
					break;
				case 4:
					cout << "Jueves: ";
					break;
				case 5:
					cout << "Viernes: ";
					break;
				default:
					break;
				}
				cout <<"\t"<< materias[mat][op][k][1] << ":00\t-\t" << materias[mat][op][k][2] << ":00" << endl;
			}
			cout << "===============" << endl;
			cout << "\n\nDesea buscar otra materia por codigo? (1. Si || 0. No): "; cin >> ni; cout << endl;
			if (ni == 1)
				another = true;
			else
				another = false;
		}
		else {
			cout << "Codigo no encontrado, por favor intente de nuevo" << endl;
			another = true;
		}

	} while (another);


}

void menuInfo(int**** materias,string*** strmat,int nmat) {
	int opcion = 0;

	do
	{
		cout << "============INFO============\n" <<
			"1) Busqueda por codigo\n" <<
			"2) Busqueda manual\n" <<
			"0) Atras\n" <<
			"Digite opcion: " << endl; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
			codeInfo(materias, strmat, nmat);
			break;
		case 2:
			//Info(materias, strmat, nmat);
			break;
		case 0:
			break;
		default:
			cout << "Opcion no disponible, por favor intente de nuevo" << endl;
			break;
		}
	} while (opcion != 0);
}

void AC(int**** materias, string*** strmat,string** sch,int nmat) {

	
	for (int i = 0; i < nmat; i++) {
		for (int j = 0; j < (sizeof(strmat[i]) / sizeof(strmat[i][0])); j++)
			delete[] strmat[i][j];
	}	
	delete[] strmat;
	
	for (int i = 0; i < 14; i++)
		delete[] sch[i];
	delete[] sch;

	for (int i = 0; i < nmat; i++) {
		

		for (int j = 0; j < (sizeof(materias[i]) / sizeof(materias[i][0])); j++) {

			for (int k = 0; k < (sizeof(materias[i][j]) / sizeof(materias[i][j][0])); k++)
				delete[] materias[i][j][k];

			delete[] materias[i][j];

		}
		delete[] materias[i];
	}
	delete[] materias;
}

void clean(string** x) {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 6; j++) {
			x[i][j] = " ";
		}
	}
}

void draw(string** x) {

	for (int i = 0; i < 14; i++) {
		//cout << "\t\t";
		for (int j = 0; j < 6; j++) {
			cout << x[i][j]<<"\t\t";
		}
		cout << endl;
		cout << endl;
	}
}

void headers(string** x) {
	clean(x);
	for (int i = 0; i < 14; i++) {

		x[i][0] = to_string(i+6)+"-"+to_string(i+7);

		switch (i)
		{
		case 0:
			x[0][i] = "@";
			break;
		case 1:
			x[0][i] = "Lunes";
			break;
		case 2:
			x[0][i] = "Martes";
			break;
		case 3:
			x[0][i] = "Mierco";
			break;
		case 4:
			x[0][i] = "Jueves";
			break;
		case 5:
			x[0][i] = "Viernes";
			break;
		default:
			break;
		}
	}
}

void Lineal() {
	int nmat = 0, opcion = 0;
	//sch: Dibujo
	//strmat: [Nombre, Profe, Codigo]
	//materias: Materias-->Opciones-->Dias-->[Dia semana,Start,Finish]

	cout << "Digite numero de materias que va a inscribir este semestre: "; cin >> nmat; cout << endl;
	int**** materias = new int*** [nmat];
	string*** strmat = new string ** [nmat];

	string** sch = new string* [14];
	for (int i = 0; i < 14; i++)
		sch[i] = new string[6];
	clean(sch);
	headers(sch);

	Input(materias, nmat,strmat);

	do
	{
		cout << "============MENU============\n"<<
				"1) Horarios disponibles\n"<<
				"2) Informacion de materias\n"<<
				"0) Salir\n"<<
				"Digite opcion: " << endl; cin >> opcion;
		switch (opcion)
		{
		case 1:
			//schMaker();
			break;
		case 2:
			menuInfo(materias,strmat,nmat);
			break;
		case 0:
			cout << "\n\nGracias por utilizar Schedule Maker by Diego Lopez" << endl;
			break;
		default:
			cout << "Opcion no disponible, por favor intente de nuevo" << endl;
			break;
		}
	} while (opcion!=0);


	AC(materias,strmat,sch,nmat);
	
}

int main() {

	Lineal();

	return 0;
}