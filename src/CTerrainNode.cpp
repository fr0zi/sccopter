#include "CTerrainNode.hpp"

CTerrainNode::CTerrainNode(CNode* parent, CWarehouser* warehouser, vbcString name, Tile* tiles, int seaLevel)
: _Warehouser(warehouser),
    CNode(parent, name)
{
    _Warehouser->grab();

    _seaLevel = seaLevel;

    if (tiles)
        generateTerrainMesh(tiles);

    //printf("Terrain Node: Sea level: %d\n", _seaLevel);
}


CTerrainNode::~CTerrainNode()
{
    for (int i = 0; i < _tiles.size(); i++)
        delete _tiles[i];

    _Warehouser->drop();
}

void CTerrainNode::generateTerrainMesh(Tile* tiles)
{
    const int TILES = 128;


    /*

   0,0-----1,0
    |     / |
    |    /  |
    |   /   |
    |  /    |
    | /     |
   0,1-----1,1
    */

    int currentHeight = 0;

    for (int y = 0; y < TILES; ++y)
        for (int x = 0; x < TILES; ++x)
        {
            //currentHeight = tiles[y * 128 + x].height;

            if (tiles[y * 128 + x].type >= 0x10 && tiles[y * 128 + x].type <= 0x20)
            {
                //printf("Sea level: %d\t", _seaLevel);
                currentHeight = _seaLevel;
            }
            else
                currentHeight = tiles[y * 128 + x].height;
                //printf("Type: %x\t", tiles[y * 128 + x].type);
            /*
            TileType currentTileType = tiles[y * 128 + x].type;
            if (( (int)tiles[y * 128 + x].type >= ETT_UNDERWATER_FLAT) && ((int)tiles[y * 128 + x].type < ETT_WATER_SUBMERGED_HIGHGROUND))
            {
                currentHeight = _seaLevel;
                printf("Terrain Node: Current height: %d\n", currentHeight);
            }
            else
            {
                currentHeight = tiles[y * 128 + x].height;
            }
            */
            CTerrainTile* tile = new CTerrainTile(x, y, currentHeight, tiles[y * 128 + x].type);

            // chwilowy workaround na czas zaimplementowania wszystkich rodzajow kafli terenu
            // jesli utworzony tile zwroci 0 vertexow, to znaczy ze jeszcze nie ma implementacji danego typu i mozna go usunac
            if (tile->getVertexCount() > 0)
                _tiles.push_back(tile);
        }


    SMaterial mat;

    //GLuint texId = _Warehouser->loadTexture("textures_new.png");
    GLuint texId = _Warehouser->loadTexture("texture_atlas.png");

    //std::cout << "Texture ID: " << texId << std::endl;

    if (texId != 0)
        mat.textureId = texId;



    //std::cout << "Material Texture ID: " << mat.textureId << std::endl;

    int totalVertexCount = 0;

    for (int i = 0; i < _tiles.size(); i++)
        totalVertexCount += _tiles[i]->getVertexCount();

    printf("Total vertex count: %d\n", totalVertexCount);



    S3DVertex* vertices = new S3DVertex[totalVertexCount];

    int startPoint = 0;

    for (int i = 0; i < _tiles.size(); i++)
    {
        for (int j = 0; j < _tiles[i]->getVertexCount(); j++)
        {
                vertices[startPoint].coord[0] = _tiles[i]->getVertices()[j].coord[0];
                vertices[startPoint].coord[1] = _tiles[i]->getVertices()[j].coord[1];
                vertices[startPoint].coord[2] = _tiles[i]->getVertices()[j].coord[2];
                vertices[startPoint].texcoord[0] = _tiles[i]->getVertices()[j].texcoord[0];
                vertices[startPoint].texcoord[1] = _tiles[i]->getVertices()[j].texcoord[1];

                //printf("V %f\n", _tiles[i]->getVertices()[j].coord[0]);
                //printf("V %f\n", _tiles[i]->getVertices()[j].coord[1]);

                //printf("V %d: %f %f %f\n", startPoint, vertices[startPoint].coord[0], vertices[startPoint].coord[1], vertices[startPoint].coord[2]);
                startPoint++;
        }
    }

    CMeshBuffer* mb = new CMeshBuffer;

    //mb->setVertexData(vertices, TILES * TILES * VERTEX_COUNT);
    mb->setVertexData(vertices, totalVertexCount);
    mb->createVBO();
    mb->setMaterial(mat);

    m_Mesh = new CMesh;
    m_Mesh->setQuantumOfMeshBuffers(1);
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
