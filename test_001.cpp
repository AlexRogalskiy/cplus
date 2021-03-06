#include <cstdlib>

template <class T>
struct OpNewCreator
{
    static T* Create()
    {
        return new T;
    }
};

template <class T>
struct MallocCreator
{
    static T* Create()
    {
        void* buf = std::malloc(sizeof(T));
        if(!buf) return 0;
        return new(buf) T;
    }
};

template <class T>
struct PrototypeCreator
{
    PrototypeCreator(T* pObj = 0) : pPrototype_(pObj)
    {

    }

    T* Create()
    {
        return pPrototype_ ? pPrototype_->Clone() : 0;
    }

    T* GetPrototype()
    {
        return pPrototype_;
    }

    void SetPrototype(T* pObj)
    {
        pPrototype_ = pObj;
    }
    private:
        T* pPrototype_;
};
//template<class Window, class Controller>
class Widget
{

};
template <class CreationPolicy>
class WidgetManager : public CreationPolicy
{

};
typedef WidgetManager <OpNewCreator<Widget> > CustomWidgetMgr;
