#ifndef __CNODE_HPP__
#define __CNODE_HPP__


#include "Includes.hpp"
#include "CRefCounter.hpp"
#include "vbTransform.hpp"

#include <string>
#include <list>


//! \brief Node class
/*!
	Node represents single element on the scene.
 */
class CNode : virtual public CRefCounter
{
    public:

		//! CONSTRUCTOR
		/*!
			\param parent Parent node
			\param name Node name
		*/
		CNode(CNode* parent = 0, vbcString name = "Node");

        //! DESTRUCTOR
		virtual ~CNode();

        //! Add child node
        virtual void addChild(CNode* child);

        //! Set node's name
        virtual void setName(const vbcString name);

        //! Get node's name
        virtual vbcString getName() const;

		//! Remove node from parent node
		/*!
			This removes node from parent's children list. If node is not attached to any other node nor the Director - it will be removed from memory
			due to reference counting.
		*/
        virtual void remove();

        //! Remove node from children list
        virtual bool removeChild(CNode* child);

        //! Remove all children
        virtual void removeAll();

        //! Set parent node
        virtual void setParent(CNode* parent);

		//! Get parent node
		virtual CNode* getParent();

        //! If the node has parent
        virtual bool hasParent();

		//! Get activity flag
		virtual bool getIsActive() const;

		//! Set activity flag
		virtual void setIsActive(bool state);

		//! Render node
		virtual void render();

        //! Set node transform
        virtual void setTransform(vbTransform transform);

        //! Get node transform
		virtual vbTransform getTransform();


    protected:
        //! Pointer to parent entity
        CNode*		m_Parent;

        //! Children list
        std::list<CNode*>	m_Children;

        //! Node name
        vbcString	m_Name;

        //! Is node active
        bool m_IsActive;

        //! Node transform
        vbTransform	m_Transform;
};

#endif // __CNODE_HPP__

