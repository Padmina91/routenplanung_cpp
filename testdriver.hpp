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
    
    static void print_success_message(bool test_successful, int test_number, const std::string& type_name);

    template <typename T>
    void test01(const std::string& type_name) const;
    
    template <typename T>
    void test02(const std::string& type_name) const;
    
    template <typename T>
    void test03(const std::string& type_name) const;
    
    template <typename T>
    void test04(const std::string& type_name) const;
    
    template <typename T>
    void test05(const std::string& type_name) const;
    
    template <typename T>
    void test06(const std::string& type_name) const;
    
    template <typename T>
    void test07(const std::string& type_name) const;
    
    template <typename T>
    void test08(const std::string& type_name) const;
    
    template <typename T>
    void test09(const std::string& type_name) const;
    
    template <typename T>
    void test10(const std::string& type_name) const;
    
    template <typename T>
    void test11(const std::string& type_name) const;
    
    template <typename T>
    void test12(const std::string& type_name) const;
    
    template <typename T>
    void test13(const std::string& type_name) const;
    
    template <typename T>
    void test14(const std::string& type_name) const;
    
    template <typename T>
    void execute_all_tests(const std::string& type_name) const;
    
    template <typename T>
    void test_cleanup(const std::string& type_name) const;

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

void Testdriver::print_success_message(bool test_successful, int test_number, const std::string& type_name) {
    if (test_successful) {
        std::cout << "Test " << test_number << " erfolgreich. (Datentyp: " << type_name << ")" << std::endl;
    } else {
        std::cout << "Test " << test_number << " FEHLGESCHLAGEN!!! (Datentyp: " << type_name << ")" << std::endl;
    }
}

template <typename T>
void Testdriver::test01(const std::string& type_name) const {
    bool test_successful = false;
    Queue<T> test_queue01;
    try {
        test_queue01.extract_min();
    } catch (EmptyHeapException&) {
        test_successful = true;
    }
    print_success_message(test_successful, 1, type_name);
}

template <typename T>
void Testdriver::test02(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 2, type_name);
}

template <typename T>
void Testdriver::test03(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 3, type_name);
}

template <typename T>
void Testdriver::test04(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 4, type_name);
}

template <typename T>
void Testdriver::test05(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 5, type_name);
}

template <typename T>
void Testdriver::test06(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 6, type_name);
}

template <typename T>
void Testdriver::test07(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 7, type_name);
}

template <typename T>
void Testdriver::test08(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 8, type_name);
}

template <typename T>
void Testdriver::test09(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 9, type_name);
}

template <typename T>
void Testdriver::test10(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 10, type_name);
}

template <typename T>
void Testdriver::test11(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 11, type_name);
}

template <typename T>
void Testdriver::test12(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 12, type_name);
}

template <typename T>
void Testdriver::test13(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 13, type_name);
}

template <typename T>
void Testdriver::test14(const std::string& type_name) const {
    bool test_successful = false;
    
    
    print_success_message(test_successful, 14, type_name);
}

template <typename T>
void Testdriver::execute_all_tests(const std::string& type_name) const {
    Queue<T> test_queue;
    test01<T>(type_name);
    test02<T>(type_name);
    test03<T>(type_name);
    test04<T>(type_name);
    test05<T>(type_name);
    test06<T>(type_name);
    test07<T>(type_name);
    test08<T>(type_name);
    test09<T>(type_name);
    test10<T>(type_name);
    test11<T>(type_name);
    test12<T>(type_name);
    test13<T>(type_name);
    test14<T>(type_name);
}

template <typename T>
void Testdriver::test_cleanup(const std::string& type_name) const {
    if (Queue<T>::num_of_queues_alive == 0 && Entry<T>::num_of_entries_alive == 0) {
        std::cout << "Test XY erfolgreich. (Datentyp: " << type_name << ")" << std::endl;
    } else {
        std::cout << "Test XY FEHLGESCHLAGEN!!! (Datentyp: " << type_name << ")" << std::endl;
    }
}

// -------------------------------- public static methods declaration ---------------------------------
void Testdriver::execute_tests() {
    Testdriver testdriver;
    testdriver.execute_all_tests<int>("int");
    testdriver.test_cleanup<int>("int");
    testdriver.execute_all_tests<float>("float");
    testdriver.test_cleanup<float>("float");
    testdriver.execute_all_tests<double>("double");
    testdriver.test_cleanup<double>("double");
    testdriver.execute_all_tests<std::string>("string");
    testdriver.test_cleanup<std::string>("string");
}

#endif //ROUTENPLANUNG_CPP_TESTDRIVER_HPP