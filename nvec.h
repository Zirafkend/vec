//
// Created by Nikola on 17/04/2018.
//

#ifndef VECT_NVEC_H
#define VECT_NVEC_H


#include <vector>
#include "vec.h"
#include "range.h"
#include "container_stream.h"

using namespace std;


template <typename T> using nvec = typename std::vector<  std::valarray < T >>;


typedef nvec<double>    nvecd;
typedef nvec<float>     nvecf;
typedef nvec<int>       nveci;




//template <typename T> nvec<T> operator+=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a += x; });     return pts;}
//template <typename T> nvec<T> operator-=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a -= x; });     return pts;}
//template <typename T> nvec<T> operator*=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a *= x; });     return pts;}
//template <typename T> nvec<T> operator/=(nvec<T> pts , double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a /= x; });     return pts;}
//
//template <typename T> nvec<T> operator+=(nvec<T> pts , vec<T> b)    { std::transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a += b; });     return pts;}
//template <typename T> nvec<T> operator-=(nvec<T> pts , vec<T> b)    { std::transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a -= b; });     return pts;}
//template <typename T> nvec<T> operator*=(nvec<T> pts , vec<T> b)    { std::transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a *= b; });     return pts;}
//template <typename T> nvec<T> operator/=(nvec<T> pts , vec<T> b)    { std::transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { a /= b; });     return pts;}
//


//template <typename T> nvec<T> rot(nvec<T> pts, double rad){ transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a)  { rot(rad, a) });     return pts;}







template <typename T>   T       area(nvec<T> pts);
template <typename T>   T       perimeter(nvec<T> pts);
template<typename T>    vec<T>  centroid(nvec<T> pts);




//      poly 2






template <typename T> using line = typename std::vector < std::valarray < T >>;     // 2
typedef line<double> lined;
typedef line<float>  linef;
typedef line<int>    linei;
//typedef line<byte>   lineb;

template<typename T> line<T> vertex(nvec<T> pts, size_t idx);


template<typename T> nvec<T> pointfromline(line<T> l,size_t npoint ){
    nvec<T> result;
    vec<T> a = l[0];
    vec<T> b = l[1];
    //auto xs = range::decimate(range::norm(npoint), npoint);
    //for(T x : xs){ result.push_back(interpolate(a, b, x)); }

    return result;

}




template<typename T>  nvec<T> &operator<<(nvec<T> &pl, const line<T> l) {
    pl.push_back(l[0]);
    pl.push_back(l[1]);
    return pl;
}


// line methods
template <typename T=float> vec<T> midpoint(vec<T> a, vec<T> b)   { return (a + b) / 2; }


template <typename T> double heading(vec<T> a, vec<T> b)    { return atan2(a - b);}


// class method
template <typename T> static inline nvec<T> centerline(T distance, T rad){
    vec<T> a = theta(rad) * distance / 2.0;
    a ^=(M_PI);
    vec<T> b = a;
    return {a, b};
}





template <typename T=double>  nvec<T> polygon(size_t num) {
    nvec<T> result;
    std::valarray<T> xs = linspace(0.0, 2*M_PI, num);
    for(auto th : xs){ result.push_back(theta<T>(th)); }

    return result;
}




template <typename T> using tri = typename std::vector < std::valarray < T >>;         // 3



template <typename T> inline tri<T> create_equilateral(vec<T> a, vec<T> b,  float top_point=0.5){}

// cout

template <typename T> inline bool contains (vec<T> a , tri<T> tri );


template <typename T> inline vec<T> center(tri<T> tri)                      { return (tri[0] + tri[1] + tri[2]) / 2; }

//template <typename T> inline double area(tri<T> tri){ return cross((tri[1] - tri[0]), (tri[2] - tri[0])) * 0.5; }



//      poly 4


//template <typename T> using rect = typename std::valarray < T >;         // 4



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
