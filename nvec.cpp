//
// Created by Nikola on 20/04/2018.
//

#include "nvec.h"


template<typename T>
line<T> vertex(nvec<T> pts, size_t idx){
    size_t size = pts.size();
    size_t i = (size / 2) * idx;
    vec<T> a = pts[i];
    vec<T> b = pts[(i + 1) % size];
    return {a,b};
}





template <typename T>  T area(nvec<T> pts) {
    T result = 0;
    size_t num = pts.size();

    for (int i = 0; i < num; ++i) {
        vec<T> a = pts[i];
        vec<T> b = pts[(i + 1) % num];
        result += a[0] * b[1];
        result -= a[1] * b[0];

    }
    result *= 0.5;
    return result;
}



template <typename T>  T  perimeter(nvec<T> pts) {
    T result = 0;
    size_t num = pts.size();

    for (int i = 0; i < num; i+=2) {
        vec<T> a = pts[i];
        vec<T> b = pts[(i + 1) % num];
        result += distance(a,b);
    }
    return result;
}

template<typename T>  vec<T> centroid(nvec<T> pts){
    vec<T> result;

    size_t  num = pts.size();

    for (int i = 0; i < num; i+=2) {
        auto a = pts[i];
        auto b = pts[i + 1];
        //auto factor = a.x() * b.y() - b.x() * a.y();
//            result.pts[0] += (a.x() + b.x()) * factor;
//            result.pts[1] += (a.y() + b.y()) * factor;
    }

    return result * (1 / (area(pts) * 6));
}