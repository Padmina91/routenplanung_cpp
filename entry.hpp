//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_ENTRY_HPP
#define ROUTENPLANUNG_CPP_ENTRY_HPP

#include <iostream>

#define DEBUG true

template <typename T>
class Entry {
private:
    T _value;
    float _priority;

public:
    explicit Entry();
    
    //explicit Entry(T& val, float prio);
    
    T get_value() const;
    
    float get_priority() const;
    
    void set_value(T);
    
    void set_priority(float);
    
    Entry<T>& operator=(const Entry<T>& original);
};

template <typename T>
Entry<T>::Entry() : _value(), _priority() {}

//template <typename T>
//Entry<T>::Entry(T& val, float prio) : _value(val), _priority(prio) {}


template <typename T>
T Entry<T>::get_value() const {
    return _value;
}

template <typename T>
float Entry<T>::get_priority() const {
    return _priority;
}

template <typename T>
void Entry<T>::set_value(T element) {
    _value = element;
}

template <typename T>
void Entry<T>::set_priority(float prio) {
    _priority = prio;
}

template <typename T>
Entry<T>& Entry<T>::operator=(const Entry<T>& original) {
    //std::cout << "operator=() wird ausgefuehrt...\n";
    _priority = original.get_priority();
    _value = original.get_value();
    return *this;
}

#endif //ROUTENPLANUNG_CPP_ENTRY_HPP