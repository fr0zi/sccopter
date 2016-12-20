#ifndef __CMESHNODE_HPP__
#define __CMESHNODE_HPP__

#include "Includes.hpp"
#include "CNode.hpp"
#include "CMesh.hpp"


typedef enum _ERenderPass {
	ERP_SOLID,
	ERP_TRANSPARENT,
} ERenderPass;

class CMeshNode : virtual public CNode
{
	public:
		CMeshNode(CNode* parent = 0, vbcString name = "VideoNode");

		virtual ~CMeshNode();

		void setMesh(CMesh* mesh);

		CMesh* getMesh();

		void setShaderID(GLuint id);

		GLuint getShaderID();

		virtual void render(ERenderPass pass);

	protected:
		CMesh*	m_Mesh;
		GLuint	m_ShaderID;
};

#endif // __CMESHNODE_HPP__
