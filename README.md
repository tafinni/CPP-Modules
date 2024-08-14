# CPP-Modules

CPP modules are shorter projects that contain several exercises that serve as an introduction to C++. Each module focuses on different aspects of C++ programming, progressively building up the understanding and skills.

**How to run**
- Each exercises has Makefile and the programs are compiled by typing "make" to the terminal in exercise's directory

## Contents
**CPP_00: Basics of C++**
- C++ syntax, namespaces, classes, I/O operations, member and non-member functions.
  - ex00: Simple program that converts input text to uppercase.
  - ex01: Implements basic phonebook that stores max 8 contacts.

**CPP_01: Memory allocation and pointers**
- Dynamic memory allocation, pointers, references, switch statement, stack and heap memory, usage of "new" and "delete".
  - ex00: Make "Zombie" class and compare memory allocation between stack and heap.
  - ex01: Create and "a horde of zombies" with dynamic memory allocation.
  - ex02: Understanding pointers' and references' memory addresses and values.
  - ex03: Implements Human classes and Weapon class to explore use of pointers and references in classes.
  - ex04: File manipulaiton program where part of the text can be replaced.
  - ex05: Responses with pointers to member functions.
  - ex06: Responses are filtered based on log levels using switch statement.

**CPP_02: Ad-hoc polymorphism, operator overloading and orthodox canonical form**
- Making classes more flexible and user-friendly with overlading operators and keeping consistent with canonical form.
  - ex00: Make class in canonical form that reperesents fixed-point number.
  - ex01: Added conversion functions for fixed-point number.
  - ex02: Operator overloading with comparison operators and arithmetic operators.

**CPP_03: Inheritance**
- Inheritance basics, base classes, derived classes and virtual functions. Usage of inheritance to create create parent and child classes and enable polymorphism with virtual functions.
  - ex00: Created ClapTrap class and action fnctions like attack and takeDamage.
  - ex01: Derived ScavTrap class from ClapTrap. Overrided constructors, destructors and attack method and values and added more action.
  - ex02: In similar way created FragTrap from ClapTrap.
  - ex03: Crested DiamondTrap that inherits from FragTrap and ScavTrap.
     
**CPP_04: Abstract classes, polymotphism, deep copies and interfaces**
- Understanding how C++ supports interfaces through abstract classes and virtual functions.
  - ex00: Created Animal class an derived classes, overriding makeSound() function.
  - ex01: Created Brain class and ensuring memory management with deep copying.
  - ex02: Modified Animal class to make it abstract.
  - ex03: Created pure abstract class as interface.

**CPP_05: Repetition and exceptions**
- Avoiding code repetition, understanding how to make better classes and using exceptions for error handling.
  - ex00: Created Bureaucrat class.
  - ex01: Added const name, getters and << operator and Form class (for Bureucrat to "sign").
  - ex02: Used abstract class as base for other Form classes.
  - ex03: Created an "Intern" class that creates Form classes.

**CPP_06: Type casting, serialization**
- Learning about static_cast, dynamic_cast, const_cast and reinterpret_cast. Correctly converting between different types and how to use each type of cast.
  - ex00: Created converter that outputs value in different formats.
  - ex01: Learnt about pointer serialization.
  - ex02: Implemented way to indentify randomly created instance of base class.

**CPP_07: Templates and standard template library**
- Usage of templates, function templates and class templates to keep code reusable and utilization of STL containers and algorithms.
  - ex00: Created function templates.
  - ex01: Created another function template that can take function template as parameter.
  - ex02: Created Array template that can be filles and elements accessed.

**CPP_08: Templated containers and iterators**
- Usage of templated containers and custom iterators when working with different data types and structures.
  - ex00: Made function template to search for an int in a container of integers.
  - ex01: Created class with container of integers to find spans between them.
  - ex02: Made std::stack iterable.

**CPP_09: Focused on Standard Template Library**
- Learnt about memory management, STL and overall deepened knowledge.
  - ex00: Program that reads CSV file and gives info of specific date.
  - ex01: A program that does calculations according to Reverse Polish Notation rules.
  - ex02: Program that sorts positive integers using merge-insert sort algorithm.
