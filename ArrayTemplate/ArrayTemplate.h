#ifndef ARRAYTEMPLATE_H_
#define ARRAYTEMPLATE_H_

#include <iostream>
#include <cstdlib>
template <class T,int n>
class ArrayTP
{
private:
	T arr[n];
public:
	ArrayTP() {}
	explicit ArrayTP(const T& t);
	virtual T& operator[](int n);
	virtual T operator[](int n)const;
};
template <class T,int n>
ArrayTP<T, n>::ArrayTP(const T& t)
{
	for (int i = 0; i < n; i++)
		arr[i] = n;
}
template<class T,int n>
T ArrayTP<T, n>::operator[](int i)const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limit:" << i
			<< " is out of range" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return arr[i];
}
template <class T,int n>
T& ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limit:" << i
			<< " is out of range" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return arr[i];
}
#endif // !ARRAYTEMPLATE_H_
