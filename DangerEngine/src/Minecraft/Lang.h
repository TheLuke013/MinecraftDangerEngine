#ifndef LANG_H
#define LANG_H

#include "Core.h"
#include "../nlohmann/json.hpp"

namespace DE
{
	enum class Languages
	{
		id_ID,	//Indonesian	Indonesia
		da_DK,	//Danish	Denmark
		de_DE,	//German	Germany
		en_GB,	//English	Great Britain
		en_US,	//English	North America
		es_ES,	//Spanish	Spain
		es_MX,	//Mexican Spanish	Mexico
		fr_CA,	//Canadian French	Canada
		fr_FR,	//French	France
		it_IT,	//Italian	Italy
		hu_HU,	//Hungarian	Hungary
		nl_NL,	//Dutch	Netherlands
		nb_NO,	//Bokmål	Norway
		pl_PL,	//Polish	Poland
		pt_BR,	//Brazilian Portuguese	Brazil
		pt_PT,	//Portuguese	Portugal
		sk_SK,	//Slovak	Slovakia
		fi_FI,	//Finnish	Finland
		sv_SE,	//Swedish	Sweden
		tr_TR,	//Turkish	Turkey
		cs_CZ,	//Czech	Czech Republic
		el_GR,	//Greek	Greece
		bg_BG,	//Bulgarian	Bulgaria
		ru_RU,	//Russian	Russia
		uk_UA,	//Ukrainian	Ukraine
		ja_JP,	//Japanese	Japan
		zh_CN,	//Chinese(Simplified)	China
		zh_TW,	//Chinese(Traditional)	Taiwan
		ko_KR	//Korean	Korea
	};

	class DANGER_API Lang
	{
	public:
		Lang();

		void AddLanguage(Languages language);
		std::string JsonParse();

	private:
		nlohmann::ordered_json languagesJson;

		std::vector<Languages> languagesList;

		std::vector<std::string> languagesListString = {
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

	};
}

#endif
