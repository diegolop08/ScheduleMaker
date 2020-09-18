#pragma once

class Materia{
private:

public:
	Materia();
	Materia(int IH);	// IH:intensidad horaria(dias) 
	~Materia();

	int mDias;
	int** Days = new int* [mDias];

};