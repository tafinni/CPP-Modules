#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &m);
		MutantStack &operator=(const MutantStack &m);
		~MutantStack();

		using std::stack<T>::c;
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};


# include "MutantStack.tpp"

#endif