//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_ENTRY_HPP
#define ROUTENPLANUNG_CPP_ENTRY_HPP

template <typename T>
class Entry {
private:
    T _element;
    float _priority;
    
public:
    explicit Entry() : _element(), _priority() {};
    
    explicit Entry(T& element, float priority) : _element(element), _priority(priority) {}
    
    T get_element();
    
    float get_priority();
    
    void set_element(T);
    
    void set_priority(float);
};

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