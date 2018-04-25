//
// Created by Nikola on 25/04/2018.
//

#ifndef VECT_REDUCE_H
#define VECT_REDUCE_H


#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>



template<typename Container>
typename Container::value_type min(const Container& c)
{
    typename Container::value_type result;
    result = * std::min_element(std::begin(c), std::end(c));
    return result;
}


template<typename Container>
typename Container::value_type max(const Container& c)
{
    typename Container::value_type result;
    result = * std::max_element(std::begin(c), std::end(c));
    return result;
}


template<typename Container>
typename Container::value_type mean(const Container& c)
{
    typename Container::value_type result;
    double sum= std::accumulate(std::begin(c), std::end(c), 0.0);


    return sum/c.size();
}


template<typename Container>
typename Container::value_type stdev(const Container& c)
{

    double m = mean(c);
    double accum = 0.0;
    std::for_each (std::begin(c), std::end(c), [&](const double d) {
        accum += (d - m) * (d - m);
    });

    return sqrt(accum / (c.size()-1));
}



template<typename Container, typename Predicate>
bool all(const Container& c, Predicate p) { return  std::all_of(std::begin(c), std::end(c), p); }

template<typename Container, typename Predicate>
bool any(const Container& c, Predicate p) { return  std::any_of(std::begin(c), std::end(c), p); }


template<typename Container >
long count(const Container& c,typename Container::value_type target ) {
    return std::count(std::begin(c), std::end(c), target);
}


template<typename Container ,  typename Predicate>
long count_if(const Container& c,Predicate p ) {
    return std::count_if(std::begin(c), std::end(c), p);
}




#endif //VECT_REDUCE_H
