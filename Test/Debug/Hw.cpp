/********************************************************************
	Rhapsody	: 8.1.5 
	Login		: waka
	Component	: Test 
	Configuration 	: Debug
	Model Element	: Hw
//!	Generated Date	: “y, 17, 12 2016  
	File Path	: Test/Debug/Hw.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Hw.h"
//#[ ignore
#define TestPkg_Hw_Hw_SERIALIZE OM_NO_OP

#define TestPkg_Hw_setLed_SERIALIZE OM_NO_OP

#define TestPkg_Hw_setLight_SERIALIZE OM_NO_OP

#define TestPkg_Hw_setSiren_SERIALIZE OM_NO_OP
//#]

//## package TestPkg

//## class Hw
Hw::Hw() {
    NOTIFY_CONSTRUCTOR(Hw, Hw(), 0, TestPkg_Hw_Hw_SERIALIZE);
}

Hw::~Hw() {
    NOTIFY_DESTRUCTOR(~Hw, false);
}

void Hw::setLed(const tLed& ident, const tOnOff& state) {
    NOTIFY_OPERATION(setLed, setLed(const tLed&,const tOnOff&), 0, TestPkg_Hw_setLed_SERIALIZE);
    //#[ operation setLed(tLed,tOnOff)
    if ( ident == RED )
    	printf("red ");
    else
    	printf("green ");
    
    if ( state == ON )
    	printf("on\n");
    else
    	printf("off\n");
    
    //#]
}

void Hw::setLight(const tLights& aLight, const tOnOff& state) {
    NOTIFY_OPERATION(setLight, setLight(const tLights&,const tOnOff&), 0, TestPkg_Hw_setLight_SERIALIZE);
    //#[ operation setLight(tLights,tOnOff)
    printf("light %d", aLight);
    if ( state == ON )
    	printf("on\n");
    else
    	printf("off\n");
    
    //#]
}

void Hw::setSiren(const tOnOff& state) {
    NOTIFY_OPERATION(setSiren, setSiren(const tOnOff&), 0, TestPkg_Hw_setSiren_SERIALIZE);
    //#[ operation setSiren(tOnOff)
    if ( state == ON ) 
    	printf("siren on\n");
    else
    	printf("siren off\n");
    
    //#]
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedHw::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    OMAnimatedAbsHardware::serializeAttributes(aomsAttributes);
}

void OMAnimatedHw::serializeRelations(AOMSRelations* aomsRelations) const {
    OMAnimatedAbsHardware::serializeRelations(aomsRelations);
}
//#]

IMPLEMENT_META_S_P(Hw, TestPkg, false, AbsHardware, OMAnimatedAbsHardware, OMAnimatedHw)

OMINIT_SUPERCLASS(AbsHardware, OMAnimatedAbsHardware)

OMREGISTER_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: Test/Debug/Hw.cpp
*********************************************************************/
