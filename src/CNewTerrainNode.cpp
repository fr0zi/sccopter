#include "CNewTerrainNode.hpp"

Tile::Tile()
{
    std::shared_ptr<CMesh> _mesh(new CMesh);

    // Create new mesh buffer
	CMeshBuffer* mb = new CMeshBuffer;
}

Tile::~Tile()
{

}


CNewTerrainNode::CNewTerrainNode(CNode* parent, CWarehouser* warehouser, vbcString name)
: _warehouser(warehouser),
    CNode(parent, name)
{

}

CNewTerrainNode::~CNewTerrainNode()
{

}


void CNewTerrainNode::render(ERenderPass pass)
{

}
