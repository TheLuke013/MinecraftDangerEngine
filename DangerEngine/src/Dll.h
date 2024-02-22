#ifndef DLL_H
#define DLL_H

#ifdef BUILD_DLL
	#define DANGER_API __declspec(dllexport)
#else
	#define DANGER_API __declspec(dllexport)
#endif

#endif
