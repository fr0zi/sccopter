#ifndef __VBTRANSFORM_HPP__
#define __VBTRANSFORM_HPP__

#include "Includes.hpp"

class vbTransform
{
	public:
		vbTransform();

		vbTransform(const vbTransform& t);

		virtual ~vbTransform();

		vec3 getPosition();

		vec3 getRotation();

		vec3 getScale();

		mat4& getAbsoluteTransform();

		void setPosition(vec3 position);

		void setRotation(vec3 rotation);

		void setScale(vec3 scale);

		vbTransform& operator = (const vbTransform& t);

	protected:
		vec3	m_Position;
		vec3	m_Rotation;
		vec3	m_Scale;
		mat4	m_AbsTransform;

		void updateAbsTransform();
};

#endif // __VBTRANSFORM_HPP__
