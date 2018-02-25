#ifndef __CMESHBUFFER_HPP__
#define __CMESHBUFFER_HPP__

#include <vector>

#include "Includes.hpp"
#include "SMaterial.hpp"
#include "S3DVertex.hpp"


//! \brief MeshBuffer class
/*!
	  Mesh Buffer holds vertices with a single material.
*/
class CMeshBuffer
{

public:
	CMeshBuffer();

	virtual ~CMeshBuffer();

	void createVBO();

	GLuint getVertexBufferID();

	unsigned int getQuantumOfVertices();

	S3DVertex* getVertices();

	SMaterial& getMaterial();

	void setMaterial(SMaterial& material);

	void setVertexData(S3DVertex* vertices, unsigned int quantumOfVertices /*, bool isValid */);


private:
	S3DVertex*	    m_Vertices;

	SMaterial       m_Material;
	unsigned int    m_QuantumOfVertices;
	GLuint          m_VertexBufferID;
};

#endif // __CMESHBUFFER_HPP__
