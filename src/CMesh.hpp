#ifndef __CMESH_HPP__
#define __CMESH_HPP__

#include <vector>
#include <cassert>

#include <lib3ds/file.h>
#include <lib3ds/material.h>

#include "CRefCounter.hpp"
#include "CMeshBuffer.hpp"


typedef std::vector<CMeshBuffer*> MeshBufferList;


class CMesh : virtual public CRefCounter
{
	public:

		CMesh();

		virtual ~CMesh();

		void addMeshBuffer(CMeshBuffer* mb);

		CMeshBuffer* getMeshBuffer(unsigned int i);

		void setQuantumOfMeshBuffers(unsigned long quantum);

		unsigned int getQuantumOfMeshBuffers();


	private:
		MeshBufferList m_MeshBuffers;
};

#endif // __CMESH_HPP__
