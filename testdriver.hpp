//
// Created by Mina (Marina Inokuchi) on 22.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_TESTDRIVER_HPP
#define ROUTENPLANUNG_CPP_TESTDRIVER_HPP

#include "queue.hpp"
#include <string>
#include <ctime>

class Testdriver {
private:
    template <typename T>
    bool test_min_heap_correctness(const Queue<T>& queue, int start_index) const;
    
    static void print_success_message(bool test_successful, int test_number, const std::string& type_name);
    
    static std::string generate_pseudo_random_string(int length);
    
    static int generate_pseudo_random_int();
    
    static float generate_pseudo_random_float();
    
    static double generate_pseudo_random_double();
    
    template <typename T>
    void insert_strings_to_queue(Queue<T>& queue, int number_of_inserts);
    
    template <typename T>
    void insert_ints_to_queue(Queue<T>& queue, int number_of_inserts);
    
    template <typename T>
    void insert_floats_to_queue(Queue<T>& queue, int number_of_inserts);
    
    template <typename T>
    void insert_doubles_to_queue(Queue<T>& queue, int number_of_inserts);
    
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
    void execute_all_tests(const std::string& type_name);
    
    template <typename T>
    void test_cleanup(const std::string& type_name) const;

public:
    
    static void execute_tests();
};

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
    if (parent_exists && heap_correct &&
        queue.get_entry_at(start_index).get_priority() < queue.get_entry_at(parent_index).get_priority()) {
        heap_correct = false;
    }
    return heap_correct;
}

void Testdriver::print_success_message(bool test_successful, int test_number, const std::string& type_name) {
    if (test_successful) {
        std::cout << "Test " << test_number << " erfolgreich. (Datentyp: " << type_name << ")" << std::endl;
    } else {
        std::cout << "Test " << test_number << " FEHLGESCHLAGEN!!! (Datentyp: " << type_name << ")" << std::endl;
    }
}

std::string Testdriver::generate_pseudo_random_string(int length) {
    char s[length+1];
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < length; ++i) {
        s[i] = alphanum[rand() % 61];
    }
    
    s[length] = 0;
    return s;
}

int Testdriver::generate_pseudo_random_int() {
    return static_cast<int>(rand());
}

float Testdriver::generate_pseudo_random_float() {
    return static_cast<float>(rand()) / 14.0f + 1.0f; // generate at least 1.0 for testing reasons
}

double Testdriver::generate_pseudo_random_double() {
    return static_cast<double>(rand()) / 13.0;
}

template <typename T>
void Testdriver::insert_strings_to_queue(Queue<T>& queue, int number_of_inserts) {
    for (int i = 0; i < number_of_inserts; i++) {
        queue.insert(generate_pseudo_random_string(10), generate_pseudo_random_double());
    }
}

template <typename T>
void Testdriver::insert_ints_to_queue(Queue<T>& queue, int number_of_inserts) {
    for (int i = 0; i < number_of_inserts; i++) {
        queue.insert(generate_pseudo_random_int(), generate_pseudo_random_double());
    }
}

template <typename T>
void Testdriver::insert_floats_to_queue(Queue<T>& queue, int number_of_inserts) {
    for (int i = 0; i < number_of_inserts; i++) {
        queue.insert(generate_pseudo_random_float(), generate_pseudo_random_double());
    }
}

template <typename T>
void Testdriver::insert_doubles_to_queue(Queue<T>& queue, int number_of_inserts) {
    for (int i = 0; i < number_of_inserts; i++) {
        queue.insert(generate_pseudo_random_double(), generate_pseudo_random_double());
    }
}

template <typename T>
void Testdriver::test01(const std::string& type_name) {
    bool test_successful = false;
    Queue<T> test_queue01;
    try {
        test_queue01.extract_min();
    } catch (EmptyHeapException&) {
        test_successful = true;
    }
    print_success_message(test_successful, 1, type_name);
}

/**
 * Testet, ob eine ValueNotFoundException geworfen wird, wenn versucht wird,
 * die Priorität von einem Element zu ändern, das es nicht gibt.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test02(const std::string& type_name) {
    bool test_successful = false;
    if (type_name == "string") {
        Queue<std::string> test_queue_02_1;
        test_queue_02_1.insert("aaa", 2.0);
        test_queue_02_1.insert("bbb", 3.5);
        try {
            test_queue_02_1.change_priority("ccc", 5.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue_02_2;
        test_queue_02_2.insert(3, 3.0);
        test_queue_02_2.insert(2, 2.0);
        try {
            test_queue_02_2.change_priority(5, 5.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue_02_3;
        test_queue_02_3.insert(5.0, 5.0);
        test_queue_02_3.insert(3.0, 3.0);
        try {
            test_queue_02_3.change_priority(6.0, 6.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else {
        Queue<double> test_queue_02_4;
        test_queue_02_4.insert(5.0, 5.0);
        test_queue_02_4.insert(3.0, 3.0);
        try {
            test_queue_02_4.change_priority(6.0, 6.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    }
    print_success_message(test_successful, 2, type_name);
}

/**
 * Testet, ob eine ValueNotFoundException geworfen wird, wenn versucht wird,
 * ein Element aus der Queue zu entfernen, das es nicht gibt.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test03(const std::string& type_name) {
    bool test_successful = false;
    if (type_name == "string") {
        Queue<std::string> test_queue_03_1;
        test_queue_03_1.insert("aaa", 2.0);
        test_queue_03_1.insert("bbb", 3.5);
        try {
            test_queue_03_1.remove("ccc");
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue_03_2;
        test_queue_03_2.insert(3, 3.0);
        test_queue_03_2.insert(2, 2.0);
        try {
            test_queue_03_2.remove(5);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue_03_3;
        test_queue_03_3.insert(5.0, 5.0);
        test_queue_03_3.insert(3.0, 3.0);
        try {
            test_queue_03_3.remove(6.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else {
        Queue<double> test_queue_03_4;
        test_queue_03_4.insert(5.0, 5.0);
        test_queue_03_4.insert(3.0, 3.0);
        try {
            test_queue_03_4.remove(6.0);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    }
    print_success_message(test_successful, 3, type_name);
}

/**
 * Testet, ob der Wert und die zugehörige Priorität beim Sortieren des Heaps beieinander bleiben.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test04(const std::string& type_name) {
    bool test_successful = false;
    if (type_name == "string") {
        Queue<std::string> test_queue_04_1;
        test_queue_04_1.insert("aaa", 2.0);
        test_queue_04_1.insert("bbb", 1.5);
        if (test_queue_04_1.get_entry_at(0).get_value() == "bbb" && test_queue_04_1.get_entry_at(0).get_priority() == 1.5) {
            test_successful = true;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue_04_2;
        test_queue_04_2.insert(3, 3.0);
        test_queue_04_2.insert(2, 2.0);
        if (test_queue_04_2.get_entry_at(0).get_value() == 2 && test_queue_04_2.get_entry_at(0).get_priority() == 2.0) {
            test_successful = true;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue_04_3;
        test_queue_04_3.insert(5.0, 5.0);
        test_queue_04_3.insert(3.0, 3.0);
        if (test_queue_04_3.get_entry_at(0).get_value() == 3.0 && test_queue_04_3.get_entry_at(0).get_priority() == 3.0) {
            test_successful = true;
        }
    } else {
        Queue<double> test_queue_04_4;
        test_queue_04_4.insert(5.0, 5.0);
        test_queue_04_4.insert(3.0, 3.0);
        if (test_queue_04_4.get_entry_at(0).get_value() == 3.0 && test_queue_04_4.get_entry_at(0).get_priority() == 3.0) {
            test_successful = true;
        }
    }
    print_success_message(test_successful, 4, type_name);
}

/**
 * Testet, ob der Heap nach Einfügen von vielen Werten korrekt sortiert bleibt.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test05(const std::string& type_name) {
    bool test_successful;
    if (type_name == "string") {
        Queue<std::string> test_queue05_1;
        insert_strings_to_queue(test_queue05_1, 50);
        test_successful = test_min_heap_correctness(test_queue05_1, 0);
    } else if (type_name == "int") {
        Queue<int> test_queue05_2;
        insert_ints_to_queue(test_queue05_2, 50);
        test_successful = test_min_heap_correctness(test_queue05_2, 0);
    } else if (type_name == "float") {
        Queue<float> test_queue05_3;
        insert_floats_to_queue(test_queue05_3, 50);
        test_successful = test_min_heap_correctness(test_queue05_3, 0);
    } else {
        Queue<double> test_queue05_4;
        insert_doubles_to_queue(test_queue05_4, 50);
        test_successful = test_min_heap_correctness(test_queue05_4, 0);
    }
    print_success_message(test_successful, 5, type_name);
}

/**
 *  Testet, ob die Kapazität des Heaps korrekt vergrößert wird, sobald die Kapazitätsgrenze erreicht ist.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test06(const std::string& type_name) {
    bool test_successful;
    if (type_name == "string") {
        Queue<std::string> test_queue06_1;
        insert_strings_to_queue(test_queue06_1, 401);
        test_successful = Entry<std::string>::num_of_entries_alive == 800;
    } else if (type_name == "int") {
        Queue<int> test_queue06_2;
        insert_ints_to_queue(test_queue06_2, 401);
        test_successful = Entry<int>::num_of_entries_alive == 800;
    } else if (type_name == "float") {
        Queue<float> test_queue06_3;
        insert_floats_to_queue(test_queue06_3, 401);
        test_successful = Entry<float>::num_of_entries_alive == 800;
    } else {
        Queue<double> test_queue06_4;
        insert_doubles_to_queue(test_queue06_4, 401);
        test_successful = Entry<double>::num_of_entries_alive == 800;
    }
    print_success_message(test_successful, 6, type_name);
}

/**
 * Testet, ob die Methode extract_min() wie erwartet das Element
 * mit der kleinsten Priorität liefert, den Heap um eins
 * verkleinert und anschließend richtig sortiert.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test07(const std::string& type_name) {
    bool test_successful;
    if (type_name == "string") {
        Queue<std::string> test_queue07_1;
        insert_strings_to_queue(test_queue07_1, 99);
        std::string expected_result = test_queue07_1.get_entry_at(0).get_value();
        std::string result = test_queue07_1.extract_min();
        test_successful = expected_result == result && test_min_heap_correctness(test_queue07_1, 0) && test_queue07_1.get_next() == 98;
    } else if (type_name == "int") {
        Queue<int> test_queue07_2;
        insert_ints_to_queue(test_queue07_2, 99);
        int expected_result = test_queue07_2.get_entry_at(0).get_value();
        int result = test_queue07_2.extract_min();
        test_successful = expected_result == result && test_min_heap_correctness(test_queue07_2, 0) && test_queue07_2.get_next() == 98;
    } else if (type_name == "float") {
        Queue<float> test_queue07_3;
        insert_floats_to_queue(test_queue07_3, 99);
        float expected_result = test_queue07_3.get_entry_at(0).get_value();
        float result = test_queue07_3.extract_min();
        test_successful = expected_result == result && test_min_heap_correctness(test_queue07_3, 0) && test_queue07_3.get_next() == 98;
    } else {
        Queue<double> test_queue07_4;
        insert_doubles_to_queue(test_queue07_4, 99);
        double expected_result = test_queue07_4.get_entry_at(0).get_value();
        double result = test_queue07_4.extract_min();
        test_successful = expected_result == result && test_min_heap_correctness(test_queue07_4, 0) && test_queue07_4.get_next() == 98;
    }
    print_success_message(test_successful, 7, type_name);
}


/**
 * Testet, ob die Methode remove() das gesuchte Element entfernt, egal wo es sich befindet.
 * @tparam T (typename)
 * @param type_name
 */
template <typename T>
void Testdriver::test08(const std::string& type_name) {
    bool test_successful = false;
    if (type_name == "string") {
        Queue<std::string> test_queue08_1;
        insert_strings_to_queue(test_queue08_1, 200);
        std::string string_to_insert = generate_pseudo_random_string(20);
        float prio_to_insert = generate_pseudo_random_float();
        test_queue08_1.insert(string_to_insert, prio_to_insert);
        test_queue08_1.remove(string_to_insert);
        try {
            test_queue08_1.remove(string_to_insert);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue08_2;
        insert_ints_to_queue(test_queue08_2, 200);
        int int_to_insert = RAND_MAX + 3; // generate number that is unique in queue
        float prio_to_insert = generate_pseudo_random_float();
        test_queue08_2.insert(int_to_insert, prio_to_insert);
        test_queue08_2.remove(int_to_insert);
        try {
            test_queue08_2.remove(int_to_insert);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue08_3;
        insert_floats_to_queue(test_queue08_3, 200);
        float float_to_insert = RAND_MAX * 2.1; // generate number that is unique in queue
        float prio_to_insert = generate_pseudo_random_float();
        test_queue08_3.insert(float_to_insert, prio_to_insert);
        test_queue08_3.remove(float_to_insert);
        try {
            test_queue08_3.remove(float_to_insert);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    } else {
        Queue<double> test_queue08_4;
        insert_doubles_to_queue(test_queue08_4, 200);
        double double_to_insert = RAND_MAX * 2.1; // generate number that is unique in queue
        float prio_to_insert = generate_pseudo_random_float();
        test_queue08_4.insert(double_to_insert, prio_to_insert);
        test_queue08_4.remove(double_to_insert);
        try {
            test_queue08_4.remove(double_to_insert);
        } catch (ValueNotFoundException&) {
            test_successful = true;
        }
    }
    print_success_message(test_successful, 8, type_name);
}


//TODO: test decrease_capacity()!!!
template <typename T>
void Testdriver::test09(const std::string& type_name) {
    bool test_successful = false;
    if (type_name == "string") {
        Queue<std::string> test_queue09_1;
        insert_strings_to_queue(test_queue09_1, 201);
        test_successful = test_queue09_1.get_size() == 400;
        if (test_successful) {
            for (int i = 1; i <= 69; i++) {
                test_queue09_1.extract_min();
            }
            test_successful = test_queue09_1.get_size() == 200;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue09_2;
        insert_ints_to_queue(test_queue09_2, 201);
        test_successful = test_queue09_2.get_size() == 400;
        if (test_successful) {
            for (int i = 1; i <= 69; i++) {
                test_queue09_2.extract_min();
            }
            test_successful = test_queue09_2.get_size() == 200;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue09_3;
        insert_floats_to_queue(test_queue09_3, 201);
        test_successful = test_queue09_3.get_size() == 400;
        if (test_successful) {
            for (int i = 1; i <= 69; i++) {
                test_queue09_3.extract_min();
            }
            test_successful = test_queue09_3.get_size() == 200;
        }
    } else {
        Queue<double> test_queue09_4;
        insert_doubles_to_queue(test_queue09_4, 201);
        test_successful = test_queue09_4.get_size() == 400;
        if (test_successful) {
            for (int i = 1; i <= 69; i++) {
                test_queue09_4.extract_min();
            }
            test_successful = test_queue09_4.get_size() == 200;
        }
    }
    print_success_message(test_successful, 9, type_name);
}


//TODO: test change_key()!!!!!
template <typename T>
void Testdriver::test10(const std::string& type_name) {
    bool test_successful = false;
    
    if (type_name == "string") {
        Queue<std::string> test_queue10_1;
        insert_strings_to_queue(test_queue10_1, 500);
        test_queue10_1.insert("aaa", 1000.1); // insert an unique element
        test_queue10_1.change_priority("aaa", 0.5); // unique element should now be at index 0
        if (test_queue10_1.extract_min() == "aaa") {
            test_successful = true;
        }
    } else if (type_name == "int") {
        Queue<int> test_queue10_2;
        insert_ints_to_queue(test_queue10_2, 500);
        test_queue10_2.insert(RAND_MAX+3, 1000.1); // insert an unique element
        test_queue10_2.change_priority(RAND_MAX+3, 0.5); // unique element should now be at index 0
        if (test_queue10_2.extract_min() == RAND_MAX+3) {
            test_successful = true;
        }
    } else if (type_name == "float") {
        Queue<float> test_queue10_3;
        insert_floats_to_queue(test_queue10_3, 500);
        test_queue10_3.insert(RAND_MAX, 1000.1); // insert an unique element
        test_queue10_3.change_priority(RAND_MAX, 0.5); // unique element should now be at index 0
        if (test_queue10_3.extract_min() == RAND_MAX) {
            test_successful = true;
        }
    } else {
        Queue<double> test_queue10_4;
        insert_doubles_to_queue(test_queue10_4, 500);
        test_queue10_4.insert(RAND_MAX, 1000.1); // insert an unique element
        test_queue10_4.change_priority(RAND_MAX, 0.5); // unique element should now be at index 0
        if (test_queue10_4.extract_min() == RAND_MAX) {
            test_successful = true;
        }
    }
    print_success_message(test_successful, 10, type_name);
}

template <typename T>
void Testdriver::execute_all_tests(const std::string& type_name) {
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
}

template <typename T>
void Testdriver::test_cleanup(const std::string& type_name) const {
    if (Queue<T>::num_of_queues_alive == 0 && Entry<T>::num_of_entries_alive == 0) {
        std::cout << "Test 11 erfolgreich. (Datentyp: " << type_name << ")" << std::endl;
    } else {
        std::cout << "Test 11 FEHLGESCHLAGEN!!! (Datentyp: " << type_name << ")" << std::endl;
    }
}

void Testdriver::execute_tests() {
    Testdriver testdriver;
    testdriver.execute_all_tests<int>("int");
    testdriver.test_cleanup<int>("int");
    std::cout << std::endl;
    testdriver.execute_all_tests<float>("float");
    testdriver.test_cleanup<float>("float");
    std::cout << std::endl;
    testdriver.execute_all_tests<double>("double");
    testdriver.test_cleanup<double>("double");
    std::cout << std::endl;
    testdriver.execute_all_tests<std::string>("string");
    testdriver.test_cleanup<std::string>("string");
}

#endif //ROUTENPLANUNG_CPP_TESTDRIVER_HPP