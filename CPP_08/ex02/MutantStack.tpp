template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m): std::stack<T>(m)
{

}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &m)
{
	if (this != &m)
		std::stack<T>::operator=(m);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return c.end();
}
