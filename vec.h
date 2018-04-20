//
// Created by Nikola on 17/04/2018.
//

#ifndef VEC_VEC_H
#define VEC_VEC_H

#include <ostream>



#include <valarray>


template <typename T> using vec = typename  std::valarray < T >;


typedef vec<double>         vecd;
typedef vec<float>          vecf;
typedef vec<int>            veci;




template <typename T> std::ostream& operator<< (std::ostream& os, vec<T> ve) {
    os << "vector2d : {" << ve[0] << "," << ve[1] << "}";
    return os;
}




#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
typedef vec<byte>   vecb;
#endif



/* construct an ortho norm point from angle */
template <typename T> inline static vec<T> theta(T theta){ return std::valarray<T>{cos(theta),sin(theta)}; }



enum plan{xy, xz, yz};
/*acessort*/
template <typename T>  inline  T x(vec<T> v )                               { return v[0]; }
template <typename T>  inline  T y(vec<T> v )                               { return v[1]; }
template <typename T>  inline  T z(vec<T> v )                               { return v[2]; }

/*scalar out*/
template <typename T> inline double atan2(vec<T> v,plan plan = plan::xy)           {
    switch (plan){
        case plan::xy : return atan2(v[1], v[0]) ;
        case plan::xz : return atan2(v[2], v[0]) ;
        case plan::yz : return atan2(v[1], v[2]) ;
    }
}



template <typename T> inline double squared(vec<T> v)                       { return (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]); }
template <typename T> inline double distance(vec<T> v)                      { return sqrt(squared(v)); }
template <typename T> inline double distance(vec<T> a, vec<T> b)            { vec<T> c = a - b;return distance(c); }


template <typename T> inline double dot(vec<T> a, vec<T> b)                 { return a[0] * b[0]+a[1] * b[1];}
template <typename T> inline vec<T> cross(vec<T> a, vec<T> b)               { return {a[0] * b[1]-a[1] * b[0]}; }

//TODO check
template <typename T>  inline vec<T> normalize(vec<T> v, float dist=1.0)    { return  (dist / distance(v)) * v; }
template <typename T>  inline vec<T> neg(vec<T> v)                          { return {-v[0], -v[1]}; }
template <typename T>  inline vec<T> perp(vec<T> v)                         { return {-v[0], v[1]}; }
//if(b == NULL){ b = {0, 0}; }
template <typename T> inline vec<T> interpolate(vec<T> a, vec<T> b = nullptr, float f=0.0){ return {a[0] + (b[0] - a[0]) * f, a[1] + (b[1] - a[1]) * f}; }


//template <typename T>  inline vec<T> reflect(vec<T> self, vec<T> other)     { (other * (dot(self, other) * 2)) - self; }

// tupples of vec
//template <typename T> inline vec<T> bisect(vec<T> a, vec<T> b){ auto diff = a - b;auto sum = a + b;return {diff.x, diff.y, -diff.dot(sum) / 2};return {}; }

//template <typename T> inline double(vec<T> a, vec<T> b, bool norm=true){ return 0


template <typename T> vec<T> max(vec<T> a,vec<T> b ){ return {max(a[0], b[0]), max(a[1], b[1]), max(a[2], b[2])};}
template <typename T> vec<T> min(vec<T> a,vec<T> b ){ return {min(a[0], b[0]), min(a[1], b[1]), min(a[2], b[2])};}



template <typename T> inline vec<T> pol(vec<T> self){ return {atan2(self), distance(self)};}

template <typename T> inline vec<T> car(vec<T> v){ vec<T> a = v[0] *     cos(v[2]);       vec<T> xx = a *       cos(v[1]);      vec<T> yy = v[0] *    sin(v[2]);  vec<T> zz = a *       sin(v[1]);  return {xx, yy, zz}; }





template <typename T> inline vec<T> norm(vec<T> v){}
//template <typename T> inline vec<T> norm(vec<T> v){}




template <typename T>
vec<T> rot(T radian,vec<T> & a){
    T c, s = cos(radian), sin(radian);
    T tx = a[0] * c - a[1] * s;
    T ty = a[0] * s + a[1] * c;
    return {tx, ty};
}
















#endif //VEC_VEC_H
