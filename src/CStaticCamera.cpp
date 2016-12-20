#include "CStaticCamera.hpp"


CStaticCamera::CStaticCamera(int width, int height, GLfloat viewAngle, GLfloat nearValue, GLfloat farValue)
	: m_WindowWidth(width), m_WindowHeight(height), m_ViewAngle(viewAngle), m_NearValue(nearValue), m_FarValue(farValue),
	m_Position(vec3(0,0,-10)), m_LookAt(vec3(0,0,0)), m_UpVector(vec3(0,1,0)),
	m_ProjectionMatrix(1.0), m_ViewMatrix(1.0)
{
	updateProjection();
	updateView();
}


CStaticCamera::~CStaticCamera()
{

}


vec3 CStaticCamera::getPosition()
{
	return m_Position;
}


GLfloat CStaticCamera::getNearValue()
{
	return m_NearValue;
}


GLfloat	CStaticCamera::getFarValue()
{
	return m_FarValue;
}


glm::vec3 CStaticCamera::getLookAtVector()
{
	return m_LookAt;
}

glm::vec3 CStaticCamera::getUpVector()
{
	return m_UpVector;
}


glm::mat4 CStaticCamera::getProjectionMatrix()
{
	return m_ProjectionMatrix;
}


glm::mat4 CStaticCamera::getViewMatrix()
{
	return m_ViewMatrix;
}


void CStaticCamera::setPosition(vec3 position)
{
	m_Position = position;

	updateView();
}


void CStaticCamera::setPosition(GLfloat x, GLfloat y, GLfloat z)
{
	vec3 pos(x, y, z);

	setPosition(pos);
}


void CStaticCamera::lookAt(vec3 lookAt)
{
	m_LookAt = lookAt;

	updateView();
}


void CStaticCamera::setUpVector(vec3 upVector)
{
	m_UpVector = upVector;
	
	updateView();
}


void CStaticCamera::setFarValue(GLfloat value)
{
	m_FarValue = value;

	updateProjection();
}


void CStaticCamera::setNearValue(GLfloat value)
{
	m_NearValue = value;

	updateProjection();
}


void CStaticCamera::setViewAngle(GLfloat angle)
{
	m_ViewAngle = angle;

	updateProjection();
}


void CStaticCamera::setWindowDimensions(GLint width, GLint height)
{
	m_WindowWidth = width;
	m_WindowHeight = height;

	updateProjection();
}


void CStaticCamera::updateProjection()
{
	m_ProjectionMatrix = glm::perspective(m_ViewAngle, float(m_WindowWidth) / float(m_WindowHeight), m_NearValue, m_FarValue);
}


void CStaticCamera::updateView()
{
	m_ViewMatrix = glm::lookAt(
						m_Position,
						m_LookAt,
						m_UpVector );
}

