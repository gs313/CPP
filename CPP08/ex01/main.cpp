#include <iostream>
#include "Span.hpp"
int main()
{
Span sp = Span(5);
int arr[] = {1, 2, 3, 4};
std::vector<int> number;
number.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
sp.addRange(number.begin(), number.end());
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
