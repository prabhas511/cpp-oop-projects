# Library Management - Inheritance & Polymorphism

A C++ project designed to demonstrate inheritance and runtime polymorphism.

## Concepts demonstrated
- Base and derived classes
- Inheritance
- Protected members
- Function overriding
- Virtual functions
- Runtime polymorphism
- Constructors and destructors
- Pointers and dynamic memory
- Vectors

## Design
`LibraryItem` is the base class. `Book` and `Magazine` inherit from it and override `display()`.

A vector of `LibraryItem*` stores different derived objects. Calling `display()` through a base-class pointer demonstrates runtime polymorphism.

## How to run
`g++ main.cpp -std=c++11 -o library_demo`
`./library_demo`

## Important learning point
The virtual destructor allows derived objects to be safely destroyed through a base-class pointer.

## Extension ideas
- Add issue/return functionality
- Add member classes
- Add exception handling
- Replace raw pointers with smart pointers after learning them properly
