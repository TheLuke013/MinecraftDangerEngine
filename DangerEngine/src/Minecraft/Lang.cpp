#include "Lang.h"

namespace DE
{
	Lang::Lang()
	{

	}

	void Lang::AddLanguage(Languages language)
	{
		languagesList.push_back(language);
	}

	std::string Lang::JsonParse()
	{
		for (int i = 0; i < languagesList.size(); i++)
		{
			int index = static_cast<int>(languagesList[i]);
			languagesJson[i] = languagesListString[index];
		}

		return languagesJson.dump(DANGER_INDENT);
	}
}