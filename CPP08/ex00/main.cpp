#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

template	<typename T>
void getValue(T &container, int value) {
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec;
	vec.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));

	getValue(vec, 3);
	getValue(lst, 4);
	getValue(vec, 6); // This will throw an exception

	return 0;
}

