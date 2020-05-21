//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_ENTRY_HPP
#define ROUTENPLANUNG_CPP_ENTRY_HPP

#include <iostream>

#define DEBUG false

template <typename T>
class Entry {
private:
    T _element;
    float _priority;

public:
    explicit Entry();
    
    explicit Entry(T& element, float priority);
    
    ~Entry();
    
    Entry<T>& operator=(Entry<T>);
    
    T get_element();
    
    float get_priority();
    
    void set_element(T);
    
    void set_priority(float);
};

template <typename T>
Entry<T>::Entry() : _element(), _priority() {
    if (DEBUG) {
        std::cout << "Konstruktor von Entry ohne Parameter laeuft..." << std::endl;
    }
}

template <typename T>
Entry<T>::Entry(T& element, float priority) : _element(element), _priority(priority) {
    if (DEBUG) {
        std::cout << "Konstruktor von Entry mit Parameter laeuft..." << std::endl;
    }
}

template <typename T>
Entry<T>::~Entry() {
    if (DEBUG) {
        std::cout << "Destruktor von Entry laeuft..." << std::endl;
    }
}

template <typename T>
Entry<T>& Entry<T>::operator=(Entry<T>) {
    Entry<T> temp = new Entry<T>(this->_element, this->_priority);
    return temp;
    //TODO: ????
}

template <typename T>
T Entry<T>::get_element() {
    return _element;
}

template <typename T>
float Entry<T>::get_priority() {
    return _priority;
}

template <typename T>
void Entry<T>::set_element(T element) {
    _element = element;
}

template <typename T>
void Entry<T>::set_priority(float prio) {
    _priority = prio;
}

#endif //ROUTENPLANUNG_CPP_ENTRY_HPP