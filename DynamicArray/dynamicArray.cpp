#include "dynamicArray.h"


DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[100];
	for (int i = 0; i < 100; i++)
	{
		tabElements[i] = 0;

	}
}

DynamicArray::DynamicArray(int _capaciteTableau)
{
	capacite = _capaciteTableau;
	tabElements = new int[_capaciteTableau];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;

	}
}
DynamicArray::~DynamicArray()
{

}

void DynamicArray::setElement( int _index, int _valeur)
{
	tabElements[_index] = _valeur;
}

int DynamicArray::getElement( int _index)
{
	return tabElements[_index];
}

 int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setCapacite( int _capacite)
{
	//tableauTemporaire = new tabElements(_capacite);
int*	tableauTemporaire = new int[_capacite];
for (int i = 0; i < _capacite; i++)
{
	tableauTemporaire[i] = 0;

}
for (int i = 0; i < capacite; i++)
{
tableauTemporaire[i] = tabElements[i];
}
tabElements = tableauTemporaire;
delete tableauTemporaire;
}
