#include <iostream>
#include <vector>

template <class T, class U>
class Conversion
{
    typedef char Small;
    class Big { char dummy[2]; };
    static Small Test(const U&);
    static Big Test(...);
    static T MakeT();
public:
    enum { exists = sizeof(Test(MakeT())) == sizeof(Small), sameType = false };
};

template <class T>
class Conversion<T, T>
{
public:
    enum{ exists = 1, sameType = 1 };
};


#define SUPERSUBCLASS(T, U) (Conversion<const U*, const T*>::exists && !Conversion<const T*, const void*>::sameType);
#define SUPERSUBCLASS_STRICT(T, U) (SUPERSUBCLASS((T, U) && !Conversion<const T*, const U*>::sameType);

int main()
{
    using namespace std;
    cout << Conversion<double, int>::exists << " "
         << Conversion<char, char*>::exists << " "
         << Conversion<size_t, vector<int> >::exists << " ";
    return 0;
}
