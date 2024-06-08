#include "DangerEngine/UUID.h"

namespace DE
{
	UUID::UUID()
		: rd(new std::random_device()), gen(new std::mt19937_64((*rd)())), dis(new std::uniform_int_distribution(0, 15)),
        dis2(new std::uniform_int_distribution(8, 11))
	{
	}

    UUID::~UUID()
    {
        delete rd;
        delete gen;
        delete dis;
        delete dis2;
    }

	std::string UUID::GenerateUUIDV4()
	{
		std::stringstream ss;
		int i;

        ss << std::hex;
        for (i = 0; i < 8; i++)
        {
            ss << (*dis)(*gen);
        }

        ss << "-";
        for (i = 0; i < 4; i++)
        {
            ss << (*dis)(*gen);
        }

        ss << "-4";
        for (i = 0; i < 3; i++)
        {
            ss << (*dis)(*gen);
        }

        ss << "-";
        ss << (*dis2)(*gen);
        for (i = 0; i < 3; i++)
        {
            ss << (*dis)(*gen);
        }

        ss << "-";
        for (i = 0; i < 12; i++)
        {
            ss << (*dis)(*gen);
        }

		return ss.str();
	}
}