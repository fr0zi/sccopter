#ifndef __TEXTURELOADERS_HPP__
#define __TEXTURELOADERS_HPP__

#include "Includes.hpp"
#include <cstring>

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint loadTextureDDS(vbcString filename);

GLuint loadTextureBMP(vbcString filename);

GLuint loadTextureTGA(vbcString filename);

#endif // __TEXTURELOADERS_HPP__
