#ifndef __CTERRAINNODE_HPP__
#define __CTERRAINNODE_HPP__

#include "Includes.hpp"
#include "CMeshNode.hpp"
#include "CMesh.hpp"
#include "CWarehouser.hpp"

#include "CSC2MapLoader.hpp"




class CTerrainNode : virtual public CMeshNode
{
    public:
        CTerrainNode(CNode* parent = 0, CWarehouser* warehouser = 0, vbcString name = "SC2 Terrain", Tile* tiles = 0);
        virtual ~CTerrainNode();

        void render(ERenderPass pass);

    private:
        void generateTerrainMesh(Tile* tiles);

        //CMesh*  _Mesh;
        GLuint  _ShaderID;
        CWarehouser* _Warehouser;
};

#endif //__CTERRAINNODE_HPP__