#include "CMesh.hpp"

CMesh::CMesh()
{

}


CMesh::~CMesh()
{
	for (unsigned int i = 0; i < m_MeshBuffers.size(); i++)
	{
		if (m_MeshBuffers[i])
			delete m_MeshBuffers[i];
	}

	m_MeshBuffers.clear();
}


void CMesh::addMeshBuffer(CMeshBuffer* mb)
{
	m_MeshBuffers.push_back(mb);
}

void CMesh::setQuantumOfMeshBuffers(unsigned long quantum)
{
	m_MeshBuffers.reserve(quantum);
}

CMeshBuffer* CMesh::getMeshBuffer(unsigned int i)
{
	return m_MeshBuffers[i];
}

  
unsigned int CMesh::getQuantumOfMeshBuffers()
{
	return m_MeshBuffers.size();
}

