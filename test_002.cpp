#include <cstdlib>

template <class T>
struct OpNewCreator
{
    static T* Create()
    {
        return new T;
    }
    template <class U>
    static T* Create(const U& arg)
    {
        return new T(arg);
    }
    protected:
        ~OpNewCreator() {}
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
    protected:
        ~MallocCreator() {}
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
    protected:
        ~PrototypeCreator()
        {
            delete pPrototype_;
            //pPrototype_ = nullptr;
        }
    private:
        T* pPrototype_;
};
//template<class Window, class Controller>
class Widget
{

};
//template<class Window>
//class Widget2<Window, MyController>
//{
//
//};
//template<class ButtonArg>
//class Widget<Button<ButtonArg>, MyController>
//{
//
//};
class Gadget
{

};
template <template <class> class CreationPolicy = OpNewCreator>
class WidgetManager : public CreationPolicy<Widget>
{
    private:
        void doSomething()
        {
            Gadget* pw = CreationPolicy<Gadget>().Create();
            //CreationPolicy<Widget>().Create(100);
        }

};
typedef WidgetManager<OpNewCreator> CustomWidgetMgr;
/*struct OpNewCreator
{
    template <class T>
    static T* Create()
    {
        return new T;
    }
};*/
