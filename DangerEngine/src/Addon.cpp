#include "Addon.h"

namespace DE
{
	Addon::Addon(unsigned int formatVersion, const std::string& name, const std::string& description,
		std::vector<unsigned int> version, const std::string& author, const std::string& license, const std::string& url)
		: rp(new ResourcePack(formatVersion, name, description, version)), bp(new BehaviourPack(formatVersion, name, description, version))
	{
		bp->GetManifest()->AddMetadataAuthor(author);
		bp->GetManifest()->SetMetadataLicense(license);
		bp->GetManifest()->SetMetadataUrl(url);
	}
}
