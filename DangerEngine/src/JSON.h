#ifndef JSON_CLASS_H
#define JSON_CLASS_H

#include "Core.h"

#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/prettywriter.h"

namespace DE
{
	class DANGER_API JSONUtils
	{
	public:
		static void AddStringMember(rapidjson::Value& member, const char* key, const std::string& value, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value v;
			v.SetString(value.c_str(), value.size(), allocator);
			member.AddMember(rapidjson::StringRef(key), v, allocator);
		}

		static void AddStringVectorMember(const char* key, const std::vector<std::string>& strVec, rapidjson::Value& parentValue, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value array(rapidjson::kArrayType);

			for (const auto& str : strVec)
			{
				rapidjson::Value value;
				value.SetString(str.c_str(), str.length(), allocator);
				array.PushBack(value, allocator);
			}

			rapidjson::GenericStringRef keyGenStr(key);
			parentValue.AddMember(keyGenStr, array, allocator);
		}

		static void AddUIntVectorMember(const char* key, const std::vector<unsigned int>& intVec, rapidjson::Value& parentValue, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value array(rapidjson::kArrayType);

			for (const auto& intValue : intVec)
			{
				rapidjson::Value value;
				value.SetInt(intValue);
				array.PushBack(value, allocator);
			}

			rapidjson::Value keyVal(key, allocator);
			parentValue.AddMember(keyVal, array, allocator);
		}

	};
}

#endif