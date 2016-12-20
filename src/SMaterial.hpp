#ifndef __SMATERIAL_HPP__
#define __SMATERIAL_HPP__

#include "Includes.hpp"

//! \brief Material structure
/*!
	Holds material data.
*/
struct SMaterial
{
	//! CONSTRUCTOR
	SMaterial()
	{
		name = "";
		textureName = "";
		transparency = 0.0f;
		textureId = 0;
		shininess = 0.0f;
	}

	//! COPY CONSTRUCTOR
	/*!
		\param m Material to be copied
	*/
	SMaterial(const SMaterial& m)
	{
		name = m.name;
		textureName = m.textureName;
		textureId = m.textureId;
		transparency = m.transparency;
		ambient[0] = m.ambient[0];
		ambient[1] = m.ambient[1];
		ambient[2] = m.ambient[2];
		ambient[3] = m.ambient[3];
		diffuse[0] = m.diffuse[0];
		diffuse[1] = m.diffuse[1];
		diffuse[2] = m.diffuse[2];
		diffuse[3] = m.diffuse[3];
		specular[0] = m.specular[0];
		specular[1] = m.specular[1];
		specular[2] = m.specular[2];
		specular[3] = m.specular[3];
		shininess = m.shininess;
		offset[0] = m.offset[0];
		offset[1] = m.offset[1];
		scale[0] = m.scale[0];
		scale[1] = m.scale[1];
	}

	//! Operator overload
	/*!
		\param m Material whose values is going to be copied
	*/
	SMaterial& operator = (const SMaterial& m)
	{
		name = m.name;
		textureName = m.textureName;
		textureId = m.textureId;
		transparency = m.transparency;
		ambient[0] = m.ambient[0];
		ambient[1] = m.ambient[1];
		ambient[2] = m.ambient[2];
		ambient[3] = m.ambient[3];
		diffuse[0] = m.diffuse[0];
		diffuse[1] = m.diffuse[1];
		diffuse[2] = m.diffuse[2];
		diffuse[3] = m.diffuse[3];
		specular[0] = m.specular[0];
		specular[1] = m.specular[1];
		specular[2] = m.specular[2];
		specular[3] = m.specular[3];
		shininess = m.shininess;
		offset[0] = m.offset[0];
		offset[1] = m.offset[1];
		scale[0] = m.scale[0];
		scale[1] = m.scale[1];

		return *this;
	}

	//! Material name
	std::string name;

	//! Texture name
	std::string textureName;

	//! Texture ID
	GLuint textureId;

	//! Ambient value
	GLfloat ambient[4];

	//! Diffuse value
	GLfloat diffuse[4];

	//! Specular value
	GLfloat specular[4];

	//! Shininess value
	GLfloat shininess;

	//! Texture offset
	GLfloat offset[2];

	//! Texture scale
	GLfloat scale[2];

	//! Material transparency
	GLfloat transparency;
};

#endif // _SMATERIAL_HPP__

