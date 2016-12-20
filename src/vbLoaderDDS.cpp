#include "vbLoaderDDS.hpp"


vbLoaderDDS::vbLoaderDDS(vbcString filename)
: m_Filename(filename)
{
    loadBitmap();
}


vbLoaderDDS::~vbLoaderDDS()
{
    if (m_Buffer)
        free(m_Buffer);
}


int vbLoaderDDS::loadBitmap()
{
	#ifdef DEBUG_MODE
	printf("Reading image: %s\n", m_Filename.c_str());
	#endif

	unsigned char header[124];

	FILE *fp;

	/* try to open the file */
	fp = fopen(m_Filename.c_str(), "rb");
	if (fp == NULL)
		return 0;

	/* verify the type of file */
	char filecode[4];
	fread(filecode, 1, 4, fp);
	if (strncmp(filecode, "DDS ", 4) != 0) {
		fclose(fp);
		return 0;
	}

	/* get the surface desc */
	fread(&header, 124, 1, fp);

	m_Height        = *(unsigned int*)&(header[8 ]);
	m_Width         = *(unsigned int*)&(header[12]);
	m_LinearSize    = *(unsigned int*)&(header[16]);
	m_MipMapCount   = *(unsigned int*)&(header[24]);
	m_FourCC        = *(unsigned int*)&(header[80]);


	//unsigned char * buffer;
	unsigned int bufsize;
	/* how big is it going to be including all mipmaps? */
	bufsize = m_MipMapCount > 1 ? m_LinearSize * 2 : m_LinearSize;
	m_Buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
	fread(m_Buffer, 1, bufsize, fp);
	/* close the file pointer */
	fclose(fp);

	m_Components  = (m_FourCC == FOURCC_DXT1) ? 3 : 4;

	switch(m_FourCC)
	{
	case FOURCC_DXT1:
		m_Format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
		break;
	case FOURCC_DXT3:
		m_Format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
		break;
	case FOURCC_DXT5:
		m_Format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
		break;
	default:
		free(m_Buffer);
		return 0;
	}

    /*
	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	unsigned int blockSize = (m_Format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
	unsigned int offset = 0;

	// load the mipmaps
	for (unsigned int level = 0; level < m_MipMapCount && (m_Width || m_Height); ++level)
	{
		unsigned int size = ((m_Width+3)/4)*((m_Height+3)/4)*blockSize;
		glCompressedTexImage2D(GL_TEXTURE_2D, level, m_Format, m_Width, m_Height,
			0, size, m_Buffer + offset);

		offset += size;
		m_Width  /= 2;
		m_Height /= 2;
	}
	*/
}
