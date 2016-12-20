#ifndef __CTEXTURERESOURCE_HPP__
#define __CTEXTURERESOURCE_HPP__

#include "Includes.hpp"
#include "CResource.hpp"
#include "TextureLoaders.hpp"

class CTextureResource : virtual public CResource
{
	public:
		CTextureResource(vbcString filename = "");

		virtual ~CTextureResource();

	protected:
		virtual void loadResource();
};

#endif // __CTEXTURERESOURCE_HPP__
