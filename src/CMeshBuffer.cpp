#include "CMeshBuffer.hpp"

CMeshBuffer::CMeshBuffer()
{

}


CMeshBuffer::~CMeshBuffer()
{
	delete[] m_Vertices;

	glDeleteBuffers(1, &m_VertexBufferID);
}


void CMeshBuffer::createVBO()
{
	glGenBuffers(1, &m_VertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, m_QuantumOfVertices * sizeof(S3DVertex), m_Vertices, GL_STATIC_DRAW);
}


GLuint CMeshBuffer::getVertexBufferID()
{
	return m_VertexBufferID;
}


unsigned int CMeshBuffer::getQuantumOfVertices()
{

	return m_QuantumOfVertices;
}


S3DVertex* CMeshBuffer::getVertices()
{
	return m_Vertices;
}


SMaterial& CMeshBuffer::getMaterial()
{
	return m_Material;
}


void CMeshBuffer::setVertexData(S3DVertex* vertices, unsigned int quantumOfVertices /*, bool isValid */)
{
	m_Vertices = vertices;

	m_QuantumOfVertices = quantumOfVertices;
}



void CMeshBuffer::setMaterial(SMaterial& material)
{
	m_Material = material;
}

