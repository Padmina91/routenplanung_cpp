//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_QUEUE_HPP
#define ROUTENPLANUNG_CPP_QUEUE_HPP

#include "entry.hpp"
#include "exception.hpp"

template <typename T>
class Queue {
private:
    Entry<T> *_entry;
    int _size;
    int _next;

public:
    explicit Queue();
    
    explicit Queue(T val, float prio);
    
    ~Queue();
};

template <typename T>
Queue<T>::Queue() {
    if (DEBUG) {
        std::cout << "Konstruktor von Queue ohne Parameter laeuft..." << std::endl;
    }
    _size = 3;
    _next = 0;
    _entry = new Entry<T>[_size]; // reserving space for _size entries on construction
}

template <typename T>
Queue<T>::Queue(T val, float prio) : Queue() {
    if (DEBUG) {
        std::cout << "Konstruktor von Queue mit 2 Parametern laeuft..." << std::endl;
    }
    _entry[0].set_element(val);
    _entry[0].set_priority(prio);
    _next = 1;
    if (DEBUG) {
        std::cout
                << "Konstruktor von Queue mit 2 Parametern sollte jetzt _entry[0] befuellt haben, lasst es uns testen: "
                << _entry[0].get_element() << ", Prio: " << _entry[0].get_priority() << std::endl;
        std::cout << "Und jetzt noch ein unbefuelltes Element: " << _entry[1].get_element() << ", Prio: "
                  << _entry[1].get_priority() << std::endl;
    }
}

template <typename T>
Queue<T>::~Queue() {
    if (DEBUG) {
        std::cout << "Destruktor von Queue laeuft...\nRufe delete[] _entry auf" << std::endl;
    }
    delete[] _entry;
}

#endif //ROUTENPLANUNG_CPP_QUEUE_HPP