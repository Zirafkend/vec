//
// Created by Nikola on 25/04/2018.
//

#ifndef VECT_RECT_H
#define VECT_RECT_H

#include <valarray>
#include <sstream>
#include "vec.h"
#include "nvec.h"

template <typename T> using rect = typename std::valarray < T >;


typedef rect<int> recti;
typedef rect<float> rectf;



#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
typedef rect<byte> rectb;
#endif

template <typename T>
std::string& printrect(const rect<T> &r) {
    std::string s;
    s + "x: " + r[0] + " y: " + r[1] + " w: " + r[2] + " h: " << r[3];

    return s;
}



template <typename T> bool          vertical(rect<T> r )        { return  r[3] > r[2]; }
template <typename T> bool          horizontal(rect<T> r)       { return r[2] > r[3];}
template <typename T> rect<T>       recenter(rect<T> r)         {r[0] -= r[2]/2.; r[1] -= r[3]/2;   return r; }
template <typename T> vec<T>        centroid(rect<T> r )        {return {r[0] + r[2] * 0.5, r[1] + r[3] * 0.5}; }
template <typename T> T             aspectratio(rect<T> r )     { return float(r[2] / r[3]); }
template <typename T> T             area(rect<T> r )            { return float(r[2] * r[3]); }
template <typename T> nvec<T>       corners(rect<T> r)          { return {{r[0], r[1]},{r[0] + r[2], r[1]},{r[0] + r[2], r[1] + r[3]}, {r[0], r[1] + r[3]}};}


#endif //VECT_RECT_H
