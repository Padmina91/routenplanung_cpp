//
// Created by Mina (Marina Inokuchi) on 22.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_TESTDRIVER_HPP
#define ROUTENPLANUNG_CPP_TESTDRIVER_HPP

#include "queue.hpp"
#include <string>

class Testdriver {
// -------------------------------------- private const methods ---------------------------------------
private:
    template <typename T>
    bool test_min_heap_correctness(Queue<T> const& queue, int start_index) const;

// ------------------------------------ private non-const methods -------------------------------------
    
    template <typename T>
    void test01(const std::string& type_name);
    
    template <typename T>
    void test02(const std::string& type_name);
    
    template <typename T>
    void test03(const std::string& type_name);
    
    template <typename T>
    void test04(const std::string& type_name);
    
    template <typename T>
    void test05(const std::string& type_name);
    
    template <typename T>
    void test06(const std::string& type_name);
    
    template <typename T>
    void test07(const std::string& type_name);
    
    template <typename T>
    void test08(const std::string& type_name);
    
    template <typename T>
    void test09(const std::string& type_name);
    
    template <typename T>
    void test10(const std::string& type_name);
    
    template <typename T>
    void test11(const std::string& type_name);
    
    template <typename T>
    void test12(const std::string& type_name);
    
    template <typename T>
    void test13(const std::string& type_name);
    
    template <typename T>
    void test14(const std::string& type_name);
    
    template <typename T>
    void execute_all_tests(const std::string& type_name);

// -------------------------------------- public static methods ---------------------------------------
public:

    static void execute_tests();
};

// -------------------------------------- private const methods ---------------------------------------

template <typename T>
bool Testdriver::test_min_heap_correctness(Queue<T> const& queue, int start_index) const {
    int parent_index = Queue<T>::index_of_parent(start_index);
    int left_child_index = Queue<T>::index_of_left_child(start_index);
    int right_child_index = Queue<T>::index_of_right_child(start_index);
    bool heap_correct = true;
    bool left_child_exists = queue.get_next() > left_child_index;
    bool right_child_exists = queue.get_next() > right_child_index;
    bool parent_exists = parent_index != -1;
    if (left_child_exists) {
        heap_correct = test_min_heap_correctness(queue, left_child_index);
    }
    if (heap_correct && right_child_exists) {
        heap_correct = test_min_heap_correctness(queue, right_child_index);
    }
    if (parent_exists && heap_correct && queue.get_entry_at(start_index).get_priority() < queue.get_entry_at(parent_index).get_priority()) {
        heap_correct = false;
    }
    return heap_correct;
}


// ------------------------------------ private non-const methods -------------------------------------

template <typename T>
void Testdriver::test01(const std::string& type_name) {

}

template <typename T>
void Testdriver::test02(const std::string& type_name) {
}

template <typename T>
void Testdriver::test03(const std::string& type_name) {
}

template <typename T>
void Testdriver::test04(const std::string& type_name) {
}

template <typename T>
void Testdriver::test05(const std::string& type_name) {
}

template <typename T>
void Testdriver::test06(const std::string& type_name) {
}

template <typename T>
void Testdriver::test07(const std::string& type_name) {
}

template <typename T>
void Testdriver::test08(const std::string& type_name) {
}

template <typename T>
void Testdriver::test09(const std::string& type_name) {
}

template <typename T>
void Testdriver::test10(const std::string& type_name) {
}

template <typename T>
void Testdriver::test11(const std::string& type_name) {
}

template <typename T>
void Testdriver::test12(const std::string& type_name) {
}

template <typename T>
void Testdriver::test13(const std::string& type_name) {
}

template <typename T>
void Testdriver::test14(const std::string& type_name) {
}

template <typename T>
void Testdriver::execute_all_tests(const std::string& type_name) {
}

// -------------------------------- public static methods declaration ---------------------------------
void Testdriver::execute_tests() {
}

#endif //ROUTENPLANUNG_CPP_TESTDRIVER_HPP