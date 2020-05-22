//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#include "queue.hpp"

int main() {
    using q = Queue<std::string>;
    using std::cout;
    q test_queue;
    test_queue.insert("aaaa", 6.0);
    test_queue.insert("bbbb", 1.0);
    test_queue.change_priority("bbbb", 8.0);
    cout << "Test";
    //test_queue.swap_entries(0,1);
    //int min = test_queue.extract_min();
}


//TODO: Tests automatisieren.