#ifndef __CDIRECTOR_HPP__
#define __CDIRECTOR_HPP__

#include <list>

#include "Includes.hpp"
#include "CNode.hpp"
#include "CLoader3ds.hpp"
#include "CVisioner.hpp"
#include "CMeshNode.hpp"
#include "vbTransform.hpp"
#include "CTerrainNode.hpp"

typedef std::list<CNode*>	NodeList;


class CDirector : virtual public CNode
{
	public:
		CDirector(vbcString name = "Director")
		{
			#ifdef DEBUG_MODE
            printf("Creating Scene Manager\n");
			#endif

			m_Visioner = new CVisioner;
			m_Warehouser = new CWarehouser;

			m_activeCamera = 0;
		}


		virtual ~CDirector()
		{
			#ifdef DEBUG_MODE
            printf("Destroying Scene Manager\n");
			#endif

			m_Visioner->drop();
			m_Warehouser->drop();
		}


		CMeshNode* addMeshSceneNode(CNode* parent = 0, vbcString name = "", CMesh* mesh = 0,
			vec3 position = vec3(0,0,0), vec3 rotation = vec3(0,0,0), vec3 scale = vec3(1,1,1))
		{
			CMeshNode* node;

            if (parent != 0)
                node = new CMeshNode(parent, name);
            else
                node = new CMeshNode(this, name);

			node->setMesh(mesh);
			node->setShaderID(m_Warehouser->loadShader("bus.shdr"));

			vbTransform transform;
			transform.setPosition(position);
			transform.setRotation(rotation);
			transform.setScale(scale);

			node->setTransform(transform);

			m_Visioner->registerNodeForRender(node);

			node->drop();

			return node;
		}

        CTerrainNode* addTerrainNode(CNode* parent = 0, vbcString name = "SC2 Terrain", Tile* tiles = 0)
        {
            CTerrainNode* node;

            if (parent != 0)
                node = new CTerrainNode(parent, m_Warehouser, name, tiles);
            else
                node = new CTerrainNode(this, m_Warehouser, name, tiles);

            node->setShaderID(m_Warehouser->loadShader("road.shdr"));

            vbTransform transform;
			transform.setPosition(vec3(0,0,0));
			transform.setRotation(vec3(0,0,0));
			transform.setScale(vec3(1,1,1));

			node->setTransform(transform);

			m_Visioner->registerNodeForRender(node);
			node->drop();

            return node;
        }


		CMesh* loadMesh(vbcString filename, vbcString texturePath)
		{
			// Loading mesh from 3ds file, adding Bus Node to Scene Manager and setting mesh for it
			CLoader3ds* loader3ds = new CLoader3ds(m_Warehouser);

			CMesh* mesh = loader3ds->getMesh(filename, texturePath);

			delete loader3ds;

			return mesh;
		}


		CVisioner* getVisioner()
		{
			return m_Visioner;
		}


		CWarehouser* getWarehouser()
		{
			return m_Warehouser;
		}

		void setActiveCamera(CStaticCamera* cam)
		{
		    m_activeCamera = cam;
		}

		void renderScene()
		{
            m_Visioner->renderNodes(m_activeCamera);
		}

	protected:
		CVisioner*	    m_Visioner;
        CWarehouser*    m_Warehouser;
        CStaticCamera*  m_activeCamera;
};

#endif // __CDIRECTOR_HPP__

