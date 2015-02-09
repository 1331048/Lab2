#include "dynamicArray.h"
#include <stdexcept>


DynamicArray::DynamicArray(const DynamicArray & _source)
	:capacite(_source.capacite), tabElements(new int[_source.capacite])
{
	{
		for (int i = 0; i < capacite; i++){
			tabElements[i] = _source.tabElements[i];
		}
	}

}
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

void DynamicArray::setElement(int _index, int _valeur)
{
	if (capacite < _index)
	{
		setCapacite(_index + 1);
	}

	tabElements[_index] = _valeur;
}

int DynamicArray::getElement(int _index)

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

void DynamicArray::setCapacite(int _capacite)
{
	if (_capacite > 0){


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
	else
	{
		throw std::invalid_argument("Trop petite capacité");
	}

}
DynamicArray& DynamicArray::operator=(const DynamicArray & _operatorSourceEgal) {
	if (&_operatorSourceEgal != this)
	{
		delete[] tabElements;
		this->capacite = _operatorSourceEgal.capacite;
		this->tabElements = new int[this->capacite];
		for (unsigned int i = 0; i < this->capacite; i++)
		{
			this->tabElements[i] = _operatorSourceEgal.tabElements[i];
		}
	}
	return *this;
}
bool DynamicArray::operator==(const DynamicArray & _operatorSourceEgalEgal) const{
	//je ne suis pas sur si cela marche mais de ce que j'ai lu oui
	if (this->capacite != _operatorSourceEgalEgal.capacite){
		return false;
	}

	for (int i = 0; i < this->capacite; i++){
		if (this->tabElements[i] != _operatorSourceEgalEgal.tabElements[i]){
			return false;
		}
	}

	return true;
}
void DynamicArray::operator+=(const DynamicArray & _operatorSourceEgalPlus) {
	int oldCapacite = this->capacite;
	int newCapacite = oldCapacite + _operatorSourceEgalPlus.capacite;
	this->setCapacite(newCapacite);
	int compteur = 0;
	for (int i = oldCapacite; i < newCapacite; i++){
		this->setElement(i, _operatorSourceEgalPlus.tabElements[compteur]);
		compteur++;
	}

}


