#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(int _capaciteDuTableau);
	~DynamicArray();
	void setElement( int _index, int _valeur);
	int getElement( int _index);
	 int getCapacite();
	void setCapacite(int _capacite);



private:

	int* tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_