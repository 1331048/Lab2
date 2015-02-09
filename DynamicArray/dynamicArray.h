#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray(const DynamicArray & _source);
	DynamicArray();
	DynamicArray(int _capaciteDuTableau);
	~DynamicArray();
	void setElement( int _index, int _valeur);
	int getElement( int _index);
	 int getCapacite();
	void setCapacite(int _capacite);
	bool operator==(const DynamicArray & _rhs) const;
	void operator+=(const DynamicArray & _rhs);
	DynamicArray& operator=(const DynamicArray & _source);

private:

	int* tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_