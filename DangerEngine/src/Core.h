#ifndef CORE_H
#define CORE_H

//STD
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>
#include <sstream>
#include <cstdlib>

//DE
#include "Log.h"

namespace DE
{
	static void InitDE()
	{
		Log::Init();
	}
}

#endif
