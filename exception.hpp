//
// Created by Mina (Marina Inokuchi) on 21.05.2020.
// Padmina91 (GitHub)
//

#ifndef ROUTENPLANUNG_CPP_EXCEPTION_HPP
#define ROUTENPLANUNG_CPP_EXCEPTION_HPP

#include <exception>

class EmptyHeapException : std::exception {};

class ValueNotFoundException: std::exception {};

class IndexOutOfBoundsException : std::exception {};

#endif //ROUTENPLANUNG_CPP_EXCEPTION_HPP