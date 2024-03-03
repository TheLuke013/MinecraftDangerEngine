#ifndef UUID_CLASS_H
#define UUID_CLASS_H

#include "Core.h"

#include <random>
#include <sstream>

namespace DE
{
	class DANGER_API UUID
	{
	private:
		std::random_device rd;
		std::mt19937_64 gen;
		std::uniform_int_distribution<> dis;
		std::uniform_int_distribution<> dis2;

	public:
		UUID();

		std::string GenerateUUIDV4();

	};
}

#endif


