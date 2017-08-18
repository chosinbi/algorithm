#include<iostream>
using namespace std;
#include <math.h>
//#include <cmath.h>
double cubicroot(int num);
int binarySearch(int a[], int first, int last, int target);
int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(10);

	int count;
	cin >> count;
	double *num= new double[count]; 
	for (int i = 0; i < count; i++) {
		cin >> num[i];
		num[i] = pow(num[i], 1.0 / 3.0);		
	}

	cout << "\n";
	for (int i = 0; i < count; i++)
		cout << num[i] << endl;
	return 0;
}

int binarySearch(int a[], int first, int last, int target)
{
	// Preconditions: a is an array sorted in ascending order, 
	//     first is the index of the first element to search,
	//     last is the index of the last element to search, 
	//     target is the item to search for.   
	if (first > last)
		return -1; // -1 indicates failure of search
	int mid = (first + last) / 2;

	if (a[mid] == target)
		return mid;
	else if (target < a[mid])
		return binarySearch(a, first, mid - 1, target);
	else // target must be > a[mid]
		return binarySearch(a, mid + 1, last, target);
	// Postcondition: Value returned is position of target in a, 
	// otherwise -1 is returned
}

