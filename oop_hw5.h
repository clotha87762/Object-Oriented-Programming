#ifndef LINK_LIST_H
#define LINK_LIST_H

///////////////////////////////////////////////////////////////////////////////////
// Class Definitions
// YOU SHOULD NOT MODIFY THINGS WE DECLARED !!!!
///////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
template <class T>
class LinkList
{

	friend class Iter;

protected:
	struct Node
	{
		Node(){data = new T;}
		Node *pre, *next;
		T *data;
	};

public:

	class Iter
	{
	friend class LinkList;
	friend void  BubbleSort(T first, T last);
	public:
		Iter();
		~Iter();

		Iter & operator++();
		Iter & operator--();
		Iter & operator=(const Iter &);
		bool   operator!=(const Iter &);
		T	 & operator*();
		Node* ptr(){

			return pointer;
		};
	private:
		Node* pointer;
	};

	LinkList();
	~LinkList();

	void	push_back(T);
	T		pop_back();
	Iter &	begin();
	Iter &	end();

private:
	Node*   nodes;
	Iter	head, tail;
	int     size;
};


///////////////////////////////////////////////////////////////////////////////////
// IMPLEMENT EVERYTHING BELOW THIS LINE !!
///////////////////////////////////////////////////////////////////////////////////

// constructor for linked list
template <class T>
inline LinkList<T>::LinkList()
{

	size = 0;
}

// destructor for linked list
template <class T>
inline LinkList<T>::~LinkList()
{


}

// push new element to the end of the list
// ex: [1 3 5] -> push_back(6) -> [1 3 5 6]
template <class T>
inline void LinkList<T>::push_back(T input)
{

	if(size==0){


			head.pointer = new Node ;


			head.pointer-> data[0] = input;
			tail = head ;
			//cout<<tail.pointer->data[0]<<"zzz"<<endl;
			size++;

	}
	else{


	tail.pointer->next = new Node;
	tail.pointer->next->pre = tail.pointer;
	tail.pointer = tail.pointer->next;
	tail.pointer->data[0] = input;
	//cout<<tail.pointer->data[0]<<"zzz"<<endl;
	size++;
	}
}

// return then delete the last element of the list
// ex: [1 2 3] -> pop_back() -> [1 2] (return 3)
template <class T>
inline T LinkList<T>::pop_back()
{


	T x;
	x=tail.pointer->data[0];

	tail.pointer=tail.pointer->pre;
	size--;

	return  x;

}

// return iterator to the first element of the list
template <class T>
inline typename LinkList<T>::Iter& LinkList<T>::begin()
{

	return head; // 怡怡怡怡咦?怡怡怡怡宜?

}

// return "past-the-end" iterator, as in STL
template <class T>
inline typename LinkList<T>::Iter& LinkList<T>::end()
{
	/*Iter ed = tail;

	++ed  ;
	ed.pointer->pre = tail.pointer;
	return ed;*/
	Iter ed ;
	tail.pointer->next = ed.pointer;

	ed.pointer->pre = tail.pointer;
	return ed;
}

// constructor for iterator class
template <class T>
inline LinkList<T>::Iter::Iter()
{

 // 這應該不需要放吧

}

// destructor for iterator class
template <class T>
inline LinkList<T>::Iter::~Iter()
{

	//這也應該不需要放吧??

}

// go to the next element in the list
template <class T>
inline typename LinkList<T>::Iter& LinkList<T>::Iter::operator++()
{

	pointer = pointer->next;
	return *this; // ?????????????????/
}

// go to the last element in the list
template <class T>
inline typename LinkList<T>::Iter& LinkList<T>::Iter::operator--()
{
	pointer = pointer->pre;
	return *this;


}

// assignment operator
template <class T>
inline typename LinkList<T>::Iter& LinkList<T>::Iter::operator=(const typename LinkList<T>::Iter& t)
{

	pointer = t.pointer;
	return *this;

}

// check if the 2 iterators points to the same position
template <class T>
inline bool LinkList<T>::Iter::operator!=(const typename LinkList<T>::Iter&  t)
{

	return !(pointer == t.pointer);

}

// get the data which the iterator points to
template <class T>
inline T& LinkList<T>::Iter::operator*()
{

	return pointer-> data[0];

}

// sort the given container
// by providing container begin & end as parameters (the same as STL sort)
template<class T>
void BubbleSort(T first, T last)
{

	int u;
	T x=last;

	T i=first;
	T j=first;
	T L = last;
	T temp ;
	--L;
	--x;
	--L;

	//cout<<*x<<endl;
	//cout<<*i<<endl;

	for(;i!=L;++i){

		for(j=first;j!=x;++j){


			temp = j;

			++temp;
			if(*j>*temp){


			swap(*j,*temp);

			}

		}

		--x;

	}

	//for(i=first;i!=last;++i)cout<<*i<<endl;

}

#endif
