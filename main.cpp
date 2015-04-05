/* Name: Gabriel Beedles
* Filename: main.cpp
* Date Modified: 6/4/2015
*
* Purpose: Used to test functionality of the DynamicArray class
*
*/

#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main() {

	DynamicArray<int> intArray;
	int temp = 0;

	cout << "intArray size is " << intArray.getSize() << endl;

	for (int i = 0; i < 10; ++i)
		intArray.add(i);

	cout << "Here is the array:" << endl;
	cout << intArray;
	cout << "Size is " << intArray.getSize() << endl;

	cin >> temp;

	return 0;
}