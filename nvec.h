//
// Created by Nikola on 17/04/2018.
//

#ifndef VECT_NVEC_H
#define VECT_NVEC_H


#include <vector>
#include "vec.h"

using namespace std;


template <typename T> using nvec = typename std::vector<  std::valarray < T >>;




template <typename T> nvec<T> operator+=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a += x; });     return pts;}
template <typename T> nvec<T> operator-=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a -= x; });     return pts;}
template <typename T> nvec<T> operator*=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a *= x; });     return pts;}
template <typename T> nvec<T> operator/=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a /= x; });     return pts;}
template <typename T> nvec<T> operator+=(nvec<T> pts , vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a += b; });     return pts;}
template <typename T> nvec<T> operator-=(nvec<T> pts , vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a -= b; });     return pts;}
template <typename T> nvec<T> operator*=(nvec<T> pts , vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a *= b; });     return pts;}
template <typename T> nvec<T> operator/=(nvec<T> pts , vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a /= b; });     return pts;}
typedef nvec<double> nvecd;
typedef nvec<float> nvecf;
typedef nvec<int> nveci;



//      poly 2


template <typename T> using line = typename std::vector < std::valarray < T >>;     // 2
typedef line<double> lined;
typedef line<float>  linef;
typedef line<int>    linei;
//typedef line<byte>   lineb;


// line methods
template <typename T> vec<T> midpoint(nvec<T> a, nvec<T> b)   { return (a + b) / 2; }
template <typename T> double heading(vec<T> a, vec<T> b)    { return atan2(a - b);}


// class method
template <typename T> static inline nvec<T> centerline(T distance, T rad){
    vec<T> a = theta(rad) * distance / 2.0;
    a ^=(M_PI);
    vec<T> b = a;
    return {a, b};
}



template <typename T> using tri = typename std::vector < std::valarray < T >>;         // 3



template <typename T> inline tri<T> create_equilateral(vec<T> a, vec<T> b,  float top_point=0.5){}

// cout
template <typename T> std::ostream& operator<< (std::ostream& o, tri<T> const& ) {return o << "tri"; }

template <typename T> inline bool contains (vec<T> a , tri<T> tri ){ return true; }
template <typename T> inline vec<T> center(tri<T> tri){ return (tri[0] + tri[1] + tri[2]) / 2; }

//template <typename T> inline double area(tri<T> tri){ return cross((tri[1] - tri[0]), (tri[2] - tri[0])) * 0.5; }



//      poly 4


//template <typename T> using rect = typename std::valarray < T >;         // 4

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
typedef rect<byte> rectb;
#endif


template <typename T>
struct rect{ T  x, y, width, height;
    rect(){};
    rect(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {}

    friend ostream &operator<<(ostream &os, const rect &r) {
        os << "x: " << r.x << " y: " << r.y << " width: " << r.width << " height: " << r.height;
        return os;
    }
};

typedef rect<int> recti;
typedef rect<float> rectf;

template <typename T> bool          vertical(rect<T> r )        { return  r.height > r.width; }
template <typename T> bool          horizontal(rect<T> r)       { return r.width > r.height;}
template <typename T> rect<T>       recenter(rect<T> r)         {r.x -= r.width/2.; r.y -= r.height/2;   return r; }
template <typename T> vec<T>        centroid(rect<T> r )        {return {r.x + r.width * 0.5, r.y + r.height * 0.5}; }
template <typename T> T             aspectratio(rect<T> r )     { return float(r.width / r.height); }
template <typename T> T             area(rect<T> r )            { return float(r.width * r.height); }
template <typename T> nvec<T>       corners(rect<T> r)          { return {{r.x, r.y},{r.x + r.width, r.y},{r.x + r.width, r.y + r.height}, {r.x, r.y + r.height}};}

// cpol

template <typename T> nvec<T> circ2pt(nvec<T>, vec<T> p1, vec<T>p2){
    vec<T> center = interpolate(p1, p2, 0.5);
    T radius = distance(center) * 2;
    return {center,{radius, radius}};
}


template <typename T> nvec<T> circ3pt(nvec<T>, vec<T> p1, vec<T>p2){
    vec<T> center = interpolate(p1, p2, 0.5);
    T radius = distance(center) * 2;
    return {center,{radius, radius}};
}




#endif //VECT_NVEC_H
