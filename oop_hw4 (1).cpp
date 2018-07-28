//! Homework #4

#include <iostream>
#include <stdexcept>

using namespace std;

///////////////////////////////////////////////////////
// IMPLEMENT THE AUTO_ARRAY CLASS BELOW THIS LINE !! //
///////////////////////////////////////////////////////





template <typename T>
class auto_array
{
public:

	friend ostream & operator<<( ostream & , auto_array &);
	auto_array<T> (int ii , int s){
	idx=ii;
	size = s;
	arr = new T[ size+1];
	}

	~auto_array<T>(){cout<<"Array #"<<idx<<" has been automatically deleted."<<endl;delete[] arr; }

	T& operator [](int a){


		if( a>=size){ throw  out_of_range("Exception: out of range!");}

		return arr[a];


		}


	int idx;
	int size;
	T* arr;



};

/*ostream& operator << (ostream& os , auto_array & v){

	os<<

	return os;
}*/

////////////////////////////////////////////////////
// YOU CANNOT MODIFY ANY CODE BELOW THIS LINE !!  //
////////////////////////////////////////////////////

int main ()
{
	//////////////////////////////////////////////////////////////////////////////
	// Test 1                                                                   //
	//////////////////////////////////////////////////////////////////////////////

	// Auto_array #1
	// auto_array(int idx, int size)
	// idx  = user-specified identifier for auto_array objects
	// size = array size
	auto_array<int> x(1, 10);
	for (int i = 0 ; i < 10 ; i++)
	{
		x[i] = i * i;
		cout << x[i] << " ";
	}
	cout << endl;

	//////////////////////////////////////////////////////////////////////////////
	// Test 2                                                                   //
	//////////////////////////////////////////////////////////////////////////////

	// Error test
	// You need to use exception handling mechanism to print out "Exception: out of range!"

	try
	{
		cout << x[20] << endl;

	}
	catch (out_of_range &e)
	{

		cout << e.what() << endl;
	}

	//////////////////////////////////////////////////////////////////////////////
	// Test 3                                                                   //
	//////////////////////////////////////////////////////////////////////////////

	// Auto_array #2
	for(int iter=0; iter<3; iter++)
	{

		auto_array<int> y(2, 5);

		for (int i = 0 ; i < 5 ; i++)
		{
			y[i] = i * i;
			cout << y[i] << " ";
		}
		cout << endl;

		// You need to print "Array #idx has been automcout<<"Array #"<<idx<<" has been automatically deleted.";atically deleted." after release the auto_array variables
	}

	//////////////////////////////////////////////////////////////////////////////
	// Test 4                                                                   //
	//////////////////////////////////////////////////////////////////////////////

	// Auto_array #3
	int usr_sz;
	cout << "Give me array size: ";
	cin >> usr_sz;
	auto_array<double> z(3, usr_sz);
	for (int i = 0 ; i < usr_sz ; i++)
	{
		z[i] = i + 10.5;

		cout << z[i] << " ";

	}
	cout << endl;

	//////////////////////////////////////////////////////////////////////////////
	// Test 5                                                                   //
	//////////////////////////////////////////////////////////////////////////////

	// You need to print "Array #idx has been automatically deleted." after release the auto_array variables

	return 0;
}
