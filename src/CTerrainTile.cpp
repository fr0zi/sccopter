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
    const float heightScale = 0.07f;


    /*
     LEFT_X             RIGHT_X
     <-------------------- 0, 0
      + 128                 |   TOP_Y
                            |
                            |
                            |
                            |
                            |
                            |   BOTTOM_Y
                           \/   + 128
    */

    const float RIGHT_X = -_x * tileSize;
    const float LEFT_X  = (-_x * tileSize) - tileSize;
    const float TOP_Y  = _y * tileSize;
    const float BOTTOM_Y   = (_y * tileSize) + tileSize;

    const float RISEN = (_height + 100) * heightScale;
    const float FLAT = _height * heightScale;


    if ( ETT_FLAT == _type )
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = FLAT;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = FLAT;
        _vertices[1].coord[2] = BOTTOM_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = FLAT;
        _vertices[2].coord[2] = BOTTOM_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = FLAT;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = FLAT;
        _vertices[4].coord[2] = TOP_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = FLAT;
        _vertices[5].coord[2] = BOTTOM_Y;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SW == _type || ETT_WATER_SUBMERGED_SLOPE_NE == _type
        || ETT_WATER_SUBMERGED_SLOPE_NW == _type || ETT_WATER_SUBMERGED_SLOPE_SE == _type )
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = RISEN;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = RISEN;
        _vertices[1].coord[2] = BOTTOM_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = RISEN;
        _vertices[2].coord[2] = BOTTOM_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = RISEN;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = RISEN;
        _vertices[4].coord[2] = TOP_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = RISEN;
        _vertices[5].coord[2] = BOTTOM_Y;
    }
    else
    if ( ETT_SLOPE_N == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = RISEN;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = FLAT;
        _vertices[1].coord[2] = BOTTOM_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = FLAT;
        _vertices[2].coord[2] = BOTTOM_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = RISEN;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = RISEN;
        _vertices[4].coord[2] = TOP_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = FLAT;
        _vertices[5].coord[2] = BOTTOM_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = RISEN;
        _vertices[6].coord[2] = TOP_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = FLAT;
        _vertices[7].coord[2] = TOP_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = FLAT;
        _vertices[8].coord[2] = TOP_Y;

        // triangle 4
        _vertices[9].coord[0] = LEFT_X;
        _vertices[9].coord[1] = RISEN;
        _vertices[9].coord[2] = TOP_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = RISEN;
        _vertices[10].coord[2] = TOP_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = FLAT;
        _vertices[11].coord[2] = TOP_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = RISEN;
        _vertices[12].coord[2] = TOP_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = FLAT;
        _vertices[13].coord[2] = TOP_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = FLAT;
        _vertices[14].coord[2] = BOTTOM_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = RISEN;
        _vertices[15].coord[2] = TOP_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = FLAT;
        _vertices[16].coord[2] = BOTTOM_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = FLAT;
        _vertices[17].coord[2] = TOP_Y;
    }
    else
    if ( ETT_SLOPE_S == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = FLAT;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = RISEN;
        _vertices[1].coord[2] = BOTTOM_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = RISEN;
        _vertices[2].coord[2] = BOTTOM_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = FLAT;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = FLAT;
        _vertices[4].coord[2] = TOP_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = RISEN;
        _vertices[5].coord[2] = BOTTOM_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = RISEN;
        _vertices[6].coord[2] = BOTTOM_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = FLAT;
        _vertices[7].coord[2] = BOTTOM_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = FLAT;
        _vertices[8].coord[2] = BOTTOM_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = RISEN;
        _vertices[9].coord[2] = BOTTOM_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = RISEN;
        _vertices[10].coord[2] = BOTTOM_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = FLAT;
        _vertices[11].coord[2] = BOTTOM_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = RISEN;
        _vertices[12].coord[2] = BOTTOM_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = FLAT;
        _vertices[13].coord[2] = TOP_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = FLAT;
        _vertices[14].coord[2] = BOTTOM_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = RISEN;
        _vertices[15].coord[2] = BOTTOM_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = FLAT;
        _vertices[16].coord[2] = BOTTOM_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = FLAT;
        _vertices[17].coord[2] = TOP_Y;
    }
    else
    if ( ETT_SLOPE_E == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = RISEN;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = FLAT;
        _vertices[1].coord[2] = TOP_Y;

        _vertices[2].coord[0] = LEFT_X;
        _vertices[2].coord[1] = FLAT;
        _vertices[2].coord[2] = BOTTOM_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = RISEN;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = FLAT;
        _vertices[4].coord[2] = BOTTOM_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = RISEN;
        _vertices[5].coord[2] = BOTTOM_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = RISEN;
        _vertices[6].coord[2] = TOP_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = FLAT;
        _vertices[7].coord[2] = TOP_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = FLAT;
        _vertices[8].coord[2] = TOP_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = RISEN;
        _vertices[9].coord[2] = BOTTOM_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = FLAT;
        _vertices[10].coord[2] = BOTTOM_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = FLAT;
        _vertices[11].coord[2] = BOTTOM_Y;

        // triangle 5
        _vertices[12].coord[0] = RIGHT_X;
        _vertices[12].coord[1] = RISEN;
        _vertices[12].coord[2] = TOP_Y;

        _vertices[13].coord[0] = RIGHT_X;
        _vertices[13].coord[1] = RISEN;
        _vertices[13].coord[2] = BOTTOM_Y;

        _vertices[14].coord[0] = RIGHT_X;
        _vertices[14].coord[1] = FLAT;
        _vertices[14].coord[2] = BOTTOM_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = RISEN;
        _vertices[15].coord[2] = TOP_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = FLAT;
        _vertices[16].coord[2] = BOTTOM_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = FLAT;
        _vertices[17].coord[2] = TOP_Y;
    }
    else
    if ( ETT_SLOPE_W == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = FLAT;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = RISEN;
        _vertices[1].coord[2] = TOP_Y;

        _vertices[2].coord[0] = LEFT_X;
        _vertices[2].coord[1] = RISEN;
        _vertices[2].coord[2] = BOTTOM_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = FLAT;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = RISEN;
        _vertices[4].coord[2] = BOTTOM_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = FLAT;
        _vertices[5].coord[2] = BOTTOM_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = FLAT;
        _vertices[6].coord[2] = TOP_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = FLAT;
        _vertices[7].coord[2] = TOP_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = RISEN;
        _vertices[8].coord[2] = TOP_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = FLAT;
        _vertices[9].coord[2] = BOTTOM_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = RISEN;
        _vertices[10].coord[2] = BOTTOM_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = FLAT;
        _vertices[11].coord[2] = BOTTOM_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = RISEN;
        _vertices[12].coord[2] = TOP_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = FLAT;
        _vertices[13].coord[2] = TOP_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = FLAT;
        _vertices[14].coord[2] = BOTTOM_Y;

        // triangle 6
        _vertices[15].coord[0] = LEFT_X;
        _vertices[15].coord[1] = RISEN;
        _vertices[15].coord[2] = TOP_Y;

        _vertices[16].coord[0] = LEFT_X;
        _vertices[16].coord[1] = FLAT;
        _vertices[16].coord[2] = BOTTOM_Y;

        _vertices[17].coord[0] = LEFT_X;
        _vertices[17].coord[1] = RISEN;
        _vertices[17].coord[2] = BOTTOM_Y;
    }
    else
    if ( ETT_SLOPE_NE == _type )
    {
        _vertexCount = 12;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = RISEN;
        _vertices[0].coord[2] = TOP_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = RISEN;
        _vertices[1].coord[2] = TOP_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = RISEN;
        _vertices[2].coord[2] = BOTTOM_Y;

        // triangle 2
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = RISEN;
        _vertices[3].coord[2] = TOP_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = FLAT;
        _vertices[4].coord[2] = BOTTOM_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = RISEN;
        _vertices[5].coord[2] = BOTTOM_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = RISEN;
        _vertices[6].coord[2] = TOP_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = FLAT;
        _vertices[7].coord[2] = TOP_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = FLAT;
        _vertices[8].coord[2] = BOTTOM_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = RISEN;
        _vertices[9].coord[2] = BOTTOM_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = FLAT;
        _vertices[10].coord[2] = BOTTOM_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = FLAT;
        _vertices[11].coord[2] = BOTTOM_Y;
    }

    setTexture();
}


void CTerrainTile::setTexture()
{
    if ( ETT_FLAT == _type )
    {
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SW == _type )
    {
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 1;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 1;

        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 1;

        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SE == _type )
    {
        _vertices[0].texcoord[0] = 0.5f;
        _vertices[0].texcoord[1] = 1;

        _vertices[1].texcoord[0] = 1;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 0.5f;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 1;

        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 1;

        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_NE == _type )
    {
        _vertices[0].texcoord[0] = 0.5f;
        _vertices[0].texcoord[1] = 0.5f;

        _vertices[1].texcoord[0] = 1;
        _vertices[1].texcoord[1] = 1;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 1;

        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 1;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_NW == _type )
    {
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0.5f;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 1;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 1;

        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0.5f;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 1;
    }
    else
    if ( ETT_SLOPE_N == _type )
    {
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;

        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0;

        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0;

        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        _vertices[12].texcoord[0] = 0;
        _vertices[12].texcoord[1] = 0;

        _vertices[13].texcoord[0] = 0;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0.5f;

        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_SLOPE_S == _type )
    {
        _vertices[0].texcoord[0] = 1;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 1;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0;

        _vertices[5].texcoord[0] = 0.5f;
        _vertices[5].texcoord[1] = 0.5f;

        _vertices[6].texcoord[0] = 0.5f;
        _vertices[6].texcoord[1] = 0;

        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0;

        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0;

        _vertices[13].texcoord[0] = 0;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0.5f;

        _vertices[15].texcoord[0] = 0;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_SLOPE_E == _type )
    {
        _vertices[0].texcoord[0] = 0.5f;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0;

        _vertices[7].texcoord[0] = 0;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0;

        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0.5f;

        _vertices[12].texcoord[0] = 0.5f;
        _vertices[12].texcoord[1] = 0;

        _vertices[13].texcoord[0] = 0;
        _vertices[13].texcoord[1] = 0;

        _vertices[14].texcoord[0] = 0;
        _vertices[14].texcoord[1] = 0.5f;

        _vertices[15].texcoord[0] = 0.5f;
        _vertices[15].texcoord[1] = 0;

        _vertices[16].texcoord[0] = 0;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_SLOPE_W == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = 0.5f;
        _vertices[0].texcoord[1] = 0;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.5f;

        _vertices[2].texcoord[0] = 1;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0;

        _vertices[4].texcoord[0] = 1;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].texcoord[0] = 1;
        _vertices[5].texcoord[1] = 0;

        // triangle 3
        _vertices[6].texcoord[0] = 0;
        _vertices[6].texcoord[1] = 0.5f;

        _vertices[7].texcoord[0] = 0.5f;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0;

        // triangle 4
        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0.5f;

        _vertices[10].texcoord[0] = 0;
        _vertices[10].texcoord[1] = 0;

        _vertices[11].texcoord[0] = 0;
        _vertices[11].texcoord[1] = 0.5f;

        // triangle 5
        _vertices[12].texcoord[0] = 0.0f;
        _vertices[12].texcoord[1] = 0.0f;

        _vertices[13].texcoord[0] = 0.0f;
        _vertices[13].texcoord[1] = 0.5f;

        _vertices[14].texcoord[0] = 0.5f;
        _vertices[14].texcoord[1] = 0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = 0.0f;
        _vertices[15].texcoord[1] = 0.0f;

        _vertices[16].texcoord[0] = 0.5f;
        _vertices[16].texcoord[1] = 0.5f;

        _vertices[17].texcoord[0] = 0.5f;
        _vertices[17].texcoord[1] = 0.0f;
    }
    else
    if ( ETT_SLOPE_NE == _type )
    {
       // triangle 1
        _vertices[0].texcoord[0] = 1.0f;
        _vertices[0].texcoord[1] = 0.0f;

        _vertices[1].texcoord[0] = 0.5f;
        _vertices[1].texcoord[1] = 0.0f;

        _vertices[2].texcoord[0] = 1.0f;
        _vertices[2].texcoord[1] = 0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = 0.5f;
        _vertices[3].texcoord[1] = 0.0f;

        _vertices[4].texcoord[0] = 0.5f;
        _vertices[4].texcoord[1] = 0.5f;

        _vertices[5].texcoord[0] = 1.0f;
        _vertices[5].texcoord[1] = 0.5f;

        // triangle 3
        _vertices[6].texcoord[0] = 0.0f;
        _vertices[6].texcoord[1] = 0.0f;

        _vertices[7].texcoord[0] = 0.0f;
        _vertices[7].texcoord[1] = 0.5f;

        _vertices[8].texcoord[0] = 0.5f;
        _vertices[8].texcoord[1] = 0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = 0.5f;
        _vertices[9].texcoord[1] = 0.0f;

        _vertices[10].texcoord[0] = 0.0f;
        _vertices[10].texcoord[1] = 0.5f;

        _vertices[11].texcoord[0] = 0.5f;
        _vertices[11].texcoord[1] = 0.5f;
    }
    else
    if ( ETT_SLOPE_NW == _type )
    {

    }
    else
    if ( ETT_SLOPE_SE == _type )
    {

    }
    else
    if ( ETT_SLOPE_SW == _type )
    {

    }
}


