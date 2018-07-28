#include "A022029_matrix33.h"

using namespace std;

matrix33::matrix33(const matrix33 &m){

	col[0]=m.col[0];
	col[1]=m.col[1];
	col[2]=m.col[2];

}

matrix33::matrix33(const vector3 &v0, const vector3 &v1, const vector3 &v2){

	col[0]= v0;
	col[1]= v1;
	col[2]= v2;

}

vector3 &matrix33::operator [] (unsigned int i){

	return col[i];

}

const vector3&	matrix33::operator [] (unsigned int i) const{

	return col[i];

}

matrix33& matrix33::operator =  (const matrix33 &m){

	for(int i=0;i<3;i++){

		col[i]=m.col[i];

	}

	return *this;

}

matrix33& matrix33::operator +=  (const matrix33 &m){

	for(int i=0;i<3;i++){

		col[i] += m.col[i];

	}

	return *this;

}

matrix33& matrix33::operator -=  (const matrix33 &m){

	for(int i=0;i<3;i++){

		col[i] -= m.col[i];

	}

	return *this;
}

matrix33& matrix33::operator *=  (const matrix33 &m){

	int k;
	vector3 temp1(0,0,0),temp2(0,0,0),temp3(0,0,0);
	matrix33 temp(temp1,temp2,temp3);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){

			for(k=0;k<3;k++)
				temp.col[j][i] += this->col[k][i] * m.col[j][k];

		}

		*this = temp;
		return *this;

}

matrix33& matrix33::operator *= (float f){

	for(int i=0;i<3;i++){

		col[i] *= f;

	}

	return *this;

}

matrix33 &matrix33::operator /= (float f){

	for(int i=0;i<3;i++){

		col[i] /= f;

	}

	return *this;
}

bool operator == (const matrix33 &a, const matrix33 &b){

	if(a.col[0]==b.col[0]&&a.col[1]==b.col[1]&&a.col[2]==b.col[2]) return true;
		else return false;

}

bool	operator != (const matrix33 &a, const matrix33 &b){

	return !(a==b);

}

matrix33  operator + (const matrix33 &a, const matrix33 &b){

	matrix33 temp;

	temp.col[0] = a.col[0] + b.col[0];
	temp.col[1] = a.col[1] + b.col[1];
	temp.col[2] = a.col[2] + b.col[2];

	return temp;

}

matrix33  operator - (const matrix33 &a, const matrix33 &b){

	matrix33 temp;

	temp.col[0] = a.col[0] - b.col[0];
	temp.col[1] = a.col[1] - b.col[1];
	temp.col[2] = a.col[2] - b.col[2];

	return temp;


}

matrix33  operator * (const matrix33 &a, const matrix33 &b){

	int k;
	vector3 temp1(0,0,0),temp2(0,0,0),temp3(0,0,0);
	matrix33 temp(temp1,temp2,temp3);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){

			for(k=0;k<3;k++)
				temp.col[j][i] += a.col[k][i] * b.col[j][k];

		}

		return temp;

}

vector3 operator * (const matrix33 &m, const vector3 &v){

	int i,j;
	vector3 temp(0,0,0);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++) temp[i] += m.col[j][i] * v[j];

	return temp;

}
/* 啊 這邊到底是在銃沙小啊啊啊啊啊啊啊啊啊啊啊啊*/
vector3 operator * (const vector3 &v, const matrix33 &m){

	int i,j;
	vector3 temp(0,0,0);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++) temp[i] += m.col[j][i] * v[j];

	return temp;

}

matrix33	operator * (const matrix33 &m, float f){

	matrix33 temp;
	temp = m;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp.col[i][j] *= f;

	return temp;

}

matrix33	operator * (float f,const matrix33 &m){

	matrix33 temp;
	temp = m;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp.col[i][j] *= f;

	return temp;

}

matrix33	operator / (const matrix33 &m,float f){

	matrix33 temp;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp.col[i][j] /= f;

	return temp;

}

 void matrix33::printMatrix() const{

 	int i,j;
 	for(i=0;i<3;i++){
		for(j=0;j<3;j++){

		cout<< col[j][i]<<" ";

		}

		cout<<endl;
 	}
 }

float& matrix33::determinant(){

	int i,j=0,k;
	float f=0,temp=1;

	for(i=0;i<3;i++)
	{
		k=i;
		for(j=0;j<3;j++)
			temp *= col[(k++)%3][j];

		f+= temp;
		temp =1;
	}

	for(i=2;i>=0;i--){

		k=i+3;
		for(j=0;j<3;j++)
			temp *=col[(k-j)%3][j];

		f-= temp;
		temp =1;
	}
	return f;

}

matrix33& matrix33::identity(){

	vector3 temp1(1,0,0),temp2(0,1,0),temp3(0,0,1);
	col[0]=temp1;
	col[1]=temp2;
	col[2]=temp3;

	return *this;

}

matrix33	&matrix33::transpose(){

	int i,j;
	matrix33 temp;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			temp.col[j][i]=col[i][j];

	*this = temp;
	return *this;


}

matrix33 &matrix33::invert(){
	int i,j;
	matrix33 temp;
	float f = determinant();
	/*for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			{
				temp.col[j][i]= col[(j+1)%3][(i+1)%3] * col[(j+2)%3][(i+2)%3] - col[(j+1)%3][(i+2)%3] * col[(j+2)%3][(i+1)%3];

			}*/

	temp.col[0][0]= (col[1][1]*col[2][2]) - (col[2][1]*col[1][2]);
	temp.col[1][0]= ((col[1][0]*col[2][2]) - (col[2][0]*col[1][2])) *-1;
	temp.col[2][0]= (col[1][0]*col[2][1]) - (col[1][1]*col[2][0]);
	temp.col[0][1]= ((col[0][1]*col[2][2]) - (col[0][2]*col[2][1]))*-1;
	temp.col[1][1]= (col[0][0]*col[2][2]) - (col[0][2]*col[2][0]);
	temp.col[2][1]= ((col[0][0]*col[2][1]) - (col[0][1]*col[2][0]))*-1;
	temp.col[0][2]= (col[0][1]*col[1][2]) - (col[0][2]*col[1][1]);
	temp.col[1][2]= ((col[0][0]*col[1][2] - (col[0][2]*col[1][0])))*-1;
	temp.col[2][2]= (col[0][0]*col[1][1]) - (col[0][1]*col[1][0]);


	temp /= f ;

	*this =temp;
	return *this;

}


