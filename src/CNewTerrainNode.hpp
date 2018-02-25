#ifndef CNEWTERRAINNODE_HPP_INCLUDED
#define CNEWTERRAINNODE_HPP_INCLUDED

#include "Includes.hpp"
#include "CMeshNode.hpp"
#include "CWarehouser.hpp"

#include <memory>

class Tile {
public:
    Tile();
    ~Tile();

    std::shared_ptr<CMesh> getMesh() { return _mesh; }

private:
    std::shared_ptr<CMesh>  _mesh;
};


//! SC2 Terrain Node
class CNewTerrainNode : virtual public CMeshNode {
public:
    CNewTerrainNode(CNode* parent = 0, CWarehouser* warehouser = 0, vbcString name = "SC2 Terrain");
    ~CNewTerrainNode();

    void render(ERenderPass pass);

private:
    CWarehouser*    _warehouser;
};


#endif // CNEWTERRAINNODE_HPP_INCLUDED
