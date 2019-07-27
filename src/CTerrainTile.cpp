#include "CTerrainTile.hpp"

CTerrainTile::CTerrainTile(unsigned char x, unsigned char y, int height, TileType type)
: _vertexCount(0), _type(type), _height(height), _x(x), _y(y)
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

    const float RIGHT_X = -_x * tileSize;
    const float LEFT_X  = (-_x * tileSize) - tileSize;
    const float FAR_Y  = _y * tileSize;
    const float NEAR_Y   = (_y * tileSize) + tileSize;

    const float TOP = (_height + 100) * heightScale;
    const float BOTTOM = _height * heightScale;
    /*
     LEFT_X             RIGHT_X
     <-------------------- 0, 0
      + 128                 |   FAR_Y
                            |
                            |
                            |
                            |
                            |
                            |   NEAR_Y
                           \/   + 128
    */



    if ( ETT_FLAT == _type || ETT_UNDERWATER_FLAT == _type || ETT_UNDERWATER_HIGHGROUND == _type
        || ETT_SURFACE_WATER_HIGHGROUND == _type
        || ETT_SURFACE_WATER_SLOPE_N == _type || ETT_SURFACE_WATER_SLOPE_S == _type
        || ETT_SURFACE_WATER_SLOPE_E == _type || ETT_SURFACE_WATER_SLOPE_W == _type
        || ETT_SURFACE_WATER_SLOPE_NE == _type || ETT_SURFACE_WATER_SLOPE_SE == _type
        || ETT_SURFACE_WATER_SLOPE_SW == _type || ETT_SURFACE_WATER_SLOPE_NW == _type
        || ETT_SURFACE_WATER_CORNER_NE == _type || ETT_SURFACE_WATER_CORNER_NW == _type
        || ETT_SURFACE_WATER_CORNER_SE == _type || ETT_SURFACE_WATER_CORNER_SW == _type
        || ETT_UNDERWATER_SLOPE_N == _type || ETT_UNDERWATER_SLOPE_S == _type
        || ETT_UNDERWATER_SLOPE_E == _type || ETT_UNDERWATER_SLOPE_W == _type
        || ETT_UNDERWATER_SLOPE_NE == _type || ETT_UNDERWATER_SLOPE_NW == _type
        || ETT_UNDERWATER_SLOPE_SE == _type || ETT_UNDERWATER_SLOPE_SW == _type
        || ETT_UNDERWATER_CORNER_NE == _type || ETT_UNDERWATER_CORNER_NW == _type
        || ETT_UNDERWATER_CORNER_SE == _type || ETT_UNDERWATER_CORNER_SW == _type
        || ETT_UNUSED_0E == _type || ETT_UNUSED_0F == _type || ETT_UNUSED_1E == _type || ETT_UNUSED_1F == _type
        || ETT_UNUSED_2E == _type || ETT_UNUSED_2F == _type || ETT_UNUSED_3F == _type
        || ETT_WATER_SUBMERGED_FLAT == _type
        || ETT_SURFACE_WATER_CANAL_NS == _type || ETT_SURFACE_WATER_CANAL_WE == _type
        )
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = BOTTOM;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SW == _type || ETT_WATER_SUBMERGED_SLOPE_NE == _type
        || ETT_WATER_SUBMERGED_SLOPE_NW == _type || ETT_WATER_SUBMERGED_SLOPE_SE == _type
        || ETT_WATER_SUBMERGED_SLOPE_N == _type || ETT_WATER_SUBMERGED_SLOPE_S == _type
        || ETT_WATER_SUBMERGED_SLOPE_E == _type || ETT_WATER_SUBMERGED_SLOPE_W == _type
        //|| ETT_WATER_SUBMERGED_CORNER_NE == _type
        )
    {
        _vertexCount = 6;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_SLOPE_N == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = BOTTOM;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = FAR_Y;

        // triangle 4
        _vertices[9].coord[0] = LEFT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = FAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = FAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = BOTTOM;
        _vertices[13].coord[2] = FAR_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = FAR_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = FAR_Y;
    }
    else
    if ( ETT_SLOPE_S == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = NEAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = NEAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = NEAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = BOTTOM;
        _vertices[13].coord[2] = FAR_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = NEAR_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = FAR_Y;
    }
    else
    if ( ETT_SLOPE_E == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = BOTTOM;
        _vertices[1].coord[2] = FAR_Y;

        _vertices[2].coord[0] = LEFT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = NEAR_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = FAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = NEAR_Y;

        // triangle 5
        _vertices[12].coord[0] = RIGHT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = FAR_Y;

        _vertices[13].coord[0] = RIGHT_X;
        _vertices[13].coord[1] = TOP;
        _vertices[13].coord[2] = NEAR_Y;

        _vertices[14].coord[0] = RIGHT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = FAR_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = FAR_Y;
    }
    else
    if ( ETT_SLOPE_W == _type )
    {
        _vertexCount = 18;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = FAR_Y;

        _vertices[2].coord[0] = LEFT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

         // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = BOTTOM;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = TOP;
        _vertices[8].coord[2] = FAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = NEAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = FAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = BOTTOM;
        _vertices[13].coord[2] = FAR_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = LEFT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = FAR_Y;

        _vertices[16].coord[0] = LEFT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = LEFT_X;
        _vertices[17].coord[1] = TOP;
        _vertices[17].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_SLOPE_NE == _type )
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1 - top
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = FAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2 - top
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = FAR_Y;

        // triangle 5
        _vertices[12].coord[0] = RIGHT_X;
        _vertices[12].coord[1] = BOTTOM;
        _vertices[12].coord[2] = NEAR_Y;

        _vertices[13].coord[0] = RIGHT_X;
        _vertices[13].coord[1] = TOP;
        _vertices[13].coord[2] = FAR_Y;

        _vertices[14].coord[0] = RIGHT_X;
        _vertices[14].coord[1] = TOP;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = BOTTOM;
        _vertices[15].coord[2] = NEAR_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = TOP;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = LEFT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = NEAR_Y;

        // triangle 7
        _vertices[18].coord[0] = RIGHT_X;
        _vertices[18].coord[1] = BOTTOM;
        _vertices[18].coord[2] = FAR_Y;

        _vertices[19].coord[0] = LEFT_X;
        _vertices[19].coord[1] = BOTTOM;
        _vertices[19].coord[2] = FAR_Y;

        _vertices[20].coord[0] = LEFT_X;
        _vertices[20].coord[1] = TOP;
        _vertices[20].coord[2] = FAR_Y;

        // triangle 8
        _vertices[21].coord[0] = RIGHT_X;
        _vertices[21].coord[1] = BOTTOM;
        _vertices[21].coord[2] = FAR_Y;

        _vertices[22].coord[0] = LEFT_X;
        _vertices[22].coord[1] = TOP;
        _vertices[22].coord[2] = FAR_Y;

        _vertices[23].coord[0] = RIGHT_X;
        _vertices[23].coord[1] = TOP;
        _vertices[23].coord[2] = FAR_Y;
    }
    else
    if ( ETT_SLOPE_SE == _type )
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = NEAR_Y;

        _vertices[1].coord[0] = RIGHT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = FAR_Y;

        // triangle 2
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = NEAR_Y;

        _vertices[4].coord[0] = RIGHT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = FAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = BOTTOM;
        _vertices[6].coord[2] = NEAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = TOP;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = FAR_Y;

        // triangle 4
        _vertices[9].coord[0] = LEFT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = FAR_Y;

        // triangle 5
        _vertices[12].coord[0] = RIGHT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = FAR_Y;

        _vertices[13].coord[0] = RIGHT_X;
        _vertices[13].coord[1] = TOP;
        _vertices[13].coord[2] = NEAR_Y;

        _vertices[14].coord[0] = RIGHT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = BOTTOM;
        _vertices[15].coord[2] = NEAR_Y;

        _vertices[16].coord[0] = RIGHT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = FAR_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = TOP;
        _vertices[17].coord[2] = FAR_Y;

        // triangle 7
        _vertices[18].coord[0] = RIGHT_X;
        _vertices[18].coord[1] = TOP;
        _vertices[18].coord[2] = NEAR_Y;

        _vertices[19].coord[0] = LEFT_X;
        _vertices[19].coord[1] = TOP;
        _vertices[19].coord[2] = NEAR_Y;

        _vertices[20].coord[0] = LEFT_X;
        _vertices[20].coord[1] = BOTTOM;
        _vertices[20].coord[2] = NEAR_Y;

        // triangle 8
        _vertices[21].coord[0] = LEFT_X;
        _vertices[21].coord[1] = BOTTOM;
        _vertices[21].coord[2] = NEAR_Y;

        _vertices[22].coord[0] = RIGHT_X;
        _vertices[22].coord[1] = BOTTOM;
        _vertices[22].coord[2] = NEAR_Y;

        _vertices[23].coord[0] = RIGHT_X;
        _vertices[23].coord[1] = TOP;
        _vertices[23].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_SLOPE_SW == _type )
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = RIGHT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = FAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = NEAR_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = FAR_Y;

        // triangle 4
        _vertices[9].coord[0] = LEFT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = FAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = TOP;
        _vertices[12].coord[2] = NEAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = BOTTOM;
        _vertices[13].coord[2] = NEAR_Y;

        _vertices[14].coord[0] = RIGHT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = NEAR_Y;

        // triangle 6
        _vertices[15].coord[0] = RIGHT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = NEAR_Y;

        _vertices[16].coord[0] = LEFT_X;
        _vertices[16].coord[1] = TOP;
        _vertices[16].coord[2] = NEAR_Y;

        _vertices[17].coord[0] = RIGHT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = NEAR_Y;

        // triangle 7
        _vertices[18].coord[0] = LEFT_X;
        _vertices[18].coord[1] = TOP;
        _vertices[18].coord[2] = NEAR_Y;

        _vertices[19].coord[0] = LEFT_X;
        _vertices[19].coord[1] = TOP;
        _vertices[19].coord[2] = FAR_Y;

        _vertices[20].coord[0] = LEFT_X;
        _vertices[20].coord[1] = BOTTOM;
        _vertices[20].coord[2] = FAR_Y;

        // triangle 8
        _vertices[21].coord[0] = LEFT_X;
        _vertices[21].coord[1] = BOTTOM;
        _vertices[21].coord[2] = FAR_Y;

        _vertices[22].coord[0] = LEFT_X;
        _vertices[22].coord[1] = BOTTOM;
        _vertices[22].coord[2] = NEAR_Y;

        _vertices[23].coord[0] = LEFT_X;
        _vertices[23].coord[1] = TOP;
        _vertices[23].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_SLOPE_NW == _type )
    {
        _vertexCount = 24;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = FAR_Y;

        // triangle 2
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = NEAR_Y;

        _vertices[4].coord[0] = RIGHT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = FAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = NEAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = TOP;
        _vertices[11].coord[2] = FAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = BOTTOM;
        _vertices[12].coord[2] = NEAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = TOP;
        _vertices[13].coord[2] = NEAR_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = TOP;
        _vertices[14].coord[2] = FAR_Y;

        // triangle 6
        _vertices[15].coord[0] = LEFT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = FAR_Y;

        _vertices[16].coord[0] = LEFT_X;
        _vertices[16].coord[1] = BOTTOM;
        _vertices[16].coord[2] = FAR_Y;

        _vertices[17].coord[0] = LEFT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = NEAR_Y;

        // triangle 7
        _vertices[18].coord[0] = LEFT_X;
        _vertices[18].coord[1] = BOTTOM;
        _vertices[18].coord[2] = FAR_Y;

        _vertices[19].coord[0] = LEFT_X;
        _vertices[19].coord[1] = TOP;
        _vertices[19].coord[2] = FAR_Y;

        _vertices[20].coord[0] = RIGHT_X;
        _vertices[20].coord[1] = TOP;
        _vertices[20].coord[2] = FAR_Y;

        // triangle 8
        _vertices[21].coord[0] = RIGHT_X;
        _vertices[21].coord[1] = TOP;
        _vertices[21].coord[2] = FAR_Y;

        _vertices[22].coord[0] = RIGHT_X;
        _vertices[22].coord[1] = BOTTOM;
        _vertices[22].coord[2] = FAR_Y;

        _vertices[23].coord[0] = LEFT_X;
        _vertices[23].coord[1] = BOTTOM;
        _vertices[23].coord[2] = FAR_Y;
    }
    else
    if ( ETT_CORNER_NE == _type )
    {
        _vertexCount = 12;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = NEAR_Y;

        _vertices[1].coord[0] = RIGHT_X;
        _vertices[1].coord[1] = BOTTOM;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = LEFT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = FAR_Y;

        // triangle 2
        _vertices[3].coord[0] = LEFT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = RIGHT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = FAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = BOTTOM;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = TOP;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = FAR_Y;
    }
    else
    if ( ETT_CORNER_SE == _type )
    {
        _vertexCount = 12;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = NEAR_Y;

        _vertices[1].coord[0] = RIGHT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = FAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = RIGHT_X;
        _vertices[6].coord[1] = BOTTOM;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = RIGHT_X;
        _vertices[7].coord[1] = TOP;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_CORNER_SW == _type )
    {
        _vertexCount = 12;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = BOTTOM;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = NEAR_Y;

        _vertices[4].coord[0] = RIGHT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = FAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = BOTTOM;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = TOP;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = LEFT_X;
        _vertices[9].coord[1] = TOP;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = RIGHT_X;
        _vertices[11].coord[1] = BOTTOM;
        _vertices[11].coord[2] = NEAR_Y;
    }
    else
    if ( ETT_CORNER_NW == _type )
    {
        _vertexCount = 12;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = LEFT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = BOTTOM;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = BOTTOM;
        _vertices[2].coord[2] = FAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = BOTTOM;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = BOTTOM;
        _vertices[4].coord[2] = NEAR_Y;

        _vertices[5].coord[0] = RIGHT_X;
        _vertices[5].coord[1] = BOTTOM;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = FAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = FAR_Y;

        _vertices[8].coord[0] = LEFT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = FAR_Y;

        _vertices[10].coord[0] = LEFT_X;
        _vertices[10].coord[1] = BOTTOM;
        _vertices[10].coord[2] = FAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = TOP;
        _vertices[11].coord[2] = FAR_Y;
    }
    else
    if (ETT_HIGHGROUND == _type || ETT_WATER_SUBMERGED_HIGHGROUND == _type || ETT_WATERFALL == _type)
    {
        _vertexCount = 30;
        _vertices = new S3DVertex[_vertexCount];

        // triangle 1
        _vertices[0].coord[0] = RIGHT_X;
        _vertices[0].coord[1] = TOP;
        _vertices[0].coord[2] = FAR_Y;

        _vertices[1].coord[0] = LEFT_X;
        _vertices[1].coord[1] = TOP;
        _vertices[1].coord[2] = NEAR_Y;

        _vertices[2].coord[0] = RIGHT_X;
        _vertices[2].coord[1] = TOP;
        _vertices[2].coord[2] = NEAR_Y;

        // triangle 2
        _vertices[3].coord[0] = RIGHT_X;
        _vertices[3].coord[1] = TOP;
        _vertices[3].coord[2] = FAR_Y;

        _vertices[4].coord[0] = LEFT_X;
        _vertices[4].coord[1] = TOP;
        _vertices[4].coord[2] = FAR_Y;

        _vertices[5].coord[0] = LEFT_X;
        _vertices[5].coord[1] = TOP;
        _vertices[5].coord[2] = NEAR_Y;

        // triangle 3
        _vertices[6].coord[0] = LEFT_X;
        _vertices[6].coord[1] = TOP;
        _vertices[6].coord[2] = NEAR_Y;

        _vertices[7].coord[0] = LEFT_X;
        _vertices[7].coord[1] = BOTTOM;
        _vertices[7].coord[2] = NEAR_Y;

        _vertices[8].coord[0] = RIGHT_X;
        _vertices[8].coord[1] = BOTTOM;
        _vertices[8].coord[2] = NEAR_Y;

        // triangle 4
        _vertices[9].coord[0] = RIGHT_X;
        _vertices[9].coord[1] = BOTTOM;
        _vertices[9].coord[2] = NEAR_Y;

        _vertices[10].coord[0] = RIGHT_X;
        _vertices[10].coord[1] = TOP;
        _vertices[10].coord[2] = NEAR_Y;

        _vertices[11].coord[0] = LEFT_X;
        _vertices[11].coord[1] = TOP;
        _vertices[11].coord[2] = NEAR_Y;

        // triangle 5
        _vertices[12].coord[0] = LEFT_X;
        _vertices[12].coord[1] = BOTTOM;
        _vertices[12].coord[2] = NEAR_Y;

        _vertices[13].coord[0] = LEFT_X;
        _vertices[13].coord[1] = TOP;
        _vertices[13].coord[2] = NEAR_Y;

        _vertices[14].coord[0] = LEFT_X;
        _vertices[14].coord[1] = BOTTOM;
        _vertices[14].coord[2] = FAR_Y;

        // triangle 6
        _vertices[15].coord[0] = LEFT_X;
        _vertices[15].coord[1] = TOP;
        _vertices[15].coord[2] = NEAR_Y;

        _vertices[16].coord[0] = LEFT_X;
        _vertices[16].coord[1] = TOP;
        _vertices[16].coord[2] = FAR_Y;

        _vertices[17].coord[0] = LEFT_X;
        _vertices[17].coord[1] = BOTTOM;
        _vertices[17].coord[2] = FAR_Y;

        // triangle 7
        _vertices[18].coord[0] = RIGHT_X;
        _vertices[18].coord[1] = TOP;
        _vertices[18].coord[2] = FAR_Y;

        _vertices[19].coord[0] = RIGHT_X;
        _vertices[19].coord[1] = TOP;
        _vertices[19].coord[2] = NEAR_Y;

        _vertices[20].coord[0] = RIGHT_X;
        _vertices[20].coord[1] = BOTTOM;
        _vertices[20].coord[2] = NEAR_Y;

        // triangle 8
        _vertices[21].coord[0] = RIGHT_X;
        _vertices[21].coord[1] = BOTTOM;
        _vertices[21].coord[2] = NEAR_Y;

        _vertices[22].coord[0] = RIGHT_X;
        _vertices[22].coord[1] = BOTTOM;
        _vertices[22].coord[2] = FAR_Y;

        _vertices[23].coord[0] = RIGHT_X;
        _vertices[23].coord[1] = TOP;
        _vertices[23].coord[2] = FAR_Y;

        // triangle 9
        _vertices[24].coord[0] = LEFT_X;
        _vertices[24].coord[1] = BOTTOM;
        _vertices[24].coord[2] = FAR_Y;

        _vertices[25].coord[0] = LEFT_X;
        _vertices[25].coord[1] = TOP;
        _vertices[25].coord[2] = FAR_Y;

        _vertices[26].coord[0] = RIGHT_X;
        _vertices[26].coord[1] = TOP;
        _vertices[26].coord[2] = FAR_Y;

        // triangle 10
        _vertices[27].coord[0] = RIGHT_X;
        _vertices[27].coord[1] = TOP;
        _vertices[27].coord[2] = FAR_Y;

        _vertices[28].coord[0] = RIGHT_X;
        _vertices[28].coord[1] = BOTTOM;
        _vertices[28].coord[2] = FAR_Y;

        _vertices[29].coord[0] = LEFT_X;
        _vertices[29].coord[1] = BOTTOM;
        _vertices[29].coord[2] = FAR_Y;

    }

    setTexture();
}


void CTerrainTile::setTexture()
{
        /*
    Texture atlas:

    4x4 textures

    1. Raw ground - tiles sides and highground: 0.0 - 0.25
    2. Surface ground - all surface tiles
    3. Full water - all tiles completely under water
    4. Water corner
    5. Water with shore on one side
    6. Water canal - water going through two shores
    7. Bay - where water canal ends
    8. Surface water - tile with circle water on the surface)
    9. Waterfall side
    */

    //typedef float[2] = uv;

    const float TEX_RAW_DIRT[8] = {
        0.0f, 0.25f,
        0.0f, 0.25f
        //0.0f, 0.25f,
        //0.25f, 0.25f
        };

    const float TEX_SURFACE[8] = {
        0.25f, 0.5f,
        0.0f, 0.25f
        //0.25f, 0.25f,
        //0.5f, 0.25f
        };

    /*
    const float TEX_SURFACE[8] = {
        0.5f, 1.0f,
        0.0f, 0.5f
        };
    */

    const float TEX_WATER[8] = {
        0.5f, 0.75f,
        0.0f, 0.25f
        //0.5f, 0.25f,
        //0.75f, 0.25f
        };

    const float TEX_WATER_CORNER[8] = {
        0.75f, 1.0f,
        0.0f, 0.25f
        //0.75f, 0.25f,
        //1.0f, 0.25f
        };

    const float TEX_WATER_SHORE[8] = {
        0.0f, 0.25f,
        0.25f, 0.5f
        //0.75f, 0.25f,
        //1.0f, 0.25f
        };

    const float TEX_WATER_SURFACE[8] = {
        0.75f, 1.0f,
        0.25f, 0.5f
        };

    const float TEX_WATERFALL[8] = {
        0.0f, 0.25f,
        0.5f, 0.75f
        };

    const float TEX_WATER_CANAL[8] = {
        0.25f, 0.5f,
        0.25f, 0.5f
        };

    if ( ETT_FLAT == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Max]; //1
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SW == _type || ETT_SURFACE_WATER_SLOPE_SW == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[1].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[2].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[3].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[4].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[4].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_SE == _type || ETT_SURFACE_WATER_SLOPE_SE == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[1].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[1].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[2].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[3].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[4].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[4].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[5].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[5].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_NE == _type || ETT_SURFACE_WATER_SLOPE_NE == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[1].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[2].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[3].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[5].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[5].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_NW == _type || ETT_SURFACE_WATER_SLOPE_NW == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[2].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;

        _vertices[3].texcoord[0] = TEX_WATER_CORNER[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_CORNER[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_CORNER[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_CORNER[V_Max];//1;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_N == _type || ETT_SURFACE_WATER_SLOPE_N == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_SHORE[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

        _vertices[2].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

        _vertices[3].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_SHORE[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_SHORE[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_S == _type || ETT_SURFACE_WATER_SLOPE_S == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;

        _vertices[2].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;

        _vertices[3].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;
    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_E == _type || ETT_SURFACE_WATER_SLOPE_E == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_SHORE[U_Max]; //TEX_WATER_SHORE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_SHORE[V_Min]; //TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

        _vertices[2].texcoord[0] = TEX_WATER_SHORE[U_Min];//1;
        _vertices[2].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;

        _vertices[3].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_SHORE[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_SHORE[U_Max];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

    }
    else
    if ( ETT_WATER_SUBMERGED_SLOPE_W == _type || ETT_SURFACE_WATER_SLOPE_W == _type )
    {
        _vertices[0].texcoord[0] = TEX_WATER_SHORE[U_Max]; //TEX_WATER_SHORE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_WATER_SHORE[V_Max]; //TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;

        _vertices[2].texcoord[0] = TEX_WATER_SHORE[U_Min];//1;
        _vertices[2].texcoord[1] = TEX_WATER_SHORE[V_Max];//1;

        _vertices[3].texcoord[0] = TEX_WATER_SHORE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_WATER_SHORE[V_Max];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_SHORE[U_Max];//0.5f;
        _vertices[4].texcoord[1] = TEX_WATER_SHORE[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_SHORE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_WATER_SHORE[V_Min];//1;

    }
    else
    if ( ETT_SLOPE_N == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // side tiles
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_SLOPE_S == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // side tiles
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_SLOPE_E == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0;

        // side tiles
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_SLOPE_W == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;
    }
    else
    if ( ETT_SLOPE_NE == _type )
    {
       // triangle 1
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[18].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[19].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[19].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[20].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[20].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 8
        _vertices[21].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[22].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[22].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[23].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[23].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;
    }
    else
    if ( ETT_SLOPE_SE == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[18].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[19].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[19].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[20].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[20].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 8
        _vertices[21].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[22].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[22].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[23].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[23].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;
    }
    else
    if ( ETT_SLOPE_SW == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[18].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[19].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[19].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[20].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[20].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 8
        _vertices[21].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[22].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[22].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[23].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[23].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;
    }
    else
    if ( ETT_SLOPE_NW == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[18].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[19].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[19].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[20].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[20].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 7
        _vertices[21].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[22].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[22].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[23].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[23].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_CORNER_NE == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Min];//0.5;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[3].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // side walls
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Min];//0;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_CORNER_SE == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_CORNER_SW == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_CORNER_NW == _type )
    {
        _vertices[0].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[0].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[1].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[2].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[3].texcoord[1] = TEX_SURFACE[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_SURFACE[U_Min];//0.5f;
        _vertices[4].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        _vertices[5].texcoord[0] = TEX_SURFACE[U_Max];//1.0f;
        _vertices[5].texcoord[1] = TEX_SURFACE[V_Max];//0.5f;

        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 3
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;
    }
    else
    if ( ETT_HIGHGROUND == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[2].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[4].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[5].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[10].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[11].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[11].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[13].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[13].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[14].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[14].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[16].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[16].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[17].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[17].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[18].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[19].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[19].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[20].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[20].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        // triangle 8
        _vertices[21].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[22].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[22].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[23].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[23].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 9
        _vertices[24].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[24].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[25].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[25].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[26].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[26].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        // triangle 10
        _vertices[27].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[27].texcoord[1] = TEX_RAW_DIRT[V_Min];//0.0f;

        _vertices[28].texcoord[0] = TEX_RAW_DIRT[U_Max];//0.5f;
        _vertices[28].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;

        _vertices[29].texcoord[0] = TEX_RAW_DIRT[U_Min];//0.0f;
        _vertices[29].texcoord[1] = TEX_RAW_DIRT[V_Max];//0.5f;
    }
    else
    if ( ETT_UNDERWATER_FLAT == _type
        || ETT_SURFACE_WATER_SLOPE_N == _type || ETT_SURFACE_WATER_SLOPE_S == _type
        || ETT_SURFACE_WATER_SLOPE_E == _type || ETT_SURFACE_WATER_SLOPE_W == _type
        || ETT_SURFACE_WATER_SLOPE_NE == _type || ETT_SURFACE_WATER_SLOPE_NW == _type
        || ETT_SURFACE_WATER_SLOPE_SE == _type || ETT_SURFACE_WATER_SLOPE_SW == _type
        || ETT_UNDERWATER_SLOPE_N == _type || ETT_UNDERWATER_SLOPE_S == _type
        || ETT_UNDERWATER_SLOPE_E == _type || ETT_UNDERWATER_SLOPE_W == _type
        || ETT_UNDERWATER_SLOPE_NE == _type || ETT_UNDERWATER_SLOPE_NW == _type
        || ETT_UNDERWATER_SLOPE_SE == _type || ETT_UNDERWATER_SLOPE_SW == _type
        || ETT_UNDERWATER_CORNER_NE == _type || ETT_UNDERWATER_CORNER_NW == _type
        || ETT_UNDERWATER_CORNER_SE == _type || ETT_UNDERWATER_CORNER_SW == _type
        || ETT_WATER_SUBMERGED_FLAT == _type
         )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_WATER[V_Max];//1.0f;

        _vertices[2].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER[V_Max];//1.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[4].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_WATER[V_Max];//1.0f;
    }
    else
    if (ETT_SURFACE_WATER_HIGHGROUND == _type)
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_WATER_SURFACE[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER_SURFACE[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_SURFACE[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_WATER_SURFACE[V_Max];//1.0f;

        _vertices[2].texcoord[0] = TEX_WATER_SURFACE[U_Max];//1.5f;//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER_SURFACE[V_Max];//1.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_WATER_SURFACE[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER_SURFACE[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_SURFACE[U_Min];//1.0f;//0.0f;
        _vertices[4].texcoord[1] = TEX_WATER_SURFACE[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_SURFACE[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_WATER_SURFACE[V_Max];//1.0f;
    }
    else
    if (ETT_WATERFALL == _type)
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER[V_Min];//0.0f;

        _vertices[1].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_WATER[V_Max];//0.5f;

        _vertices[2].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER[V_Max];//0.5f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER[V_Min];//0.0f;

        _vertices[4].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[4].texcoord[1] = TEX_WATER[V_Min];//0.0f;

        _vertices[5].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_WATER[V_Max];//0.5f;

        // side walls
        // triangle 3
        _vertices[6].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[6].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[7].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[7].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[8].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[8].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        // triangle 4
        _vertices[9].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[9].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[10].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[10].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[11].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[11].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        // triangle 5
        _vertices[12].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[12].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[13].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[13].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[14].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[14].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        // triangle 6
        _vertices[15].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[15].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[16].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[16].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[17].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[17].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        // triangle 7
        _vertices[18].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[18].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[19].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[19].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[20].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[20].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        // triangle 8
        _vertices[21].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[21].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[22].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[22].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[23].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[23].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        // triangle 9
        _vertices[24].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[24].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[25].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[25].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[26].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[26].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        // triangle 10
        _vertices[27].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[27].texcoord[1] = TEX_WATERFALL[V_Min];//0.0f;

        _vertices[28].texcoord[0] = TEX_WATERFALL[U_Max];//0.5f;
        _vertices[28].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;

        _vertices[29].texcoord[0] = TEX_WATERFALL[U_Min];//0.0f;
        _vertices[29].texcoord[1] = TEX_WATERFALL[V_Max];//0.5f;
    }
    else
    if (ETT_SURFACE_WATER_HIGHGROUND == _type)
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_WATER[V_Min];//1.0f;

        _vertices[2].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER[V_Max];//1.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_WATER[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[4].texcoord[1] = TEX_WATER[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_WATER[V_Max];//1.0f
    }
    else // TODO Fix UV mappings
    if ( ETT_SURFACE_WATER_CANAL_NS == _type || ETT_SURFACE_WATER_CANAL_WE == _type )
    {
        // triangle 1
        _vertices[0].texcoord[0] = TEX_WATER_CANAL[U_Max];//0.5f;
        _vertices[0].texcoord[1] = TEX_WATER_CANAL[V_Min];//0.5f;

        _vertices[1].texcoord[0] = TEX_WATER_CANAL[U_Min];//0.0f;
        _vertices[1].texcoord[1] = TEX_WATER_CANAL[V_Min];//1.0f;

        _vertices[2].texcoord[0] = TEX_WATER_CANAL[U_Max];//0.5f;
        _vertices[2].texcoord[1] = TEX_WATER_CANAL[V_Max];//1.0f;

        // triangle 2
        _vertices[3].texcoord[0] = TEX_WATER_CANAL[U_Max];//0.5f;
        _vertices[3].texcoord[1] = TEX_WATER_CANAL[V_Min];//0.5f;

        _vertices[4].texcoord[0] = TEX_WATER_CANAL[U_Min];//0.0f;
        _vertices[4].texcoord[1] = TEX_WATER_CANAL[V_Min];//0.5f;

        _vertices[5].texcoord[0] = TEX_WATER_CANAL[U_Min];//0.0f;
        _vertices[5].texcoord[1] = TEX_WATER_CANAL[V_Max];//1.0f
    }
}
