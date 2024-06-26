#ifndef JSON_H
#define JSON_H

#include "DangerEngine/Core.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

namespace DE
{
	class JSONUtils
	{
	public:
		static void SaveJsonFile(const std::filesystem::path& path, const std::string& content)
		{
			std::ofstream fileToSave(path);
			if (fileToSave.is_open())
			{
				fileToSave << content;
				fileToSave.close();
			}
			else
			{
				LOG_ERROR("Error: Unable to save json file: ", path.string());
			}
		}

		static std::string* GetJsonString(rapidjson::Document& document)
		{
			rapidjson::StringBuffer buffer;
			rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
			document.Accept(writer);

			//return buffer.GetString();
			return new std::string(buffer.GetString());
		}

		static void AddStringMember(rapidjson::Value& member, const char* key, const std::string& value, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value v;
			v.SetString(value.c_str(), static_cast<rapidjson::SizeType>(value.size()), allocator);
			member.AddMember(rapidjson::StringRef(key), v, allocator);
		}

		static void AddStringVectorMember(const char* key, const std::vector<std::string>& strVec, rapidjson::Value& parentValue, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value array(rapidjson::kArrayType);

			for (const auto& str : strVec)
			{
				rapidjson::Value value;
				value.SetString(str.c_str(), static_cast<rapidjson::SizeType>(str.length()), allocator);
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

		static void AddFloatVectorMember(const char* key, const std::vector<float>& floatVec, rapidjson::Value& parentValue, rapidjson::Document::AllocatorType& allocator)
		{
			rapidjson::Value array(rapidjson::kArrayType);

			for (const auto& intValue : floatVec)
			{
				rapidjson::Value value;
				value.SetFloat(intValue);
				array.PushBack(value, allocator);
			}

			rapidjson::Value keyVal(key, allocator);
			parentValue.AddMember(keyVal, array, allocator);
		}

	};
}

#endif
