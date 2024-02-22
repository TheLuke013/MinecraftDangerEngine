#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>
#include <vector>

#ifdef BUILD_DLL
	#define DANGER_API __declspec(dllexport)
#else
	#define DANGER_API __declspec(dllexport)
#endif

#endif
