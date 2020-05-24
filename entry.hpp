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
// ---------------------------------------- private attributes ----------------------------------------
    T _value;
    float _priority;

public:
// ---------------------------------------- public attributes -----------------------------------------
    static int num_of_entries_alive; // only for debugging

// ------------------------------------ constructors & destructor -------------------------------------
    explicit Entry();
    
    Entry(Entry&);
    
    ~Entry();

// ---------------------------------------- getters & setters -----------------------------------------
    T get_value() const;
    
    float get_priority() const;
    
    void set_value(T);
    
    void set_priority(float);

// ------------------------------------- public non-const methods -------------------------------------
    Entry<T>& operator=(const Entry<T>&);
};

// ****************************************************************************************************
// ****************************************************************************************************

// ---------------------------------------- public attributes -----------------------------------------

/**
 * Nur fuer debugging- und Testzwecke: Zaehlt die Anzahl der
 * Objekte der Klasse Entry, fuer die derzeit Speicher bereitgestellt wird.
 * @tparam T (typename)
 */
template <typename T>
int Entry<T>::num_of_entries_alive = 0;

// ------------------------------------ constructors & destructor -------------------------------------

/**
 * Konstruktor der Klasse Entry.
 * @tparam T (typename)
 */
template <typename T>
Entry<T>::Entry() : _value(), _priority() {
    num_of_entries_alive++;
}

/**
 * Copy-Constructor der Klasse Entry.
 * @tparam T (typename)
 * @param original (Entry&)
 */
template <typename T>
Entry<T>::Entry(Entry& original) {
    _value = original.get_value();
    _priority = original.get_priority();
    num_of_entries_alive++;
}

/**
 * Destruktor der Klasse Entry.
 * @tparam T (typename)
 */
template <typename T>
Entry<T>::~Entry<T>() {
    num_of_entries_alive--;
}

// ---------------------------------------- getters & setters -----------------------------------------

/**
 * Getter-Methode fuer das private Attribut _value.
 * @tparam T (typename)
 * @return _value
 */
template <typename T>
T Entry<T>::get_value() const {
    return _value;
}

/**
 * Getter-Methode fuer das private Attribut _priority.
 * @tparam T (typename)
 * @return _priority
 */
template <typename T>
float Entry<T>::get_priority() const {
    return _priority;
}

/**
 * Setter-Methode fuer das private Attribut _value.
 * @tparam T (typename)
 * @param val (T)
 */
template <typename T>
void Entry<T>::set_value(T val) {
    _value = val;
}

/**
 * Setter-Methode fuer das private Attribut _priority
 * @tparam T (typename)
 * @param prio (float)
 */
template <typename T>
void Entry<T>::set_priority(float prio) {
    _priority = prio;
}

// ------------------------------------- public non-const methods -------------------------------------

/**
 * Ueberladung des Zuweisungs-Operators.
 * @tparam T (typename)
 * @param original (const Entry<T>&)
 * @return *this (Entry<T>&)
 */
template <typename T>
Entry<T>& Entry<T>::operator=(const Entry<T>& original) {
    _priority = original.get_priority();
    _value = original.get_value();
    return *this;
}

#endif //ROUTENPLANUNG_CPP_ENTRY_HPP