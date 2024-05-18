#ifndef SAFESHAREDPTR_H
#define SAFESHAREDPTR_H

#include <iostream>
#include <memory>
#include <cstdlib> // exit fn

template<typename T>
class SafeSharedPtr : public std::shared_ptr<T> {
public:
    // Inheriting constructors from std::shared_ptr
    using std::shared_ptr<T>::shared_ptr;

    // Overloading the -> operator
    T* operator->() const 
    {
        if(this->get() == nullptr) {
            // Terminates program when attempting to dereference a shared pointer
            std::cout<<"\033[1;31mError: Attempted to dereference a null Safe Shared Pointer. Terminating Program.\033[0m"<<std::endl;
            exit(EXIT_SUCCESS);
        }
        else
        {
            // Return the underlying pointer if it's not null
            return std::shared_ptr<T>::operator->();
        }   
    }
};

#endif
