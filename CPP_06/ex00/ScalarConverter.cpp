#include "ScalarConverter.hpp"

ScalaConverter::ScalaConverter()
{
	std::cout << "ScalaConverter default constructor" << std::endl;
}

ScalaConverter::ScalaConverter(ScalaConverter &s)
{
	std::cout << "ScalaConverter copy constructor" << std::endl;
	*this = s;

}

ScalaConverter &ScalaConverter::operator=(ScalaConverter &s)
{
	std::cout << "ScalaConverter copy assignment operator" << std::endl;
	(void)s;
	return *this;
}

ScalaConverter::~ScalaConverter()
{
	std::cout << "ScalaConverter destructor" << std::endl;
}

bool ScalaConverter::isInt(const std::string &literal)
{
	int signs = 0;

	for (char c : literal)
	{
		if (c == '-' || c == '+')
			signs++;
		if (!std::isdigit(c) && c != '+' && c != '-')
			return false;
	}
	if (signs > 1)
		return false;
	return true;
}

bool ScalaConverter::isFloat(const std::string &literal)
{
	bool all_zero = true;
	int signs = 0;
	int f = 0;

	for (char c : literal)
	{
		if (c == 'f')
			f++;
		if (c == '-' || c == '+')
			signs++;
		if (c != '.' && c != '0' && c != 'f' && c != '-' && c != '+')
			false;
		if (!std::isdigit(c) && (c != 'f'))
		{
			if (c != '.' && c != '-' && c != '+')
				return false;
		}
	}
	if (signs > 1 || f != 1)
		return false;
	if (all_zero)
		return true;
	double check = std::stof(literal);
	if (check)
		return true;
	else
		return false;
}

bool ScalaConverter::isDouble(const std::string &literal)
{
	bool all_zero = true;
	int signs = 0;

	for (char c : literal)
	{
		if (c == '-' || c == '+')
			signs++;
		if (c != '.' && c != '0' && c != '-' && c != '+')
			false;
		if (!std::isdigit(c) && c != '.' && c != '-' && c != '+')
			return false;
	}
	if (signs > 1)
		return false;
	if (all_zero)
		return true;
	double check = std::stod(literal);
	if (check)
		return true;
	else
		return false;
}

void ScalaConverter::fromFail()
{
	std::cout << "char:	impossible" << std::endl;
	std::cout << "int:	impossible" << std::endl;
	std::cout << "float:	impossible" << std::endl;
	std::cout << "double:	impossible" << std::endl;
}

void	ScalaConverter::fromChar(const std::string &literal)
{
	char c = static_cast<char>(literal[0]);

	std::cout << "char:	'" << c << "'" << std::endl;

	std::cout << "int:	" << static_cast<int>(c) << std::endl;

	std::cout << "float:	" << static_cast<float>(c) << "f" << std::endl;

	std::cout << "double:	" << static_cast<double>(c) << std::endl;
}

void ScalaConverter::fromInt(const std::string &literal)
{
	std::istringstream iss(literal);
	int temp;
	iss >> temp;

	int value = static_cast<int>(temp);
	if (value >= 32 && value <= 126)
		std::cout << "char:	'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char:	non displayable" << std::endl;

	std::cout << "int:	" << value << std::endl;

	std::cout << "float:	" << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double:	" << static_cast<double>(value) << std::endl;
}

void ScalaConverter::fromFloat(const std::string &literal)
{
	std::istringstream iss(literal);
	float temp;
	iss >> temp;

	float value = static_cast<float>(temp);
	if (value >= 32 && value <= 126)
		std::cout << "char:	'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char:	non displayable" << std::endl;

	std::cout << "int:	" << static_cast<int>(value) << std::endl;

	std::cout << "float:	" << value << "f" << std::endl;

	std::cout << "double:	" << static_cast<double>(value) << std::endl;
}

void ScalaConverter::fromDouble(const std::string &literal)
{
	std::istringstream iss(literal);
	double temp;
	iss >> temp;

	double value = static_cast<double>(temp);
	if (value >= 32 && value <= 126)
		std::cout << "char:	'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char:	non displayable" << std::endl;

	std::cout << "int:	" << static_cast<int>(value) << std::endl;

	std::cout << "float:	" << static_cast<float>(value) << "f" << std::endl;

	std::cout <<"double:	" << value << std::endl;
}

void ScalaConverter::fromLiteral(const std::string &literal)
{
	std::cout << "char:	impossible" << std::endl;

	std::cout << "int:	impossible" << std::endl;

	std::cout << "float:	" << std::stof(literal) << "f" << std::endl;

	std::cout << "double:	" << std::stod(literal) << std::endl;
}

void ScalaConverter::convert(const std::string &literal)
{
	if (literal.size() < 1)
	{
		fromFail();
		return ;
	}
	for (char c : literal)
	{
		if (c == '	' || c == ' ')
		{
			fromFail();
			return ;
		}
	}
	if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126 && !(isdigit(literal[0])))
	{
		fromChar(literal);
		return ;
	}
	else if (isInt(literal))
	{
		fromInt(literal);
		return ;
	}
	else if (isFloat(literal))
	{
		fromFloat(literal);
		return ;
	}
	else if (isDouble(literal))
	{	
		fromDouble(literal);
		return ;
	}
	else if (literal == "nan" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "inff")
	{
		fromLiteral(literal);
		return ;
	}
	fromFail();
}
