#include "dynamicArray.h"
#include <stdexcept>

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
	if (_capaciteTableau < 1)
	{
		throw std::invalid_argument("trop petite valeur");
	}
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
	if (capacite < _index)
	{
		setCapacite(_index+1);
	}

	tabElements[_index] = _valeur;
}

int DynamicArray::getElement( int _index)

{
	if (capacite < _index)
	{
		throw std::out_of_range("Trop grande index");
	}
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
delete tabElements;
capacite = _capacite;
tabElements = tableauTemporaire;

}
