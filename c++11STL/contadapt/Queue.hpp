#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>
#include <exception>

template<typename T>
class Queue {
    protected:
        std::deque<T> c;
    public:
        class ReadEmptyQueue : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "read empty queue";
                }
        };

        typename std::deque<T>::size_type size() const {
            return c.size();
        }
        
        bool empty() {
            return c.empty();
        }

        void push(const T& elem) {
            c.push_back(elem);
        }

        T pop() {
            if(c.empty()) {
                throw ReadEmptyQueue();
            }
            T elem(c.front());
            c.pop_front();
            return elem;
        }

        T& front() {
            if(c.empty()) {
                throw ReadEmptyQueue();
            }
            return c.front();
        }
};

#endif