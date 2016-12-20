#include "CTextureResource.hpp"

#include <SOIL.h>

CTextureResource::CTextureResource(vbcString filename)
: CResource(filename)
{
	#ifdef DEBUG_MODE
	printf("Creating texture resource: %s\n", m_Filename.c_str());
	#endif

	loadResource();
}


CTextureResource::~CTextureResource()
{
	#ifdef DEBUG_MODE
	printf("Destroying texture resource: %s\n", m_Filename.c_str());
	#endif

	glDeleteTextures(1, &m_ID);
}


void CTextureResource::loadResource()
{
    /*
	unsigned dotPos = m_Filename.rfind(".");

	vbcString fileExtension = m_Filename.substr(dotPos+1);

	if ( fileExtension == "bmp" )
	{
		#ifdef DEBUG_MODE
		printf("Texture format is BMP\n");
		#endif

		m_ID = loadTextureBMP(m_Filename);

		return;
	}
	else if ( fileExtension == "tga" )
	{
		#ifdef DEBUG_MODE
		printf("Texture format is TGA\n");
		#endif

		m_ID = loadTextureTGA(m_Filename);

		return;
	}
	else if ( fileExtension == "dds" )
	{
		#ifdef DEBUG_MODE
		printf("Texture format is DDS\n");
		#endif

		m_ID = loadTextureDDS(m_Filename);

		return;
	}
	*/

    m_ID = SOIL_load_OGL_texture
	(
		m_Filename.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

if( 0 == m_ID )
{
	printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
}


	//m_ID = 0;
}

