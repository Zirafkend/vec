#include <iostream>
#include <vector>
#include "vec.h"


using namespace std;

inline static long double deg_to_rad(long double deg) { return deg * M_PI / 180; }
inline static long double rad_to_deg(long double rad) { return (rad / M_PI) * 180; }

long double operator"" _deg ( long double deg ) { return deg_to_rad(deg); }
long double operator"" _rad ( long double rad ) { return rad_to_deg(rad); }


#include "nvec.h"


template <typename T>
nvec<T> centerangle(T distance, T rad){
    vec<T> a = theta(rad) * distance / 2.0;
    vec<T> b = a;
    b ^= (M_PI);
    return nvec<T>({a,b});
}



int main() {


    vec a(3,4);
    vec b(2.3,8.3);

    //auto line = centerangle(1.3, 0.3);
    //cout << line << endl;

    //nvec pts{0, 1, 0.2, 0.4, 0.8, 0.8};



    return 0;
}
/*

template <typename T>
struct line : nvec<T>{

    line(){};
    line(const vec<T> &a, const vec<T> &b){
        pts[0] = a;
        pts[1] = b;
    }

    vec<T> midpoint(){ return (pts[0] + pts[1]) / 2; }
    double heading(){ return (pts[0] - pts[1]).angle();}
};






vec c = a + b;

cout << c << endl;

c^= 90.0deg;
*/