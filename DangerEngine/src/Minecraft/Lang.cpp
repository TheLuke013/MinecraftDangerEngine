#include "Lang.h"

namespace Minecraft
{
	Lang::Lang()
		: languagesJson(new rapidjson::Document(rapidjson::kArrayType))
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
			languagesJson->PushBack(rapidjson::Value(languagesListString[static_cast<int>(language)].c_str(), languagesJson->GetAllocator()), languagesJson->GetAllocator());
		}

		return *DE::JSONUtils::GetJsonString(*languagesJson);
	}
}