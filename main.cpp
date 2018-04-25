#include <iostream>
#include <vector>
#include "range.h"
#include "nvec.h"
#include "container_stream.h"
#include "rect.h"

using namespace std;




vector<recti> a{
    {0, 0, 15, 63},
    {11, 0, 12, 43},
    {18, 0, 15, 63},
    {28, 0, 12, 43},
    {36, 0, 15, 63},
    {54, 0, 15, 63},
    {64, 0, 12, 43},
    {72, 0, 15, 63},
    {82, 0, 12, 43},
    {90, 0, 15, 63},
    {100, 0, 12, 43},
    {108, 0, 15, 63}};




int main() {



//    nvecd b = polygon(10);
//
//
//    //linei a{{0, 1, 1, 0}};
//
//    cout << midpoint({0, 1}, {1,0}) << endl;
//
//



    cout << printrect(a[0]) << endl;

    return 0;
}


