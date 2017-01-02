#include "CTerrainNode.hpp"

CTerrainNode::CTerrainNode(CNode* parent, CWarehouser* warehouser, vbcString name, int* heights, Tile* tiles)
: _Warehouser(warehouser),
    CNode(parent, name)
{
    _Warehouser->grab();

    if (heights && tiles)
        generateTerrainMesh(heights, tiles);


}


CTerrainNode::~CTerrainNode()
{
    _Warehouser->drop();
}


void CTerrainNode::generateTerrainMesh(const int* heights, Tile* tiles)
{
    const int TILES = 128;

    S3DVertex* vertices = new S3DVertex[TILES * TILES * 6];



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
    int y = 0;
    for (int y = 0; y < TILES; ++y)
        for (int x = 0; x < TILES; ++x)
        {
            vertices[(y* 128 + x) * 6].coord[0] = x * tileSize; //0.0f;    // x * tileSize
            vertices[(y* 128 + x) * 6].coord[1] = tiles[y * 128 + x].height * heightScale; //(float)(*(heights + (y * 128 + x)) * heightScale);
            vertices[(y* 128 + x) * 6].coord[2] = -y * tileSize; //0.0f;     // y * tileSize
            vertices[(y* 128 + x) * 6].texcoord[0] = 1;
            vertices[(y* 128 + x) * 6].texcoord[1] = 0;

            vertices[(y* 128 + x) * 6 + 1].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 1].coord[1] = tiles[y * 128 + x].height * heightScale;
            vertices[(y* 128 + x) * 6 + 1].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 1].texcoord[0] = 0;
            vertices[(y* 128 + x) * 6 + 1].texcoord[1] = 1;

            vertices[(y* 128 + x) * 6 + 2].coord[0] = (x * tileSize) + tileSize; //-10.0f;   // (x * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 2].coord[1] = tiles[y * 128 + x].height * heightScale;
            vertices[(y* 128 + x) * 6 + 2].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
            vertices[(y* 128 + x) * 6 + 2].texcoord[0] = 0;
            vertices[(y* 128 + x) * 6 + 2].texcoord[1] = 0;

            vertices[(y* 128 + x) * 6 + 3].coord[0] = (x * tileSize) + tileSize; //-10.f;   // (x * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 3].coord[1] = tiles[y * 128 + x].height * heightScale;
            vertices[(y* 128 + x) * 6 + 3].coord[2] = (-y * tileSize) - tileSize; //-10.0f;   // (y * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 3].texcoord[0] = 0;
            vertices[(y* 128 + x) * 6 + 3].texcoord[1] = 1;

            vertices[(y* 128 + x) * 6 + 4].coord[0] = x * tileSize; //0.0f;    // x * tileSize
            vertices[(y* 128 + x) * 6 + 4].coord[1] = tiles[y * 128 + x].height * heightScale;
            vertices[(y* 128 + x) * 6 + 4].coord[2] = -y * tileSize; //0.0f;    // y * tileSize
            vertices[(y* 128 + x) * 6 + 4].texcoord[0] = 1;
            vertices[(y* 128 + x) * 6 + 4].texcoord[1] = 0;

            vertices[(y* 128 + x) * 6 + 5].coord[0] = x * tileSize; //0.0f;    // x * tileSize
            vertices[(y* 128 + x) * 6 + 5].coord[1] = tiles[y * 128 + x].height * heightScale;
            vertices[(y* 128 + x) * 6 + 5].coord[2] = (-y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize
            vertices[(y* 128 + x) * 6 + 5].texcoord[0] = 1;
            vertices[(y* 128 + x) * 6 + 5].texcoord[1] = 1;
/*
            vertices[x * 6].coord[0] = (-x * tileSize) - tileSize; //-10.0f;   // (x * tileSize) - tileSize
            vertices[x * 6].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6].coord[2] = y * tileSize; //0.0f;     // y * tileSize

            vertices[x * 6 + 1].coord[0] = (-x * tileSize) - tileSize; //-10.f;   // (x * tileSize) - tileSize
            vertices[x * 6 + 1].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6 + 1].coord[2] = (y * tileSize) + tileSize; //-10.0f;   // (y * tileSize) - tileSize

            vertices[x * 6 + 2].coord[0] = -x * tileSize; //0.0f;    // x * tileSize
            vertices[x * 6 + 2].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6 + 2].coord[2] = y * tileSize; //0.0f;    // y * tileSize

            vertices[x * 6 + 3].coord[0] = (-x * tileSize) - tileSize; //-10.f;   // (x * tileSize) - tileSize
            vertices[x * 6 + 3].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6 + 3].coord[2] = (y * tileSize) + tileSize; //-10.0f;   // (y * tileSize) - tileSize

            vertices[x * 6 + 4].coord[0] = -x * tileSize; //0.0f;    // x * tileSize
            vertices[x * 6 + 4].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6 + 4].coord[2] = y * tileSize; //0.0f;    // y * tileSize

            vertices[x * 6 + 5].coord[0] = -x * tileSize; //0.0f;    // x * tileSize
            vertices[x * 6 + 5].coord[1] = (float)(*(heights + x) * heightScale);
            vertices[x * 6 + 5].coord[2] = (y * tileSize) + tileSize; //-10.0f;  // (y * tileSize) - tileSize
*/
        }
    // for (y)

    /*
    int x = 0; int y = 0;

    //S3DVertex v = new S3DVertex[4]
    vertices[0].coord[0] = (x * tileSize) - tileSize; //-10.0f;   // (x * tileSize) - tileSize
    vertices[0].coord[1] = 150.0f * heightScale;
    vertices[0].coord[2] = y * tileSize; //0.0f;     // y * tileSize

    vertices[1].coord[0] = (x * tileSize) - tileSize; //-10.f;   // (x * tileSize) - tileSize
    vertices[1].coord[1] = 150.0f * heightScale;
    vertices[1].coord[2] = (y * tileSize) + tileSize; //-10.0f;   // (y * tileSize) - tileSize

    vertices[2].coord[0] = x * tileSize; //0.0f;    // x * tileSize
    vertices[2].coord[1] = 150.0f * heightScale;
    vertices[2].coord[2] = y * tileSize; //0.0f;    // y * tileSize

    //vertices[3].coord[0] = x * tileSize; //0.0f;    // x * tileSize
    //vertices[3].coord[1] = 0.0f;
    //vertices[3].coord[2] = (y * tileSize) - tileSize; //-10.0f;  // (y * tileSize) - tileSize

    vertices[3].coord[0] = (-x * tileSize) - tileSize; //-10.f;   // (x * tileSize) - tileSize
    vertices[3].coord[1] = 150.0f * heightScale;
    vertices[3].coord[2] = (y * tileSize) + tileSize; //-10.0f;   // (y * tileSize) - tileSize

    vertices[4].coord[0] = -x * tileSize; //0.0f;    // x * tileSize
    vertices[4].coord[1] = 150.0f * heightScale;
    vertices[4].coord[2] = y * tileSize; //0.0f;    // y * tileSize

    vertices[5].coord[0] = -x * tileSize; //0.0f;    // x * tileSize
    vertices[5].coord[1] = 150.0f * heightScale;
    vertices[5].coord[2] = (y * tileSize) + tileSize; //-10.0f;  // (y * tileSize) - tileSize

    x = 1; y = 1;
    */

    SMaterial mat;

    GLuint texId = _Warehouser->loadTexture("crate.bmp");

    std::cout << "Texture ID: " << texId << std::endl;

    if (texId != 0)
        mat.textureId = texId;

    std::cout << "Material Texture ID: " << mat.textureId << std::endl;


    CMeshBuffer* mb = new CMeshBuffer;

    mb->setVertexData(vertices, TILES * TILES * 6);
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
