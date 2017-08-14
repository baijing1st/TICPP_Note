#ifdef ZTHREAD_DLL_EXPORTS
#define ZTHREAD_DLL_API __declspec(dllexport)
#else
#define ZTHREAD_DLL_API __declspec(dllimport)
#endif