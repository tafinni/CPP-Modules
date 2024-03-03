#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const & other): _stack(other._stack) {}

RPN &RPN::operator=(RPN const & other) 
{
    if (this != &other) 
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}


void RPN::calculate(const std::string line)
{
    for (size_t i = 0; i < line.size(); i++)
    {
        // Checks for correct input
        if (std::isdigit(line[i]) == false && line[i] != '-' && line[i] != '+' && line[i] != '*' && line[i] != '/')
            throw InputError();

        // Saves number to stack
        if (std::isdigit(line[i]) == true && line[i + 1] == ' ')
        {
            if (i + 1 == line.size() - 1)
                throw InputError();
            _stack.push(std::strtod(&line[i], nullptr));
        }
        else if ((line[i] == '+' || line[i] == '-') && line[i + 1] && line[i + 1] != ' ')
            _stack.push(std::stod(line.substr(i++, 2), nullptr));
        else if (line[i] == '-' || line[i] == '+' || line[i] == '*' || line[i] == '/')
            handleOperator(line[i]);
        
        // All values need to be separated by space
        if (++i > line.size() && line[i] != ' ' && line[i] != '\0')
            throw InputError();
    }
    
    // Check stack and print result
    if (_stack.size() != 1)
        throw InputError();
    std::cout << _stack.top() << std::endl; 
}


void RPN::handleOperator(char c)
{
    if (_stack.size() < 2)
        throw InputError();
    
    // Get two top values from stack
    int second = _stack.top();
    _stack.pop();
    int first = _stack.top();
    _stack.pop();
            
    switch (c)
    {
        case '+':
            _stack.push(first + second);
            break ;
        case '-':
            _stack.push(first - second);
            break ;
        case '*':
            _stack.push(first * second);
            break ;
        case '/':
            if (second == 0)
                throw InputError();
            else
                _stack.push(first / second);
            break ;
    }
}


const char* RPN::WrongArgs::what() const throw()
{
    return "Error: Wrong amount of aruments";
}

const char* RPN::InputError::what() const throw()
{
    return "Error: Input error";
}


