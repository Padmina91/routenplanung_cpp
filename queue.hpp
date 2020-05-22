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
// ---------------------------------------- private attributes ----------------------------------------
    Entry<T> *_entries;
    int _size;
    int _next;

// -------------------------------------- private const methods ---------------------------------------
    bool is_empty() const;

// ------------------------------------ private non-const methods -------------------------------------
    void increase_capacity();
    
    void remove_entry_at(int index);
    
    void swap_entries(int x, int y);
    
    int search_value(T val, int start_index);

// -------------------------------------- private static methods --------------------------------------
    static int index_of_parent(int start_index);
    
    static int index_of_left_child(int start_index);
    
    static int index_of_right_child(int start_index);

public:
// ------------------------------------ constructors & destructor -------------------------------------
    explicit Queue();
    
    ~Queue();
// ------------------------------------- public non-const methods -------------------------------------
    
    void insert(T val, float prio);
    
    void change_priority(T val, float prio);
    
    T extract_min();
};

// -------------------------------------- private const methods ---------------------------------------

template <typename T>
bool Queue<T>::is_empty() const {
    return _next == 0;
}

// ------------------------------------ private non-const methods -------------------------------------

template <typename T>
void Queue<T>::increase_capacity() {
    _size *= 2; //TODO: maybe don't just double it?
    auto *temp = new Entry<T>[_size];
    for (int i = 0; i < _next; i++) {
        temp[i] = _entries[i];
    }
    delete[] _entries;
    _entries = temp;
}

template <typename T>
void Queue<T>::remove_entry_at(int index) {
    _next--;
    swap_entries(index, _next);
    //TODO: assert_min_heap_top_down
}

template <typename T>
void Queue<T>::swap_entries(int x, int y) {
    Entry<T> temp = _entries[x];
    _entries[x] = _entries[y];
    _entries[y] = temp;
}

template <typename T>
int Queue<T>::search_value(T val, int start_index) {
    int found_index = -1;
    int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    if (val == _entries[start_index].get_value()) {
        return start_index;
    }
    if (left_child_exists) {
        found_index = search_value(val, left_child_index);
    }
    if (found_index < 0 && right_child_exists) {
        found_index = search_value(val, right_child_index);
    }
    return found_index;
}

// -------------------------------------- private static methods --------------------------------------

template <typename T>
int Queue<T>::index_of_parent(int start_index) {
    if (start_index > 0) {
        return (start_index - 1) / 2;
    } else {
        return -1;
    }
}

template <typename T>
int Queue<T>::index_of_left_child(int start_index) {
    return start_index * 2 + 1;
}

template <typename T>
int Queue<T>::index_of_right_child(int start_index) {
    return start_index * 2 + 2;
}

// ------------------------------------ constructors & destructor -------------------------------------

template <typename T>
Queue<T>::Queue() {
    _size = 3;
    _next = 0;
    _entries = new Entry<T>[_size]; // reserving space for _size entries on construction
}

template <typename T>
Queue<T>::~Queue() {
    delete[] _entries;
}

// ------------------------------------- public non-const methods -------------------------------------

template <typename T>
void Queue<T>::insert(T val, float prio) {
    if (_size == _next) {
        increase_capacity();
    }
    _entries[_next].set_value(val);
    _entries[_next].set_priority(prio);
    _next++;
    //TODO: assert_min_heap_...
}

template <typename T>
void Queue<T>::change_priority(T val, float prio) {
    int index = search_value(val, 0);
    if (index != -1) {
        _entries[index].set_priority(prio);
        std::cout << "Priority successfully changed to " << _entries[index].get_priority() << std::endl;
    }
    //TODO: Heap neu sortieren.
}

template <typename T>
T Queue<T>::extract_min() {
    T smallest_element;
    if (!is_empty()) {
        smallest_element = _entries[0].get_value();
    }
    remove_entry_at(0);
    return smallest_element;
}

#endif //ROUTENPLANUNG_CPP_QUEUE_HPP