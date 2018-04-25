# C++ GMath library



##Intro 

```c++
vecf pts = vecf(0.0, 1.0);
pts^=90.0_deg;
cout << pts << endl;
nvec pts;
pts << pts;
nvec tri = polygon(3);
cout << tri << endl;
tri *= 0.3;
```



##Meshgrid implementation from numpy



```c++
auto grid = meshgrid(rangei(0, 127).decimate(8),rangei(0, 64).decimate(4));
```


```c++
typedef valarray<float>       nfloat;
nfloat xs = rangef(-1, 1).sampling(16);
int main() {
    auto sig = sigmoid<float>();
    transform(begin(xs), end(xs), begin(xs), sig);
    cout << xs << endl;
    return 0;
}
//{0.00247262 0.00407014 0.00669285 0.0109869 0.0179862 0.0293122 0.0474259 0.0758582 0.119203 0.182426 0.268941 0.377541 0.5 0.622459 0.731059 0.817575 0.880797 }

```

