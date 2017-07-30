//template <class T, template <class> class CheckingPolicy, template <class> class ThreadingModel, template <class> class Storage = DefaultSmartPtrStorage> class SmartPtr : public CheckingPolicy<T>, public ThreadingModel<SmartPtr>, public Storage<T>
//{
//    T* operator->()
//    {
//        typename ThreadingModel<SmartPtr>::Lock guard(*this);
//        CheckingPolicy<T>::Check(pointee_);
//        return pointee_;
//    }
//    template <class T1, template <class> class CheckingPolicy1, template <class> class ThreadingModel1, template <class> class Storage1>
//      SmartPtr(const SmartPtr<T1, CheckingPolicy1, ThreadingModel1, Storage1>& other) : pointee_(other.pointee_), CheckingPolicy<T>(other), ThreadingModel1<SmartPtr>(other), Storage1<T>(other)
//      {
//
//      }
//    private:
//        T* pointee_;
//};
//typedef SmartPrt<Widget, NoChecking, SingleThreaded> WidgetPtr;
//
//template <class T>
//struct NoChecking
//{
//    static void Check(T*) {}
//};
//template <class T>
//struct EnforceNotNull
//{
//    class NullPointerException : public std::exception
//    {
//
//    };
//    static void Check(T* ptr)
//    {
//        if(!ptr) throw NullPointerException();
//    }
//};
//template <class T>
//struct EnsureNotNull
//{
//    static void Check(T*& ptr)
//    {
//        if(!ptr) ptr = GetDefaultValue();
//    }
//    private:
//        T* GetDefaultValue()
//        {
//            return;
//        }
//};

//template <class T>
//class DefautSmartPtrStorage
//{
//public:
//    typedef T* PointerType;
//    typedef T& ReferenceType;
//protected:
//    PointerType GetPointer()
//    {
//        return ptr_;
//    }
//    void SetPointer(PointerType ptr)
//    {
//        ptr_ = ptr;
//    }
//private:
//    PointerType ptr_;
//};

//typedef SmartPtr<Winget, RefCounted, NoChecked> WidgetPtr;
