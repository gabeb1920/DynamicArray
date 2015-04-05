/* Name: Gabriel Beedles
* Filename: DynamicArray.h
* Date Modified: 6/4/2015
*
* Purpose: Contains the definition of the template class DynamicArray
*
*/

#include <iostream>

#ifndef _DynamicArray_
#define _DynamicArray_
template <class T>
class DynamicArray {
private:
	T * data;
	int size;
	int capacity;
	void grow();
public:
	// Constructors
	DynamicArray() {
		data = NULL;
		size = 0;
		capacity = 0;
	}
	// Destructor
	~DynamicArray() { if(data != NULL) delete[] data; }
	// Set functions
	void add(T newData);
	// Get functions
	int getSize() { return size; }
	// Overloaded operators
	const T & operator[] (int index) { return data[index]; }
	template <class U>
	friend std::ostream& operator<<(std::ostream& out, DynamicArray<U>& rhs);
};

// Private functions
template <class T>
void DynamicArray<T>::grow() {
	if (capacity == 0) { // This must be the first element in the array
		data = new T[1];
		capacity = 1;
	}
	else {
		// Create a new array with double the size
		T * temp = new T[capacity * 2];
		// Copy the old array into the new one
		for (int i = 0; i < size; ++i)
			temp[i] = data[i];
		// Delete the old array
		delete[] data;
		// Make data point to the new array
		data = temp;
		capacity = capacity * 2;
	}
} // void DynamicArray<T>::grow()

// Set functions
template <class T>
void DynamicArray<T>::add(T newData) {
	if (size >= capacity) // We need to expand the size of the array
		grow();
	// Add in the new element
	data[size] = newData;
	++size;
} // void DynamicArray<T>::add(T newData)

// Overloaded operator functions
template <class T>
std::ostream& operator<<(std::ostream& out, DynamicArray<T>& rhs) {
	for (int i = 0; i < rhs.size; ++i) 
		out << rhs.data[i] << std::endl;

	return out;
} // std::ostream& operator<<(std::ostream& out, const DynamicArray<T>& rhs)
#endif