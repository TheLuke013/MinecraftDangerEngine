#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>
#include <sstream>
#include <cstdlib>

#include "DangerEngine/Log.h"

namespace DE
{
	static void InitDE()
	{
		Log::Init();
	}
}

#endif
