#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "A022029_vector3.h"
#include <math.h>
#include <iostream>
class matrix33
{
public:
	/* data members */
	vector3 col[3];

	//****************************************************//
	//  You need to implement the following functions !!  //
	//****************************************************//

public:
	/* constructors - implement them !! */
	matrix33() {};

	// constructor with initializing matrix33
	matrix33(const matrix33 &m);

	// constructor with 3 initializing column vectors
	matrix33(const vector3 &v0, const vector3 &v1, const vector3 &v2);

public:
	/* Operators */
	vector3				 &operator [] (unsigned int i);
	const vector3		 &operator [] (unsigned int i) const;

	matrix33             &operator =  (const matrix33 &m);
	matrix33             &operator += (const matrix33 &m);
	matrix33             &operator -= (const matrix33 &m);
	matrix33             &operator *= (const matrix33 &m);
	matrix33             &operator *= (float f);
	matrix33             &operator /= (float f);

	friend bool	operator == (const matrix33 &a, const matrix33 &b);
	friend bool	operator != (const matrix33 &a, const matrix33 &b);

	friend matrix33	operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33	operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33	operator * (const matrix33 &a, const matrix33 &b);
	friend vector3 operator * (const matrix33 &m, const vector3 &v);
	friend vector3 operator * (const vector3 &v, const matrix33 &m);
	friend matrix33	operator * (const matrix33 &m, float f);
	friend matrix33	operator * (float f, const matrix33 &m);
	friend matrix33	operator / (const matrix33 &m, float f);

 public:

	 /* Methods */
	 // print matrix using std::cout
	 void printMatrix() const;

	 // calculate matrix determinant
	 float	    &determinant();

	 // set this matrix to identity matrix
	 matrix33	&identity();

	 // transpose matrix
	 matrix33	&transpose();

	 // calculate matrix inversion
	 matrix33	&invert();
};

#endif
