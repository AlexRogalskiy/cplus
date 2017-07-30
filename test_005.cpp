template<bool> struct CompileTimeError;
template<> struct CompileTimeError<true>{};

template<bool> struct CompileTimeChecker
{
    CompileTimeChecker();
};
template<> struct CompileTimeChecker<true>{};
#define STATIC_CHECK(expr, msg) { CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; };
//Loki::CompileTimeError<((expr) != 0)>

template <class To, class From>
To safe_reinterpret_cast(From from)
{
    STATIC_CHECK(sizeof(From) <= sizeof(To), Destination_Type_Too_Narrow);
    return reinterpret_cast<To>(from);
}
