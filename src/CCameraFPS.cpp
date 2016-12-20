#include "CCameraFPS.hpp"

CCameraFPS::CCameraFPS(int width, int height, GLfloat viewAngle, GLfloat nearValue, GLfloat farValue)
: CStaticCamera(width, height, viewAngle, nearValue, farValue),
	m_HorizontalAngle(3.14f), m_VerticalAngle(0.0f),
	m_MoveSpeed(3.0f), m_RotateSpeed(0.0005f), m_Direction(vec3(0,0,0)), m_RightVector( vec3(0,0,0))
{
	updateProjection();
	updateView();
	updateDirection();
}


CCameraFPS::~CCameraFPS()
{

}


void CCameraFPS::update(int mousePosX, int mousePosY)
{
	// Compute new orientation
	m_HorizontalAngle += m_RotateSpeed * float( m_WindowWidth/2 - mousePosX);
	m_VerticalAngle += m_RotateSpeed * float( m_WindowHeight/2 - mousePosY);

	updateDirection();

	m_RightVector = vec3(
				sin(m_HorizontalAngle - 3.14f/2.0f),
				0,
				cos(m_HorizontalAngle - 3.14f/2.0f)
	);

	m_UpVector = vec3( glm::cross(m_RightVector, m_Direction) );

	m_LookAt = m_Position + m_Direction;

	m_ViewMatrix = glm::lookAt(
						m_Position,
						m_LookAt,
						m_UpVector );
}


void CCameraFPS::updateDirection()
{
	// Direction: coordinates convertion from Spherical to Cartesian
	m_Direction = vec3(
				cos(m_VerticalAngle) * sin(m_HorizontalAngle),
				sin(m_VerticalAngle),
				cos(m_VerticalAngle) * cos(m_HorizontalAngle)
	);
}


void CCameraFPS::moveForward(double deltaTime)
{
	m_Direction *= deltaTime * m_MoveSpeed;

	m_Position += m_Direction;
}


void CCameraFPS::moveBackward(double deltaTime)
{
	m_Direction *= deltaTime * m_MoveSpeed;

	m_Position -= m_Direction;
}


void CCameraFPS::strafeLeft(double deltaTime)
{
	m_RightVector *= deltaTime * m_MoveSpeed;

	m_Position -= m_RightVector;
}


void CCameraFPS::strafeRight(double deltaTime)
{
	m_RightVector *= deltaTime * m_MoveSpeed;

	m_Position += m_RightVector;
}


void CCameraFPS::setMoveSpeed(float speed)
{
	m_MoveSpeed = speed;
}


void CCameraFPS::setRotationSpeed(float speed)
{
	m_RotateSpeed = speed;
}

