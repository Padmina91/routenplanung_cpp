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
    
    void decrease_capacity();
    
    void swap_entries(int, int);
    
    void remove_entry_at(int);
    
    int search_value(T, int);
    
    void assert_min_heap_bottom_up(int);
    
    void assert_min_heap_top_down(int);
    
    void assert_min_heap(int);

public:
// ---------------------------------------- public attributes -----------------------------------------
    static int num_of_queues_alive;  // only for debugging & testing

// ------------------------------------ constructors & destructor -------------------------------------
    explicit Queue();
    
    Queue(Queue&);
    
    ~Queue();

// ---------------------------------------- getters & setters -----------------------------------------
    int get_size() const;
    
    int get_next() const;
    
    Entry<T> get_entry_at(int) const;

// ------------------------------------- public non-const methods -------------------------------------
    void insert(T, float);
    
    void change_priority(T, float);
    
    void remove(T);
    
    T extract_min();

// -------------------------------------- public static methods ---------------------------------------
    static int index_of_parent(int);
    
    static int index_of_left_child(int);
    
    static int index_of_right_child(int);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
    for (int i = 0; i < queue.get_next(); i++) {
        os << "Element at " << i << ": " << queue.get_entry_at(i).get_value() << ", priority: "
           << queue.get_entry_at(i).get_priority() << std::endl;
    }
    return os;
}

// -------------------------------------- private const methods ---------------------------------------

template <typename T>
bool Queue<T>::is_empty() const {
    return _next == 0;
}

// ------------------------------------ private non-const methods -------------------------------------

template <typename T>
void Queue<T>::increase_capacity() {
    _size *= 2;
    auto *temp = new Entry<T>[_size];
    for (int i = 0; i < _next; i++) {
        temp[i] = _entries[i];
    }
    delete[] _entries;
    _entries = temp;
}

/**
 * Verringert die Kapazitaet. Kapazitaet faellt niemals unter 100.
 * @tparam T (typename)
 */
template <typename T>
void Queue<T>::decrease_capacity() {
    if (_next < _size / 3 && _size > 100) {
        _size /= 2;
        auto *temp = new Entry<T>[_size];
        for (int i = 0; i < _next; i++) {
            temp[i] = _entries[i];
        }
        delete[] _entries;
        _entries = temp;
    }
}

template <typename T>
void Queue<T>::swap_entries(int x, int y) {
    Entry<T> temp = _entries[x];
    _entries[x] = _entries[y];
    _entries[y] = temp;
}

template <typename T>
void Queue<T>::remove_entry_at(int index) {
    _next--;
    swap_entries(index, _next);
    assert_min_heap(index);
    if (_next < _size / 3 && _size > 100) {
        decrease_capacity();
    }
}

template <typename T>
int Queue<T>::search_value(T val, int start_index) {
    int found_index = -1;
    int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    T current_val = _entries[start_index].get_value();
    if (val == current_val) {
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

template <typename T>
void Queue<T>::assert_min_heap_bottom_up(int start_index) {
    int parent_index = index_of_parent(start_index);
    int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    bool parent_exists = parent_index != -1;
    if (left_child_exists) {
        assert_min_heap_bottom_up(left_child_index);
    }
    if (right_child_exists) {
        assert_min_heap_bottom_up(right_child_index);
    }
    if (parent_exists && _entries[start_index].get_priority() < _entries[parent_index].get_priority()) {
        swap_entries(start_index, parent_index);
    }
}

template <typename T>
void Queue<T>::assert_min_heap_top_down(int start_index) {
    int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    if (left_child_exists && right_child_exists) {
        if (_entries[left_child_index].get_priority() < _entries[right_child_index].get_priority()) {
            if (_entries[left_child_index].get_priority() < _entries[start_index].get_priority()) {
                swap_entries(start_index, left_child_index);
                assert_min_heap_top_down(left_child_index);
            }
        } else if (_entries[right_child_index].get_priority() < _entries[start_index].get_priority()) {
            swap_entries(start_index, right_child_index);
            assert_min_heap_top_down(right_child_index);
        }
    } else if (left_child_exists && _entries[left_child_index].get_priority() < _entries[start_index].get_priority()) {
        swap_entries(start_index, left_child_index);
    }
}

template <typename T>
void Queue<T>::assert_min_heap(int index) {
    int parent_index = index_of_parent(index);
    int left_child_index = index_of_left_child(index);
    int right_child_index = index_of_right_child(index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    bool parent_exists = parent_index != -1;
    if (parent_exists && _entries[index].get_priority() < _entries[parent_index].get_priority()) {
        assert_min_heap_bottom_up(0);
    } else if ((left_child_exists && _entries[index].get_priority() > _entries[left_child_index].get_priority())
               || (right_child_exists && _entries[index].get_priority() > _entries[right_child_index].get_priority())) {
        assert_min_heap_top_down(0);
    }
}

// ---------------------------------------- public attributes -----------------------------------------

template <typename T>
int Queue<T>::num_of_queues_alive = 0; // only for debugging & testing

// ------------------------------------ constructors & destructor -------------------------------------

template <typename T>
Queue<T>::Queue() {
    _size = 100;
    _next = 0;
    _entries = new Entry<T>[_size]; // reserving space for _size entries upon construction
    num_of_queues_alive++;
}

template <typename T>
Queue<T>::Queue(Queue& original) {
    _size = original.get_size();
    _next = original.get_next();
    for (int i = 0; i < _next; i++) {
        _entries[i] = original.get_entry_at(i);
    }
    num_of_queues_alive++;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] _entries;
    num_of_queues_alive--;
}

// ---------------------------------------- getters & setters -----------------------------------------

template <typename T>
int Queue<T>::get_size() const {
    return _size;
}

template <typename T>
int Queue<T>::get_next() const {
    return _next;
}

template <typename T>
Entry<T> Queue<T>::get_entry_at(int index) const {
    return _entries[index];
}

// ------------------------------------- public non-const methods -------------------------------------

template <typename T>
void Queue<T>::insert(T val, float prio) {
    if (prio > 0.0) {
        if (_size == _next) {
            increase_capacity();
        }
        _entries[_next].set_value(val);
        _entries[_next].set_priority(prio);
        _next++;
        assert_min_heap(_next);
    }
}

template <typename T>
void Queue<T>::change_priority(T val, float prio) {
    int index = search_value(val, 0);
    if (index != -1) {
        _entries[index].set_priority(prio);
        assert_min_heap(index);
    } else {
        throw ValueNotFoundException();
    }
}

template <typename T>
void Queue<T>::remove(T val) {
    int index = search_value(val, 0);
    if (index != -1) {
        remove_entry_at(index);
    } else {
        throw ValueNotFoundException();
    }
}

template <typename T>
T Queue<T>::extract_min() {
    T smallest_element;
    if (!is_empty()) {
        smallest_element = _entries[0].get_value();
        remove_entry_at(0);
        return smallest_element;
    }
    throw EmptyHeapException();
}


// -------------------------------------- public static methods ---------------------------------------

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

#endif //ROUTENPLANUNG_CPP_QUEUE_HPP