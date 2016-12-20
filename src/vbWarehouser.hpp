#ifndef VBWAREHOUSER_HPP_INCLUDED
#define VBWAREHOUSER_HPP_INCLUDED

#include "Includes.hpp"
#include "CShaderResource.hpp"

#include <list>

typedef std::list<CResource*>   ResourceList;

class vbWarehouser
{
    public:
        vbWarehouser();
        ~vbWarehouser();

        CShaderResource* addShaderResource(vbcString filename);
        void             addBitmapResource(vbcString filename);
        void             addTextureResource(vbcString filename);
        void             addTextureResource(string vbBitmapResourcePointer);
        void             addMeshResource(vbcString filename);
        void             addTerrainMeshResource(vbcString BMPheightmapFilename);

    private:
        ResourceList    m_Resources;
};



#endif // VBWAREHOUSER_HPP_INCLUDED
