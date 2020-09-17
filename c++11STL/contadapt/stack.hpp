#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <exception>

template <typename T>
class Stack {
protected:
    std::deque<T> c;
public:
    class ReadEmptyStack : public std::exception {
    public:
        vitrual const char *what() const throw() {
            return "read empty stack";
        }
    }
};