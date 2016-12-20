#ifndef __CREFCOUNTER_HPP__
#define __CREFCOUNTER_HPP__

#include "Includes.hpp"


//! \brief Reference Counter class
/*!
	It counts references that other objects hold to specific object.
	This is used to automatic object deletion if it's no longer needed.
	Every new object derived from this class has reference counter equals to 1 in moment of creation.
	If reference counter reach 0, object is deleted from memory.
*/
class CRefCounter
{
	public:
		//! CONSTRUCTOR
		CRefCounter() : _refCounter(1)
		{
		    #ifdef DEBUG_MODE
               fprintf(stdout, "Creating Reference Counter\n");
            #endif
		}

		//! DESTRUCTOR
		virtual ~CRefCounter()
		{
		    #ifdef DEBUG_MODE
               fprintf(stdout, "Destroying Reference Counter\n");
            #endif
		}

		//! Grab a pointer
		/*!
			Increases object's internal reference counter.
		*/
		void grab() const
		{
			++_refCounter;
		}

		//! Drop a pointer
		/*!
			Decreases object's internal reference counter.
			If the counter equals 0 - object is deleted from memory.
		*/
		bool drop() const
		{
			--_refCounter;

			if( !_refCounter )
			{
				delete this;
				return true;
			}

			return false;
		}

		//! Get reference counter
		/*!
			Returns internal reference counter value.
		*/
		unsigned int getReferenceCount() const
		{
			return _refCounter;
		}


	private:
		//! Reference counter
		mutable unsigned int _refCounter;
};

#endif // __CREFCOUNTER_HPP__

