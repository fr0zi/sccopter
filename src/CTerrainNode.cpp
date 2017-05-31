#include "CTerrainNode.hpp"

CTerrainNode::CTerrainNode(CNode* parent, CWarehouser* warehouser, vbcString name, Tile* tiles)
: _Warehouser(warehouser),
    CNode(parent, name)
{
    _Warehouser->grab();

    if (tiles)
        generateTerrainMesh(tiles);


}


CTerrainNode::~CTerrainNode()
{
    _Warehouser->drop();
}


void CTerrainNode::generateTerrainMesh(Tile* tiles)
{
    const int TILES = 128;
    const char VERTEX_COUNT = 9;

    S3DVertex* vertices = new S3DVertex[TILES * TILES * VERTEX_COUNT];



    float tileSize = 10.0f;
    float heightScale = 0.05f;

    /*
 	for (int i = 0; i < TILES; i++)
    {
        printf("%f\t", (float)(tiles[i].height) );
    }
    */


    /*

   0,0-----1,0
    |     / |
    |    /  |
    |   /   |
    |  /    |
    | /     |
   0,1-----1,1
    */

    //for (int y = 0; y < 128; ++y)
    //int y = 0;
    for (int y = 0; y < TILES; ++y)
        for (int x = 0; x < TILES; ++x)
        {
            if (tiles[y * 128 + x].type == ETT_SLOPE_N)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_E)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_S)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_W)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_SLOPE_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_CORNER_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_CORNER_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_CORNER_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_CORNER_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_HIGHGROUND)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_FLAT)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_N)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_E)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_S)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_W)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_SLOPE_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_CORNER_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_CORNER_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_CORNER_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_CORNER_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_COVERED_HIGHGROUND)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_FLAT)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_N)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_E)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_S)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_W)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_SLOPE_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_CORNER_NE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_CORNER_SE)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_CORNER_SW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else if (tiles[y * 128 + x].type == ETT_WATER_SUBMERGED_CORNER_NW)
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }
            else
            {
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 1].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 2].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 3].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 4].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 5].texcoord[1] = 1;

                // side triangles
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[0] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 6].texcoord[1] = 0;

                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[1] = (tiles[y * 128 + x].height + 100) * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 7].texcoord[1] = 1;

                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[0] = x * tileSize; //-10.f;   // (x * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[1] = tiles[y * 128 + x].height * heightScale;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[0] = 0;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
                vertices[(y* 128 + x) * VERTEX_COUNT + 8].texcoord[1] = 1;
            }


        }




    SMaterial mat;

    GLuint texId = _Warehouser->loadTexture("grid.jpg");

    if (texId != 0)
        mat.textureId = texId;


    CMeshBuffer* mb = new CMeshBuffer;

    mb->setVertexData(vertices, TILES * TILES * VERTEX_COUNT);
    mb->createVBO();
    mb->setMaterial(mat);

    m_Mesh = new CMesh;
    //m_Mesh->setQuantumOfMeshBuffers(1);
    m_Mesh->addMeshBuffer(mb);

}

void CTerrainNode::render(ERenderPass pass)
{
	GLuint TextureID = glGetUniformLocation(m_ShaderID, "myTextureSampler");
	GLuint AlphaValueID = glGetUniformLocation(m_ShaderID, "alpha");

	CMeshBuffer* mb;

	if ( pass == ERP_SOLID )
	{
		//First we draw all solid objects
		for(unsigned int mbLoop = 0; mbLoop < m_Mesh->getQuantumOfMeshBuffers(); mbLoop++)
		{
			mb = m_Mesh->getMeshBuffer(mbLoop);

			if(mb->getMaterial().transparency == 0)
			{
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, mb->getMaterial().textureId);

				glUniform1i(TextureID, 0);
				glUniform1f(AlphaValueID, mb->getMaterial().transparency);


				// Setting interleaved VBO
				// Vertices: 3 x float, repeated in 32 bytes (8 * sizeof(float)), starting at 0 byte
				glEnableVertexAttribArray(0);
				glBindBuffer(GL_ARRAY_BUFFER, mb->getVertexBufferID() );
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0 );

				// Normals: 3 x float, repeated in 32 bytes (8 * sizeof(float)), starting at 12 byte (3 * sizeof(float))
				glEnableVertexAttribArray(1);
				glBindBuffer(GL_ARRAY_BUFFER, mb->getVertexBufferID() );
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float)*3)  );

				// Texture coords: 2 x float, repeated in 32 bytes (8 * sizeof(float)), starting at 24 byte (6 * sizeof(float))
				glEnableVertexAttribArray(2);
				glBindBuffer(GL_ARRAY_BUFFER, mb->getVertexBufferID() );
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(sizeof(float)*6) );


				// Drawing VBO
				glDrawArrays(GL_TRIANGLES, 0, mb->getQuantumOfVertices());

				glDisableVertexAttribArray(0);
				glDisableVertexAttribArray(1);
				glDisableVertexAttribArray(2);

			}

		}
	}
}
