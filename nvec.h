//
// Created by Nikola on 17/04/2018.
//

#ifndef VECT_NVEC_H
#define VECT_NVEC_H

// TODO make this more as container parts


#include <ostream>
#include "vec.h"

using namespace std;



template <typename T=float>
struct nvec{

    vector<vec<T>> pts;
    nvec() :pts() {}
    nvec(vector<vec<T>> v) : pts(v) {}
    size_t size(){ return pts.size();}

    vec<T> operator []  (size_t idx){return pts[idx];}
    nvec<T> operator+=(double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a += x; });return *this;}
    nvec<T> operator-=(double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a -= x; });return *this;}
    nvec<T> operator*=(double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a *= x; });return *this;}
    nvec<T> operator/=(double x)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a /= x; });return *this;}
    nvec<T> operator+=(vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a += b; });return *this;}
    nvec<T> operator-=(vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a -= b; });return *this;}
    nvec<T> operator*=(vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a *= b; });return *this;}
    nvec<T> operator/=(vec<T> b)    { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a /= b; });return *this;}
    nvec<T> operator ^= (double s)  { transform(begin(pts), end(pts), begin(pts), [&](vec<T> & a){ a ^= s; });return *this;}


    friend nvec<T> &operator<<(nvec<T> &lhs,  vec<T> &rhs)  { lhs.pts.push_back(rhs);return lhs; }
    friend nvec<T> &operator<<(nvec<T> &lhs,  nvec<T> &rhs) { lhs.pts.insert( end(rhs), begin(rhs), end(rhs) );return lhs;}
    friend ostream &operator<<(ostream &os, const nvec &nvec1) { os << "pts: " << nvec1.pts;return os; }


};
#endif //VECT_NVEC_H
