#ifndef __CLOADER3DS_HPP__
#define __CLOADER3DS_HPP__

#include <lib3ds/file.h>
#include <lib3ds/material.h>
#include <lib3ds/mesh.h>

#include <cstring>

#include "Includes.hpp"
#include "CMesh.hpp"
#include "CWarehouser.hpp"

class CLoader3ds
{
	public:
		CLoader3ds(CWarehouser* warehouser);
		virtual ~CLoader3ds();

		CMesh* getMesh(vbcString filename, vbcString texPath);

	private:
		unsigned long getQuantumOfMaterials();

		SMaterial loadMaterialData(Lib3dsMaterial* material, vbcString texPath);

        S3DVertex* loadGeometryByMaterial(SMaterial& material, unsigned int& quantumOfVertices);

		CWarehouser* m_Warehouser;
		Lib3dsFile* m_File3ds;
};

#endif // __CLOADER3DS_HPP__
