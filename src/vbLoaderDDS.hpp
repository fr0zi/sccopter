#ifndef VBLOADERDDS_HPP_INCLUDED
#define VBLOADERDDS_HPP_INCLUDED

#include "Includes.hpp"
#include <cstring>

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

class vbLoaderDDS
{
    public:
        vbLoaderDDS(vbcString filename);
        ~vbLoaderDDS();

    protected:
        unsigned char*  m_Buffer;
        unsigned int    m_Height;
        unsigned int    m_Width;
        unsigned int    m_LinearSize;
        unsigned int    m_MipMapCount;
        unsigned int    m_FourCC;
        unsigned int    m_Format;
        unsigned int    m_Components;
        vbcString       m_Filename;


        int loadBitmap();

};

#endif // VBLOADERDDS_HPP_INCLUDED
