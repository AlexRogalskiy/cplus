template <bool flag, typename T, typename U>
struct Select
{
    typedef T Result;
};

template <typename T, typename U>
struct Select<false, T, U>
{
    typedef U Result;
};

template <int v>
struct Int2Type
{
    enum { value = v };
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
    typedef typename Select<isPolymorphic, T*, T>::Result ValueType;
private:
    void DoSomething(T* pObj, Int2Type<true>)
    {
        T* pNewObj = pObj->Clone();
    }
    void DoSomething(T* pObj, Int2Type<false>)
    {
        T* pNewObj = new T(*pObj);
    }
public:
    void DoSomething(T* pObj)
    {
        DoSomething(pObj, Int2Type<isPolymorphic>());
    }
};
