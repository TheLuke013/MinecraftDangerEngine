#include "Lang.h"

namespace DE
{
	Lang::Lang()
		: languagesJson(rapidjson::kArrayType)
	{
	}

	void Lang::AddLanguage(Languages language)
	{
		languagesList.push_back(language);
	}

	std::string Lang::JsonParse()
	{
		for (const auto& language : languagesList)
		{
			languagesJson.PushBack(rapidjson::Value(languagesListString[static_cast<int>(language)].c_str(), languagesJson.GetAllocator()), languagesJson.GetAllocator());
		}

		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writter(buffer);
		languagesJson.Accept(writter);

		return buffer.GetString();
	}
}