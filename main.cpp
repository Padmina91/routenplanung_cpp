//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#include "queue.hpp"

int main() {
    Queue<std::string> test_queue;
    test_queue.insert("aaaa", 6.0);
    test_queue.insert("bbbb", 1.0);
    test_queue.change_priority("bbbb", 4.0);
    //test_queue.swap_entries(0,1);
    //int min = test_queue.extract_min();
}


//TODO: Direkt beim Anlegen ein bisschen Speicher vorreservieren.
//TODO: Erst dann Speicher verringern, wenn die Queue zur Hälfte leer ist.
//TODO: Tests automatisieren.
//TODO: Datenstruktur pqentry_t benutzen zur Kapselung von String + Priorität!
//TODO: Operatoren überladen. z.B. = als Konstruktor benutzen. + zum Einfügen benutzen.