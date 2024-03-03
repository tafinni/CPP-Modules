#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <cstdlib>

class RPN
{
    private:
        std::stack<double> _stack;
    
    public:
        RPN();
        RPN(RPN const & other);
        RPN &operator=(RPN const & other);
        ~RPN();
        
        void calculate(const std::string line);
        void handleOperator(char c);

        class WrongArgs: public std::exception
        {
            public:
                const char *what() const throw();
        };

        class InputError: public std::exception
        {
            public:
                const char *what() const throw();
        };

};

#endif