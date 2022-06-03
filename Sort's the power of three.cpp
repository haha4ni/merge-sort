#include <iostream>
#include <stdlib.h>
using namespace std;

int array[10];



void randArray()
{
	for(int i = 0; i<10; i++)
		array[i] = rand()%100;
}
void printArray()
{
	for(int i = 0; i<10; i++)
		cout << array[i] << ",";
	cout << endl;
}

int main() {
	//Insertion Sort
	cout << "Insertion Sort\n";
	randArray();
	printArray();
	int n, j;
    for (int i = 1; i < 10; ++i)
    {
        n = array[i];
        for (j = i; j >= 0 && array[j-1] > n; j--)
            array[j] = array[j-1];
        array[j] = n;
    }
	
	printArray();
	
	
	//Bubble sort
	cout << "Bubble sort\n";
	randArray();
	printArray();
	for(int i = 0; i<10; i++)
		for(int j = 0; j<10-1-i; j++)
			if(array[j] > array[j+1])
			{
				int temp;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				
			}
			
	printArray();

	//Selection Sort
	cout << "Selection sort\n";
	randArray();
	printArray();
	for(int i = 0; i<10; i++)
	{
		int min = i;
		for(int j = i+1; j<10; j++)
		{
			if(array[min]>array[j])
			min = j;
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	
	printArray();
	
	return 0;
}
