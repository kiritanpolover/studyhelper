/*********************************************************************
	Rhapsody	: 8.1.5 
	Login		: waka
	Component	: Test 
	Configuration 	: Debug
	Model Element	: Hw
//!	Generated Date	: “y, 17, 12 2016  
	File Path	: Test/Debug/Hw.h
*********************************************************************/

#ifndef Hw_H
#define Hw_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <aom/aom.h>
//## auto_generated
#include "assert.h"
//## auto_generated
#include "TestPkg.h"
//## class Hw
#include "AbsHardware.h"
//## operation setLed(tLed,tOnOff)
#include "HardwarePkg.h"
//## package TestPkg

//## class Hw
// a test class that just writes to standard out
class Hw : public AbsHardware {
    ////    Friends    ////
  //dsfgsdfhsdf          
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedHw;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Hw();
    
    //## auto_generated
    virtual ~Hw();
    
    ////    Operations    ////
    
    //## operation setLed(tLed,tOnOff)
    virtual void setLed(const tLed& ident, const tOnOff& state);
    
    //## operation setLight(tLights,tOnOff)
    virtual void setLight(const tLights& aLight, const tOnOff& state);
    
    //## operation setSiren(tOnOff)
    virtual void setSiren(const tOnOff& state);
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedHw : public OMAnimatedAbsHardware {
    DECLARE_META(Hw, OMAnimatedHw)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: Test/Debug/Hw.h
*********************************************************************/
