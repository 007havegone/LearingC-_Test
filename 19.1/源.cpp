#include <iostream>
#include <cstdlib>
using namespace std;


void* operator new(size_t t)
{
	if (void *men = malloc(t))
		return men;
	else
		throw bad_alloc();
}
void operator delete(void *men) noexcept
{
	free(men);
}

int main()
{
	int *pi = static_cast<int*>(operator new(sizeof(int)));
	int a = 23;
	*pi = 16;
	cout << a << " " << *pi << endl;
	operator delete((void*)pi);
}