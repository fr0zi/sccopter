#ifndef __CCAMERAFPS_HPP__
#define __CCAMERAFPS_HPP__

#include "CStaticCamera.hpp"

class CCameraFPS : virtual public CStaticCamera
{
	public:
		CCameraFPS(int width = 800, int height = 600, GLfloat viewAngle = 45.0f, GLfloat nearValue = 0.1f, GLfloat farValue = 1000.0f);

		virtual ~CCameraFPS();

		void update(int mousePosX, int mousePosY);

		void moveForward(double deltaTime);

		void moveBackward(double deltaTime);

		void strafeLeft(double deltaTime);

		void strafeRight(double deltaTime);

		void setMoveSpeed(float speed);

		//! Default rotation speed = 0.0005f
		void setRotationSpeed(float speed);

	protected:
		GLfloat	m_HorizontalAngle;
		GLfloat m_VerticalAngle;
		GLfloat m_MoveSpeed;
		GLfloat m_RotateSpeed;
		glm::vec3 m_Direction;
		glm::vec3 m_RightVector;

		void updateDirection();
};


#endif // __CCAMERAFPS_HPP__
