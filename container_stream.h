//
// Created by Nikola on 25/04/2018.
//

#ifndef VECT_CONTAINER_STREAM_H
#define VECT_CONTAINER_STREAM_H

#include <ostream>
#include <deque>
#include <list>
#include <set>
#include <valarray>


template<typename Container >
std::ostream& print(std::ostream& os,const Container& c) {
    for(auto el : c) {
        os << el << ' ';
    }
    return os;
}



template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) { return print(os, v); }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& v) { return print(os, v); }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& v) { return print(os, v); }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& v) { return print(os, v); }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& v) { return print(os, v); }
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::valarray<T>& v) { return print(os, v); }




#endif //VECT_CONTAINER_STREAM_H
