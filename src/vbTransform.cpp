#include "vbTransform.hpp"

vbTransform::vbTransform()
: m_Position(vec3(0,0,0)), m_Rotation(vec3(0,0,0)), m_Scale(vec3(1,1,1)), m_AbsTransform(mat4(1.0f))
{
	updateAbsTransform();
}


vbTransform::vbTransform(const vbTransform& t)
{
	m_Position = t.m_Position;
	m_Rotation = t.m_Rotation;
	m_Scale = t.m_Scale;

	updateAbsTransform();
}


vbTransform::~vbTransform()
{

}


vec3 vbTransform::getPosition()
{
	return m_Position;
}


vec3 vbTransform::getRotation()
{
	return m_Rotation;
}


vec3 vbTransform::getScale()
{
	return m_Scale;
}


mat4& vbTransform::getAbsoluteTransform()
{
	return m_AbsTransform;
}


void vbTransform::setPosition(vec3 position)
{
	m_Position = position;

	updateAbsTransform();
}


void vbTransform::setRotation(vec3 rotation)
{
	m_Rotation = rotation;

	updateAbsTransform();
}


void vbTransform::setScale(vec3 scale)
{
	m_Scale = scale;

	updateAbsTransform();
}


vbTransform& vbTransform::operator = (const vbTransform& t)
{
	m_Position = t.m_Position;
	m_Rotation = t.m_Rotation;
	m_Scale = t.m_Scale;

	updateAbsTransform();

	return *this;
}


void vbTransform::updateAbsTransform()
{
    mat4 position = glm::translate(m_Position);

	mat4 rotation = glm::rotate( m_Rotation[0], vec3(1,0,0));
	rotation *= glm::rotate( m_Rotation[1], vec3(0,1,0));
	rotation *= glm::rotate( m_Rotation[2], vec3(0,0,1));

    mat4 scale = glm::scale(m_Scale);

    m_AbsTransform = position * rotation * scale;
}

