#include "CResource.hpp"

CResource::CResource(vbcString filename)
: m_Filename(filename)
{

}

CResource::~CResource()
{

}


vbcString CResource::getFilename()
{
	return m_Filename;
}


GLuint CResource::getID()
{
	return m_ID;
}

