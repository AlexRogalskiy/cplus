class String
{
    public:
    String(const char* arg)
    {

    }
};
class Widget
{
    public:
    Widget(const int arg)
    {

    }
};

template <typename T>
struct Type2Type
{
    typedef T OriginalType;
};

template <class T, class U>
T* Create(const U& arg, Type2Type<T>)
{
    return new T(arg);
}
template <class U>
Widget* Create(const U& arg, Type2Type<Widget>)
{
    return new Widget(arg);
}
String* pStr = Create("", Type2Type<String>());
Widget* pW = Create(100, Type2Type<Widget>());
