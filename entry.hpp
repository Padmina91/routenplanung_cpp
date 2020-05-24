//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_ENTRY_HPP
#define ROUTENPLANUNG_CPP_ENTRY_HPP

#include <iostream>

template <typename T>
class Entry {
private:
    T _value;
    float _priority;

public:
    static int num_of_entries_alive;
    
    explicit Entry();
    
    Entry(Entry& original);
    
    ~Entry();
    
    T get_value() const;
    
    float get_priority() const;
    
    void set_value(T);
    
    void set_priority(float);
    
    Entry<T>& operator=(const Entry<T>& original);
};

template <typename T>
int Entry<T>::num_of_entries_alive = 0;

template <typename T>
Entry<T>::Entry() : _value(), _priority() {
    num_of_entries_alive++;
}

template <typename T>
Entry<T>::Entry(Entry& original) {
    _value = original.get_value();
    _priority = original.get_priority();
    num_of_entries_alive++;
}

template <typename T>
Entry<T>::~Entry<T>() {
    num_of_entries_alive--;
}

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
    _priority = original.get_priority();
    _value = original.get_value();
    return *this;
}

#endif //ROUTENPLANUNG_CPP_ENTRY_HPP