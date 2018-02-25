#include "CNode.hpp"




CNode::CNode(CNode* parent, vbcString name)
	: m_Parent(parent), m_Name(name), m_IsActive(true)
{

	/* This line was couse of error - Segmentation Fault
		when it was inside 'if( parent != 0 )'
		When I moved it here - everything started to work well :)
	*/
	m_Parent = parent;

	if( parent )
		parent->addChild(this);

	#ifdef DEBUG_MODE
	std::cout << "\t -- Creating object " << m_Name << std::endl;
	#endif
}



CNode::~CNode()
{
	#ifdef DEBUG_MODE
	std::cout << "\t -- Deleting object " << m_Name << " with all its children.\n";
	#endif

    // Delete all children
	removeAll();
}



void CNode::addChild(CNode* child)
{
	if( child && (child != this) )
	{
		child->grab();
		child->remove();    // remove from old parent
		m_Children.push_back(child);
		child->m_Parent = this;
	}

	child->setIsActive(m_IsActive);


}



void CNode::setName(const vbcString name)
{
	m_Name = name;
}



vbcString CNode::getName() const
{
	return m_Name;
}


void CNode::remove()
{
	// If Entity have parent - we remove it from its parent children list
	if( m_Parent )
		m_Parent->removeChild(this);
}



bool CNode::removeChild(CNode* child)
{
    std::list<CNode *>::iterator it = m_Children.begin();

    for(; it != m_Children.end(); ++it )
        if( (*it) == child )
        {
            (*it)->m_Parent = 0;
            (*it)->drop();
            m_Children.erase(it);

            return true;
        }

    return false;
}



void CNode::removeAll()
{
	std::list<CNode *>::iterator it = m_Children.begin();

	for( ; it != m_Children.end(); ++it )
	{
		(*it)->m_Parent = 0;
		(*it)->drop();
	}

	m_Children.clear();
}



void CNode::setParent(CNode* parent)
{
	grab();
	remove();

	m_Parent = parent;


	if( parent )
	{
		m_Parent->addChild(this);

		m_IsActive = m_Parent->getIsActive();
	}

	drop();
}


CNode* CNode::getParent()
{
	return m_Parent;
}


bool CNode::hasParent()
{
	return static_cast<bool>(m_Parent);
}


bool CNode::getIsActive() const
{
    return m_IsActive;
}


void CNode::setIsActive(bool state)
{
    m_IsActive = state;

    std::list<CNode *>::iterator it = m_Children.begin();

    for( ; it != m_Children.end(); ++it )
        (*it)->setIsActive(state);
}


void CNode::render()
{

}


void CNode::setTransform(vbTransform transform)
{
	m_Transform = transform;
}


vbTransform& CNode::getTransform()
{
	return m_Transform;
}


