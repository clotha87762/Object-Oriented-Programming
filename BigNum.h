#ifndef _BIGNUM_H_
#define _BIGNUM_H_ 

#include "Number.h"

class BigNum : public Number
{
public:
	BigNum();
	BigNum(const Number &v);
	BigNum(const char *ptr);
	const Number &operator= (const Number &v);
	const Number &operator= (const BigNum &v);
	const Number &operator+ (const Number &v);
	const Number &operator- (const Number &v);
	const Number &operator* (const Number &v);
	const Number &operator/ (const Number &v);
};

#endif
