#include "CTerrainTile.hpp"

CTerrainTile::CTerrainTile(unsigned char x, unsigned char y, int height, TileType type)
: _x(x), _y(y), _height(height), _type(type), _vertexCount(0)
{
    generateMesh();
}


CTerrainTile::~CTerrainTile()
{
    if (_vertices)
    {
        delete [] _vertices;
        _vertices = 0;
    }
}


    /*

   0,0-----1,0
    |     / |
    |    /  |
    |   /   |
    |  /    |
    | /     |
   0,1-----1,1
    */



void CTerrainTile::generateMesh()
{
    const float tileSize = 10.0f;
    const float heightScale = 0.09f;

    if (_type == ETT_FLAT) // CAŁY
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = _height * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = _height * heightScale;
        _vertices[1].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].coord[0] = _x * tileSize;
        _vertices[2].coord[1] = _height * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = _x * tileSize;
        _vertices[3].coord[1] = _height * heightScale;
        _vertices[3].coord[2] = -_y * tileSize;
        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].coord[0] = (_x * tileSize) + tileSize;
        _vertices[4].coord[1] = _height * heightScale;
        _vertices[4].coord[2] = -_y * tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = (_x * tileSize) + tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_N) // CAŁY
    {
        //printf("Tile: %d, %d, %d\n", _x, _y, _height);

        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = (_height + 100) * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = _height * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = _x * tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = -_y * tileSize;
        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].coord[0] = (_x * tileSize) + tileSize;
        _vertices[4].coord[1] = _height * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0.5f;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = (_height + 100) * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0;

        _vertices[7].coord[0] = _x * tileSize;
        _vertices[7].coord[1] = _height * heightScale;
        _vertices[7].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].coord[0] = _x * tileSize;
        _vertices[8].coord[1] = _height * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        // side triangle 2
        _vertices[9].coord[0] = (_x * tileSize) + tileSize;
        _vertices[9].coord[1] = (_height + 100) * heightScale;
        _vertices[9].coord[2] = -_y * tileSize;
        _vertices[9].texcoord[0] = 0;
        _vertices[9].texcoord[1] = 0;

        _vertices[10].coord[0] = (_x * tileSize) + tileSize;
        _vertices[10].coord[1] = _height * heightScale;
        _vertices[10].coord[2] = -_y * tileSize;
        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].coord[0] = (_x * tileSize) + tileSize;
        _vertices[11].coord[1] = _height * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0.5f;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = (_height + 100) * heightScale;
        _vertices[12].coord[2] = -_y * tileSize;
        _vertices[12].texcoord[0] = 0;
        _vertices[12].texcoord[1] = 0;

        _vertices[13].coord[0] = _x * tileSize;
        _vertices[13].coord[1] = _height * heightScale;
        _vertices[13].coord[2] = -_y * tileSize;
        _vertices[13].texcoord[0] = 0;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = _height * heightScale;
        _vertices[14].coord[2] = -_y * tileSize;
        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0.5f;

        // front triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = _height * heightScale;
        _vertices[15].coord[2] = -_y * tileSize;
        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0.5f;

        _vertices[16].coord[0] = (_x * tileSize) + tileSize;
        _vertices[16].coord[1] = (_height + 100) * heightScale;
        _vertices[16].coord[2] = -_y * tileSize;
        _vertices[16].texcoord[0] = 0.5f;
        _vertices[16].texcoord[1] = 0;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = (_height + 100) * heightScale;
        _vertices[17].coord[2] = -_y * tileSize;
        _vertices[17].texcoord[0] = 0;
        _vertices[17].texcoord[1] = 0;
    }
    else
    if (_type == ETT_SLOPE_E) // CAŁY
    {
        //printf("Tile: %d, %d, %d\n", _x, _y, _height);

        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = _height * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = _height * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = (_x * tileSize) + tileSize;
        _vertices[3].coord[1] = _height * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = _x * tileSize;
        _vertices[4].coord[1] = (_height + 100) * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = (_height + 100) * heightScale;
        _vertices[5].coord[2] = -_y * tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = (_height + 100) * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0;

        _vertices[7].coord[0] = _x * tileSize;
        _vertices[7].coord[1] = _height * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].coord[0] = _x * tileSize + tileSize;
        _vertices[8].coord[1] = _height * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        // side triangle 1
        _vertices[9].coord[0] = _x * tileSize;
        _vertices[9].coord[1] = (_height + 100) * heightScale;
        _vertices[9].coord[2] = -_y * tileSize - tileSize;
        _vertices[9].texcoord[0] = 0;
        _vertices[9].texcoord[1] = 0;

        _vertices[10].coord[0] = _x * tileSize + tileSize;
        _vertices[10].coord[1] = _height * heightScale;
        _vertices[10].coord[2] = -_y * tileSize - tileSize;
        _vertices[10].texcoord[0] = 0.5f;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].coord[0] = _x * tileSize;
        _vertices[11].coord[1] = _height * heightScale;
        _vertices[11].coord[2] = -_y * tileSize - tileSize;
        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = (_height + 100) * heightScale;
        _vertices[12].coord[2] = -_y * tileSize;
        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0;

        _vertices[13].coord[0] = _x * tileSize;
        _vertices[13].coord[1] = (_height + 100) * heightScale;
        _vertices[13].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[13].texcoord[0] = 0;
        _vertices[13].texcoord[1] = 0;

        _vertices[14].coord[0] = _x * tileSize;
        _vertices[14].coord[1] = _height * heightScale;
        _vertices[14].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[14].texcoord[0] = 0;
        _vertices[14].texcoord[1] = 0.5f;

        // front triangle 2
        _vertices[15].coord[0] = _x * tileSize;
        _vertices[15].coord[1] = _height * heightScale;
        _vertices[15].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[15].texcoord[0] = 0;
        _vertices[15].texcoord[1] = 0.5f;

        _vertices[16].coord[0] = _x * tileSize;
        _vertices[16].coord[1] = _height * heightScale;
        _vertices[16].coord[2] = -_y * tileSize;
        _vertices[16].texcoord[0] = 0.5f;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = (_height + 100) * heightScale;
        _vertices[17].coord[2] = -_y * tileSize;
        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0;
    }
    else
    if (_type == ETT_SLOPE_S)  // CAŁY
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = _height * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = _height * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = (_x * tileSize) + tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = _x * tileSize;
        _vertices[4].coord[1] = (_height + 100) * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = -_y * tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;


        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = _x * tileSize;
        _vertices[7].coord[1] = (_height + 100) * heightScale;
        _vertices[7].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0;

        _vertices[8].coord[0] = _x * tileSize;
        _vertices[8].coord[1] = _height * heightScale;
        _vertices[8].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[8].texcoord[0] = 0;
        _vertices[8].texcoord[1] = 0.5f;

        // side triangle 2
        _vertices[9].coord[0] = (_x * tileSize) + tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = -_y * tileSize;
        _vertices[9].texcoord[0] = 0;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = (_x * tileSize) + tileSize;
        _vertices[10].coord[1] = _height * heightScale;
        _vertices[10].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[10].texcoord[0] = 0.5f;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].coord[0] = (_x * tileSize) + tileSize;
        _vertices[11].coord[1] = (_height + 100) * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = _x * tileSize;
        _vertices[13].coord[1] = (_height + 100) * heightScale;
        _vertices[13].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[14].texcoord[0] = 0;
        _vertices[14].texcoord[1] = 0;

        // front triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[15].texcoord[0] = 0;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = (_x * tileSize) + tileSize;
        _vertices[16].coord[1] = _height * heightScale;
        _vertices[16].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_W)
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = _height * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = (_height + 100) * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = (_x * tileSize) + tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = _x * tileSize;
        _vertices[4].coord[1] = _height * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = -_y * tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = (_x * tileSize) + tileSize;
        _vertices[7].coord[1] = _height  * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0.5f;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].coord[0] = (_x * tileSize) + tileSize;
        _vertices[8].coord[1] = (_height + 100) * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0;

        // side triangle 1
        _vertices[9].coord[0] = _x * tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = _x * tileSize + tileSize;
        _vertices[10].coord[1] = (_height + 100) * heightScale;
        _vertices[10].coord[2] = -_y * tileSize - tileSize;
        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].coord[0] = (_x * tileSize) + tileSize;
        _vertices[11].coord[1] = _height * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        // front triangle 1
        _vertices[12].coord[0] = (_x * tileSize) + tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = -_y * tileSize;
        _vertices[12].texcoord[0] = 0;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = (_x * tileSize) + tileSize;
        _vertices[13].coord[1] = _height * heightScale;
        _vertices[13].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0;

        // front triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = (_x * tileSize) + tileSize;
        _vertices[16].coord[1] = (_height + 100) * heightScale;
        _vertices[16].coord[2] = -_y * tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0;

        _vertices[17].coord[0] = (_x * tileSize) + tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = -_y * tileSize;
        _vertices[17].texcoord[0] = 0;
        _vertices[17].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_NE)
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = (_height + 100) * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = _x * tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = _x * tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = (_x * tileSize) + tileSize;
        _vertices[4].coord[1] = (_height + 100) * heightScale;
        _vertices[4].coord[2] = -_y * tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = (_x * tileSize) + tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;

        // side triangle 1
        _vertices[6].coord[0] = (_x * tileSize) + tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = (_x * tileSize) + tileSize;
        _vertices[7].coord[1] = (_height + 100) * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0;

        _vertices[8].coord[0] = (_x * tileSize) + tileSize;
        _vertices[8].coord[1] = _height * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0;
        _vertices[8].texcoord[1] = 0.5f;

        // side triangle 2
        _vertices[9].coord[0] = (_x * tileSize) + tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[9].texcoord[0] = 0;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = _x * tileSize;
        _vertices[10].coord[1] = _height * heightScale;
        _vertices[10].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[10].texcoord[0] = 0.5f;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].coord[0] = _x * tileSize;
        _vertices[11].coord[1] = (_height + 100) * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = -_y * tileSize;
        _vertices[12].texcoord[0] = 0;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = (_x * tileSize) + tileSize;
        _vertices[13].coord[1] = _height * heightScale;
        _vertices[13].coord[2] = -_y * tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = -_y * tileSize;
        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0;

        // front triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = -_y * tileSize;
        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = _x * tileSize;
        _vertices[16].coord[1] = (_height + 100) * heightScale;
        _vertices[16].coord[2] = -_y * tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = -_y * tileSize;
        _vertices[17].texcoord[0] = 0;
        _vertices[17].texcoord[1] = 0.5f;

        // front triangle 3
        _vertices[18].coord[0] = _x * tileSize;
        _vertices[18].coord[1] = _height * heightScale;
        _vertices[18].coord[2] = -_y * tileSize;
        _vertices[18].texcoord[0] = 0.5f;
        _vertices[18].texcoord[1] = 0.5f;

        _vertices[19].coord[0] = _x * tileSize;
        _vertices[19].coord[1] = (_height + 100) * heightScale;
        _vertices[19].coord[2] = -_y * tileSize;
        _vertices[19].texcoord[0] = 0.5f;
        _vertices[19].texcoord[1] = 0;

        _vertices[20].coord[0] = _x * tileSize;
        _vertices[20].coord[1] = (_height + 100) * heightScale;
        _vertices[20].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[20].texcoord[0] = 0;
        _vertices[20].texcoord[1] = 0;

        // front triangle 4
        _vertices[21].coord[0] = _x * tileSize;
        _vertices[21].coord[1] = (_height + 100) * heightScale;
        _vertices[21].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[21].texcoord[0] = 0;
        _vertices[21].texcoord[1] = 0;

        _vertices[22].coord[0] = _x * tileSize;
        _vertices[22].coord[1] = _height * heightScale;
        _vertices[22].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[22].texcoord[0] = 0;
        _vertices[22].texcoord[1] = 0.5f;

        _vertices[23].coord[0] = _x * tileSize;
        _vertices[23].coord[1] = _height * heightScale;
        _vertices[23].coord[2] = -_y * tileSize;
        _vertices[23].texcoord[0] = 0.5f;
        _vertices[23].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_SE)
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = _height * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = (_x * tileSize) + tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = _x * tileSize;
        _vertices[4].coord[1] = (_height + 100) * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = (_height + 100) * heightScale;
        _vertices[5].coord[2] = -_y * tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = (_x * tileSize) + tileSize;
        _vertices[7].coord[1] = _height * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0.5f;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].coord[0] = _x * tileSize;
        _vertices[8].coord[1] = (_height + 100) * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0;
        _vertices[8].texcoord[1] = 0;

        // side triangle 2
        _vertices[9].coord[0] = (_x * tileSize) + tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = -_y * tileSize;
        _vertices[9].texcoord[0] = 0;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = (_x * tileSize) + tileSize;
        _vertices[10].coord[1] = _height * heightScale;
        _vertices[10].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[10].texcoord[0] = 0.5f;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].coord[0] = (_x * tileSize) + tileSize;
        _vertices[11].coord[1] = (_height + 100) * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[12].texcoord[0] = 0;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = _x * tileSize;
        _vertices[13].coord[1] = _height * heightScale;
        _vertices[13].coord[2] = -_y * tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].coord[0] = _x * tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = -_y * tileSize;
        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0;

        // front triangle 2
        _vertices[15].coord[0] = _x * tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = -_y * tileSize;
        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = _x * tileSize;
        _vertices[16].coord[1] = (_height + 100) * heightScale;
        _vertices[16].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[17].texcoord[0] = 0;
        _vertices[17].texcoord[1] = 0.5f;

        // front triangle 3
        _vertices[18].coord[0] = _x * tileSize;
        _vertices[18].coord[1] = _height * heightScale;
        _vertices[18].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[18].texcoord[0] = 0.5f;
        _vertices[18].texcoord[1] = 0.5f;

        _vertices[19].coord[0] = _x * tileSize;
        _vertices[19].coord[1] = (_height + 100) *  heightScale;
        _vertices[19].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[19].texcoord[0] = 0.5f;
        _vertices[19].texcoord[1] = 0;

        _vertices[20].coord[0] = (_x * tileSize) + tileSize;
        _vertices[20].coord[1] = (_height + 100) * heightScale;
        _vertices[20].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[20].texcoord[0] = 0;
        _vertices[20].texcoord[1] = 0;

        // front triangle 4
        _vertices[21].coord[0] = (_x * tileSize) + tileSize;
        _vertices[21].coord[1] = (_height + 100) * heightScale;
        _vertices[21].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[21].texcoord[0] = 0;
        _vertices[21].texcoord[1] = 0;

        _vertices[22].coord[0] = (_x * tileSize) + tileSize;
        _vertices[22].coord[1] = _height * heightScale;
        _vertices[22].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[22].texcoord[0] = 0;
        _vertices[22].texcoord[1] = 0.5f;

        _vertices[23].coord[0] = _x * tileSize;
        _vertices[23].coord[1] = _height * heightScale;
        _vertices[23].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[23].texcoord[0] = 0.5f;
        _vertices[23].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_SW)
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = _height * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = (_height + 100) * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = _x * tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = _x * tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = (_x * tileSize) + tileSize;
        _vertices[4].coord[1] = (_height + 100) * heightScale;
        _vertices[4].coord[2] = -_y * tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = (_x * tileSize) + tileSize;
        _vertices[5].coord[1] = (_height + 100) * heightScale;
        _vertices[5].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = (_x * tileSize) + tileSize;
        _vertices[7].coord[1] = _height * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0.5f;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].coord[0] = (_x * tileSize) + tileSize;
        _vertices[8].coord[1] = (_height + 100) * heightScale;
        _vertices[8].coord[2] = -_y * tileSize;
        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0;

        // side triangle 2
        _vertices[9].coord[0] = _x * tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = -_y * tileSize;
        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = _x * tileSize;
        _vertices[10].coord[1] = (_height + 100) * heightScale;
        _vertices[10].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].coord[0] = _x * tileSize;
        _vertices[11].coord[1] = _height * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        // front triangle 1
        _vertices[12].coord[0] = _x * tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = _x * tileSize;
        _vertices[13].coord[1] = (_height + 100) * heightScale;
        _vertices[13].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[14].texcoord[0] = 0;
        _vertices[14].texcoord[1] = 0;

        // front triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[15].texcoord[0] = 0;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = (_x * tileSize) + tileSize;
        _vertices[16].coord[1] = _height * heightScale;
        _vertices[16].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].coord[0] = _x * tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;

        // front triangle 3
        _vertices[18].coord[0] = (_x * tileSize) + tileSize;
        _vertices[18].coord[1] = _height * heightScale;
        _vertices[18].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[18].texcoord[0] = 0.5f;
        _vertices[18].texcoord[1] = 0.5f;

        _vertices[19].coord[0] = (_x * tileSize) + tileSize;
        _vertices[19].coord[1] = (_height + 100) * heightScale;
        _vertices[19].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[19].texcoord[0] = 0.5f;
        _vertices[19].texcoord[1] = 0;

        _vertices[20].coord[0] = (_x * tileSize) + tileSize;
        _vertices[20].coord[1] = (_height + 100) * heightScale;
        _vertices[20].coord[2] = -_y * tileSize;
        _vertices[20].texcoord[0] = 0;
        _vertices[20].texcoord[1] = 0;

        // front triangle 4
        _vertices[21].coord[0] = (_x * tileSize) + tileSize;
        _vertices[21].coord[1] = (_height + 100) * heightScale;
        _vertices[21].coord[2] = -_y * tileSize;
        _vertices[21].texcoord[0] = 0;
        _vertices[21].texcoord[1] = 0;

        _vertices[22].coord[0] = (_x * tileSize) + tileSize;
        _vertices[22].coord[1] = _height * heightScale;
        _vertices[22].coord[2] = -_y * tileSize;
        _vertices[22].texcoord[0] = 0;
        _vertices[22].texcoord[1] = 0.5f;

        _vertices[23].coord[0] = (_x * tileSize) + tileSize;
        _vertices[23].coord[1] = _height * heightScale;
        _vertices[23].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[23].texcoord[0] = 0.5f;
        _vertices[23].texcoord[1] = 0.5f;
    }
    else
    if (_type == ETT_SLOPE_NW)
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = (_height + 100) * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = (_x * tileSize) + tileSize;
        _vertices[2].coord[1] = (_height + 100) * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = (_x * tileSize) + tileSize;
        _vertices[3].coord[1] = (_height + 100) * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = _x * tileSize;
        _vertices[4].coord[1] = _height * heightScale;
        _vertices[4].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].coord[0] = _x * tileSize;
        _vertices[5].coord[1] = (_height + 100) * heightScale;
        _vertices[5].coord[2] = -_y * tileSize;
        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        // side triangle 1
        _vertices[6].coord[0] = _x * tileSize;
        _vertices[6].coord[1] = _height * heightScale;
        _vertices[6].coord[2] = -_y * tileSize;
        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].coord[0] = _x * tileSize;
        _vertices[7].coord[1] = (_height + 100) * heightScale;
        _vertices[7].coord[2] = -_y * tileSize;
        _vertices[7].texcoord[0] = 0.5f;
        _vertices[7].texcoord[1] = 0;

        _vertices[8].coord[0] = _x * tileSize;
        _vertices[8].coord[1] = _height * heightScale;
        _vertices[8].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[8].texcoord[0] = 0;
        _vertices[8].texcoord[1] = 0.5f;

        // side triangle 2
        _vertices[9].coord[0] = _x * tileSize;
        _vertices[9].coord[1] = _height * heightScale;
        _vertices[9].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].coord[0] = (_x * tileSize) + tileSize;
        _vertices[10].coord[1] = (_height + 100) * heightScale;
        _vertices[10].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].coord[0] = (_x * tileSize) + tileSize;
        _vertices[11].coord[1] = _height * heightScale;
        _vertices[11].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        // face triangle 1
        _vertices[12].coord[0] = (_x * tileSize) + tileSize;
        _vertices[12].coord[1] = _height * heightScale;
        _vertices[12].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0.5f;

        _vertices[13].coord[0] = (_x * tileSize) + tileSize;
        _vertices[13].coord[1] = (_height + 100) * heightScale;
        _vertices[13].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[13].texcoord[0] = 0.5f;
        _vertices[13].texcoord[1] = 0;

        _vertices[14].coord[0] = (_x * tileSize) + tileSize;
        _vertices[14].coord[1] = (_height + 100) * heightScale;
        _vertices[14].coord[2] = -_y * tileSize;
        _vertices[14].texcoord[0] = 0;
        _vertices[14].texcoord[1] = 0;

        // face triangle 2
        _vertices[15].coord[0] = (_x * tileSize) + tileSize;
        _vertices[15].coord[1] = (_height + 100) * heightScale;
        _vertices[15].coord[2] = -_y * tileSize;
        _vertices[15].texcoord[0] = 0;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].coord[0] = (_x * tileSize) + tileSize;
        _vertices[16].coord[1] = _height * heightScale;
        _vertices[16].coord[2] = -_y * tileSize;
        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].coord[0] = (_x * tileSize) + tileSize;
        _vertices[17].coord[1] = _height * heightScale;
        _vertices[17].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;

        // front triangle 3
        _vertices[18].coord[0] = _x * tileSize;
        _vertices[18].coord[1] = (_height + 100) * heightScale;
        _vertices[18].coord[2] = -_y * tileSize;
        _vertices[18].texcoord[0] = 0;
        _vertices[18].texcoord[1] = 0;

        _vertices[19].coord[0] = _x * tileSize;
        _vertices[19].coord[1] = _height * heightScale;
        _vertices[19].coord[2] = -_y * tileSize;
        _vertices[19].texcoord[0] = 0;
        _vertices[19].texcoord[1] = 0.5f;

        _vertices[20].coord[0] = (_x * tileSize) + tileSize;
        _vertices[20].coord[1] = _height * heightScale;
        _vertices[20].coord[2] = -_y * tileSize;
        _vertices[20].texcoord[0] = 0.5f;
        _vertices[20].texcoord[1] = 0.5f;

        // front triangle 4
        _vertices[21].coord[0] = (_x * tileSize) + tileSize;
        _vertices[21].coord[1] = _height * heightScale;
        _vertices[21].coord[2] = -_y * tileSize;
        _vertices[21].texcoord[0] = 0.5f;
        _vertices[21].texcoord[1] = 0.5f;

        _vertices[22].coord[0] = (_x * tileSize) + tileSize;
        _vertices[22].coord[1] = (_height + 100) * heightScale;
        _vertices[22].coord[2] = -_y * tileSize;
        _vertices[22].texcoord[0] = 0.5f;
        _vertices[22].texcoord[1] = 0;

        _vertices[23].coord[0] = _x * tileSize;
        _vertices[23].coord[1] = (_height + 100) * heightScale;
        _vertices[23].coord[2] = -_y * tileSize;
        _vertices[23].texcoord[0] = 0;
        _vertices[23].texcoord[1] = 0;
    }
    else
    if (_type == ETT_CORNER_NE)
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = _x * tileSize;
        _vertices[0].coord[1] = (_height + 100) * heightScale;
        _vertices[0].coord[2] = -_y * tileSize;
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].coord[0] = (_x * tileSize) + tileSize;
        _vertices[1].coord[1] = _height * heightScale;
        _vertices[1].coord[2] = -_y * tileSize;
        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0;

        _vertices[2].coord[0] = _x * tileSize;
        _vertices[2].coord[1] = _height * heightScale;
        _vertices[2].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].coord[0] = _x * tileSize;
        _vertices[3].coord[1] = _height * heightScale;
        _vertices[3].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].coord[0] = (_x * tileSize) + tileSize;
        _vertices[4].coord[1] = _height * heightScale;
        _vertices[4].coord[2] = -_y * tileSize;
        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].coord[0] = (_x * tileSize) + tileSize;
        _vertices[5].coord[1] = _height * heightScale;
        _vertices[5].coord[2] = (-_y * tileSize) - tileSize;
        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;
    }
}
