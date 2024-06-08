#ifndef UUID_H
#define UUID_H

#include "DangerEngine/Core.h"

namespace DE
{
	class UUID
	{
	private:
		std::random_device* rd;
		std::mt19937_64* gen;
		std::uniform_int_distribution<>* dis;
		std::uniform_int_distribution<>* dis2;

	public:
		UUID();
		~UUID();

		std::string GenerateUUIDV4();

	};
}

#endif


