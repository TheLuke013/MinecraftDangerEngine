#include "DangerEngine/Minecraft/Lang.h"

namespace Minecraft
{
	Lang::Lang()
		: languagesJson(new rapidjson::Document(rapidjson::kArrayType)), languagesList(new std::vector<Languages>()),
		languagesListString(new std::vector<std::string>())
	{
		*languagesListString = {
		"id_ID",	//Indonesian	Indonesia
		"da_DK",	//Danish	Denmark
		"de_DE",	//German	Germany
		"en_GB",	//English	Great Britain
		"en_US",	//English	North America
		"es_ES",	//Spanish	Spain
		"es_MX",	//Mexican Spanish	Mexico
		"fr_CA",	//Canadian French	Canada
		"fr_FR",	//French	France
		"it_IT",	//Italian	Italy
		"hu_HU",	//Hungarian	Hungary
		"nl_NL",	//Dutch	Netherlands
		"nb_NO",	//Bokmål	Norway
		"pl_PL",	//Polish	Poland
		"pt_BR",	//Brazilian Portuguese	Brazil
		"pt_PT",	//Portuguese	Portugal
		"sk_SK",	//Slovak	Slovakia
		"fi_FI",	//Finnish	Finland
		"sv_SE",	//Swedish	Sweden
		"tr_TR",	//Turkish	Turkey
		"cs_CZ",	//Czech	Czech Republic
		"el_GR",	//Greek	Greece
		"bg_BG",	//Bulgarian	Bulgaria
		"ru_RU",	//Russian	Russia
		"uk_UA",	//Ukrainian	Ukraine
		"ja_JP",	//Japanese	Japan
		"zh_CN",	//Chinese(Simplified)	China
		"zh_TW",	//Chinese(Traditional)	Taiwan
		"ko_KR" };
	}

	Lang::~Lang()
	{
		delete languagesJson;
		delete languagesList;
		delete languagesListString;
	}

	void Lang::AddLanguage(Languages language)
	{
		languagesList->push_back(language);
	}

	std::string Lang::JsonParse()
	{
		for (const auto& language : *languagesList)
		{
			languagesJson->PushBack(rapidjson::Value(languagesListString->at(static_cast<int>(language)). c_str(), languagesJson->GetAllocator()), languagesJson->GetAllocator());
		}

		return *DE::JSONUtils::GetJsonString(*languagesJson);
	}
}