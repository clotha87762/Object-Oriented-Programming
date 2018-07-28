#include "A022029_vector3.h"
#include <iostream>
#include <math.h>

using namespace std;
vector3::vector3(float inX, float inY, float inZ){

	x=inX;
	y=inY;
	z=inZ;

}

vector3::vector3(const vector3 &v){

	x=v.x;
	y=v.y;
	z=v.z;

}

void vector3:: set(float xIn, float yIn, float zIn){

	x=xIn;
	y=yIn;
	z=zIn;

}


vector3& vector3::operator =  (const vector3 &v){

	x=v.x;
	y=v.y;
	z=v.z;
	return *this;

}

vector3& vector3::operator += (const vector3 &v){

	x+=v.x;
	y+=v.y;
	z+=v.z;
	return *this;
}

vector3& vector3::operator -= (const vector3 &v){

	x-=v.x;
	y-=v.x;
	z-=v.z;
	return *this;

}

vector3 &vector3::operator *= (float f){

		x*=f;
		y*=f;
		z*=f;
		return *this;

}

vector3& vector3::operator /= (float f){

	x/=f;
	y/=f;
	z/=f;
	return *this;

}

 bool  operator == (const vector3 &a, const vector3 &b){

 	if((a.x==b.x)&&(a.y==b.y)&&(a.z==b.z))return true;
 		else return false;

 }

 bool  operator != (const vector3 &a, const vector3 &b){

 	return !(a==b);

 }

 vector3   operator - (const vector3 &a){

   vector3 temp;
   temp.x = -1 *a.x;
   temp.y = -1 *a.y;
   temp.z = -1 *a.z;
   return temp;

 }

 vector3 operator + (const vector3 &a, const vector3 &b){

	vector3 temp;

	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	temp.z = a.z + b.z;

	return temp;

 }

 vector3 operator - (const vector3 &a, const vector3 &b){

 	vector3 temp;

 	temp.x= a.x-b.x;
 	temp.y= a.y-b.y;
 	temp.z= a.z-b.z;

 	return temp;

 }

 vector3  operator * (const vector3 &v, float f){

	vector3 temp;

	temp.x = v.x * f;
	temp.y = v.y * f;
	temp.z = v.z * f;

	return temp;

}

 vector3  operator * (float f, const vector3 &v){

 	vector3 temp;

 	temp.x = v.x * f;
	temp.y = v.y * f;
	temp.z = v.z * f;

	return temp;

 }

 vector3 operator / (const vector3 &v,float f){

 	vector3 temp;

 	temp.x = v.x/f;
 	temp.y = v.y/f;
 	temp.z = v.z/f;

 	return temp;

 }

  void vector3::printVector3() const{

	cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;

  }

   float vector3::length() const{

	float temp;
	temp = sqrt(x*x+y*y+z*z);
	cout<<temp;

	return temp;


   }

  float &vector3::operator [] (unsigned int index){

  	if(index==0)return x;
  		else if(index == 1) return y;
  			else return z;

  }

  const float  &vector3::operator [] (unsigned int index) const{

	if(index==0)return x;
  		else if(index == 1) return y;
  			else return z;


  }
