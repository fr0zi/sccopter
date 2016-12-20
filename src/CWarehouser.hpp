#ifndef __CWAREHOUSER_HPP__
#define __CWAREHOUSER_HPP__



#include "Includes.hpp"
#include "CRefCounter.hpp"
#include "CTextureResource.hpp"
#include "CShaderResource.hpp"
#include "LoaderBMP.hpp"

#include <list>
#include <cstring>

typedef std::list<CResource*>	ResourceList;

class CWarehouser : virtual public CRefCounter
{
	public:
		CWarehouser(vbcString name = "Warehouser");
		virtual ~CWarehouser();

		GLuint loadTexture(vbcString filename);
		GLuint loadShader(vbcString filename);

	private:
		ResourceList	m_Resources;
		//GLuint			m_CurrentResourceID;
		vbcString		m_Name;
};

#endif // __CWAREHOUSER_HPP__
