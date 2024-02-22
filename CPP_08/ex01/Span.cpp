#include "Span.hpp"

Span::Span(): _n(0)
{
	std::cout << "Span default constructor" << std::endl;
}

Span::Span(const Span &s): _n(s._n), _container(s._container)
{
	std::cout << "Span copy constructor" << std::endl;
}

Span &Span::operator=(const Span &s)
{
	std::cout << "Span assignment operator" << std::endl;
	if (this != &s)
	{
		this->_n = s._n;
		this->_container = s._container;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor" << std::endl;
}

Span::Span(unsigned int n): _n(n)
{
	std::cout << "Span unsigned int constructor" << std::endl;
}

void Span::addNumber(int value)
{
	try
	{
		if (this->_n > this->_container.size())
			this->_container.push_back(value);
		else
			throw Span::ContainerFull();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void Span::addMany(int count)
{
    std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	int range = 1000;

	try
	{
		for (int i = 0; i < count; i++)
		{
			if (this->_container.size() == this->_n)
				throw ContainerFull();
			this->_container.push_back(std::rand() % range);
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int Span::shortestSpan()
{
	if (this->_container.size() < 2)
		throw NotEnoughValues();

	int lowest = *std::max_element(this->_container.begin(), this->_container.end());
	int temp;
	std::vector<int>::iterator compare = this->_container.begin();

	for (int rounds = 0; rounds < static_cast<int>(this->_container.size()); rounds++)
	{
		compare = this->_container.begin() + rounds;
		for (std::vector<int>::iterator it = this->_container.begin(); it != this->_container.end(); it++)
		{
			if (it != this->_container.begin() && compare != it)
			{
				temp = *compare - *it;
				if (temp < 0)
					temp *= -1;
				if (temp < lowest)
					lowest = temp;
			}
		}
	}
	return lowest;
}

int Span::longestSpan()
{
	if (this->_container.size() < 2)
		throw NotEnoughValues();
	return (*std::max_element(this->_container.begin(), this->_container.end())) - (*std::min_element(this->_container.begin(), this->_container.end()));
}

std::vector<int>* Span::getContainer()
{
	return &_container;
}

const char *Span::ContainerFull::what() const throw()
{
	return "Container full";
}

const char *Span::NotEnoughValues::what() const throw()
{
	return "Not enough values in container";
}

std::ostream &operator<<(std::ostream &os, Span &sp)
{
	for (std::vector<int>::iterator it = sp.getContainer()->begin(); it != sp.getContainer()->end(); it++)
		os << *it << "  ";
	return (os);
	
}