#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>
#include <vector>

#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/prettywriter.h"

#ifdef _WIN32
	#ifdef DANGER_ENGINE_EXPORTS
		#define DANGER_API __declspec(dllexport)
	#else
		#define DANGER_API __declspec(dllimport)
	#endif
	#else
		#define DANGER_API
#endif

#endif
