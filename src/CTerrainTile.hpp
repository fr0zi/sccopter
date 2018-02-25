#ifndef CTERRAINTILE_HPP_INCLUDED
#define CTERRAINTILE_HPP_INCLUDED

#include "CSC2MapLoader.hpp"
#include "S3DVertex.hpp"

enum TextureType {
    Ground,
    Water,
    SubmergedNW,
    SubmergedNE,
    SubmergedSW,
    SubmergedSE
};


class CTerrainTile
{
    public:
        CTerrainTile(unsigned char x, unsigned char y, int height, TileType type);
        ~CTerrainTile();

        char getVertexCount() { return _vertexCount; }

        S3DVertex* getVertices() { return _vertices; }

    protected:
        S3DVertex*  _vertices;
        char        _vertexCount;
        TileType    _type;
        int         _height;
        unsigned char _x, _y;

        void generateMesh();
        void setTexture();
};


#endif // CTERRAINTILE_HPP_INCLUDED
