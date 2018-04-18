//
// Created by Nikola on 17/04/2018.
//

#ifndef VEC_VEC_H
#define VEC_VEC_H

#include <valarray>
#include <ostream>


template <typename T> std::ostream& operator<< (std::ostream& out, const std::valarray<T>& ve) {  for (auto &&item : ve) { out << item << ' '; }return out;  }

template <typename T=float>
struct  vec {
    std::valarray<T> v;

    vec(std::valarray<T> valarray) : v(valarray) {}
    vec(const std::initializer_list<T> &__il) : v(__il) {}
    vec() : vec({0, 0}) {};
    vec(T x, T y) : vec({x, y}) {}
    vec(T x, T y, T z) : vec({x, y, z}) {}


    vec& operator=(vec &v) { v = v.v; return *this; }


    /*acessor*/
    size_t space()const { return v.size();}
    T  x() const{return v[0]; };
    T  y() const{return v[1]; };
    T  z() const{return v[2]; };



    /* scalar out */
    inline double angle()                        const {return atan2(v[1], v[0]);}
    inline double squared()                        const {return (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]); }
    inline double distance()                       const {return sqrt(squared()); }
    inline double distance(const vec &v)         const {vec d = (v - v.v); return sqrt(d.squared()); }


    inline vec interpolate(vec& that, double f){ return vec(v[0] + (that.v[0] - v[0]) * f, v[1] + (that.v[1] - v[1]) * f); }


    /* scalar in */
    inline vec operator+(double s) { return vec(v + s);        }
    inline vec operator-(double s) { return vec(v - s);        }
    inline vec operator*(double s) { return vec(v * s);        }
    inline vec operator/(double s) { return vec(v * s);        }

    /* vector in */
    inline vec operator+(vec& v) { return vec(v + v.v);    }
    inline vec operator-(vec &v) { return vec(v - v.v);    }
    inline vec operator*(vec& v) { return vec(v * v.v);    }
    inline vec operator/(vec& v) { return vec(v / v.v);    }


    
    
    vec operator ^ ( T radian) {
        T c, s = cos(radian), sin(radian);
        T tx = v[0] * c - v[1] * s;
        T ty = v[0] * s + v[1] * c;
        return vec(tx, ty);
    }

    inline vec& operator ^= ( T radian) { return *this ^ radian; }
    
    
    inline vec ortho()             { return vec(v[1], -v[0]); }
    inline vec mirror()            { return vec({-v[0], -v[1]}); }


    inline vec  truncate(double length) {
        double angle = this->angle();
        v[0] = length * cos(angle);
        v[1] = length * sin(angle);
        return  *this;
    }



    /*normalize*/
    inline vec operator!() {return *this * (1 /distance());    }
    /*dot product & ross product*/
    inline vec     operator%   (vec&  r) { return v[0]*r.v[0] + v[1]*r.v[1] +v[1]*r.v[1];}
    
    inline vec     operator^   (vec r) {   return vec(
            v[1]*r.v[2]-v[2]*r.v[1],
            v[2]*r.v[0]-v[0]*r.v[2],
            v[0]*r.v[1]-v[1]*r.v[0]);} //Cross-product

    /*polar*/
    inline vec polar(){ return vec(angle(), distance());}





    friend std::ostream &operator<<(std::ostream &os, const vec &vec1) { os << "v: " << vec1.v;return os; }



};

template <typename T=double>
static vec<T> theta(T theta){ return vec(cos(theta),sin(theta)); }



// Optional since 17++
typedef vec<float>  vecf;
typedef vec<int>    veci;



#endif //VEC_VEC_H
