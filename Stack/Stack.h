#ifndef STACK_H_
#define STACK_H_
//制作一个模板栈
template <class T>
class Stack
{
private:
	enum{MAX=10};//等于const static int MAX=10
	T items[MAX];
	int top;
public:
	Stack();
	bool isempty()const;
	bool isfull()const;
	bool push(const T& item);
	bool pop(T& item);
	int size()const;
};

template <class T>
Stack<T>::Stack()
{
	top = 0;
}

template <class T>
bool Stack<T>::isempty()const
{
	return top == 0;
}
template <class T>
bool Stack<T>::isfull()const
{
	return top == MAX;
}
template <class T>
bool Stack<T>::push(const T& item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}
template <class T>
bool Stack<T>::pop(T &item)
{
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else
		return false;
}
template<class T  >
int Stack<T>::size() const
{
	return top;
}
#endif // !STACK_H_
