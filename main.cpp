#include <iostream>
#include <vector>
#include "vec.h"
#include "nvec.h"
#include "range.h"


using namespace std;


template <class T>
class Helper {
private:
    T obj_;

public:
    explicit Helper<T>( T obj ) : obj_(obj) {}

public:
    T getObj() const { return obj_; }
    void setObj( T obj ) { obj_ = obj; }

    template<class U>
    inline friend std::ostream& operator<< ( std::ostream& out, const Helper<U>& rhs );
};




// TODO forward declarator
/*
template<typename T>
struct foo{
    using vec = typename  std::valarray < T >;
    using range = typename  std::valarray < T >;

};



template<class T> using vec = typename foo<T>::vec;
template<class T> using range = typename foo<T>::vec;
*/






using namespace range;

int main() {

    vecf a      { 0.0, 1.0 };

    //rect c(0,0, 100, 100);



    return 0;
}


/*
 *     vecf b { 1.0, 0.0 };


    //vecf c = theta<float>(90.0_deg); // -4.37114e-08 1

    float theta = anglebetween(a, b);

    distance(a);
    delta(a,b);

    rectf r;

    //vecf b = theta(0.3);

 */
float anglebetween(vecf valarray, vecf valarray1) {

    return 0;
}



