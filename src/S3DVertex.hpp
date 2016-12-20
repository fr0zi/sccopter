#ifndef __S3DVERTEX_HPP__
#define __S3DVERTEX_HPP__

//! 3DVertex structure
/*!
	Represents a point in 3D space.
*/
struct S3DVertex
{
	//! CONSTRUCTOR
	S3DVertex()
	{

	}

	//! DESTRUCTOR
	~S3DVertex()
	{

	}

	//! Point coordinates
	float coord[3];

	//! Point normal
	float normal[3];

	//! Point texture coordinates
	float texcoord[2];
};

#endif // __S3DVERTEX_HPP__
