template<typename T>
Array<T>::Array(): _array(nullptr), _arrlen(0)
{
	std::cout << "Array default constructor" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &a): _array(new T[a._arrlen]), _arrlen(a._arrlen)
{
	std::cout << "Array copy constructor" << std::endl;
	for (int i = 0; i < a._arrlen; i++)
		this->_array[i] = a._array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &a)
{
	std::cout << "Array copy assignment operator" << std::endl;
	if (this != &a)
	{
		this->_arrlen = a._arrlen;
		if (this->_array != nullptr)
			delete[] this->_array;
		this->_array = new T[this->_arrlen];
		for (int i = 0; i < this->_arrlen; i++)
			this->_array[i] = a._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array default destructor" << std::endl;
	delete[] this->_array;
}

template<typename T>
Array<T>::Array(unsigned int n): _array(nullptr), _arrlen(n)
{
	std::cout << "Array unsigned int constructor" << std::endl;
	try
	{
		if (n < 1)
		{
			this->_array = nullptr;
			throw OutOFBounds();
		}
		else
			this->_array = new T[this->_arrlen];
		for (int i = 0; i < this->_arrlen; i++)
			this->_array[i] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

template<typename T>
T &Array<T>::operator[](const int value)
{
	if (value < 0 || value >= this->_arrlen || this->_array == nullptr)
		throw OutOFBounds();
	return (this->_array[value]);	
}

template<typename T>
int Array<T>::size()
{
	return (this->_arrlen);
}

/* template<typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Value out of bounds";
} */


