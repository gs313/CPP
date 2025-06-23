#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	// Type aliases for iterator and const_iterator
	// using iterator = typename std::stack<T>::container_type::iterator;
	// using const_iterator = typename std::stack<T>::container_type::const_iterator;
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	// Default constructor
	MutantStack() : std::stack<T>() {}

	// Copy constructor
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}

	// Assignment operator
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}

	// Destructor
	~MutantStack() {}

	// Begin iterator
	iterator begin() {
		return std::stack<T>::c.begin();
	}

	// End iterator
	iterator end() {
		return std::stack<T>::c.end();
	}

	// Const begin iterator
	const_iterator begin() const {
		return std::stack<T>::c.begin();
	}

	// Const end iterator
	const_iterator end() const {
		return std::stack<T>::c.end();
	}
};

#endif
