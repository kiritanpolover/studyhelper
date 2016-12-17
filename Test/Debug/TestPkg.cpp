/********************************************************************
	Rhapsody	: 8.1.5 
	Login		: waka
	Component	: Test 
	Configuration 	: Debug
	Model Element	: TestPkg
//!	Generated Date	: “y, 17, 12 2016  
	File Path	: Test/Debug/TestPkg.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "TestPkg.h"
//## classInstance theAlarmCtrl
#include "AlarmController.h"
//## classInstance theHW
#include "Hw.h"
//## package TestPkg


//## classInstance theAlarmCtrl
AlarmController theAlarmCtrl;

//## classInstance theHW
Hw theHW;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(TestPkg, TestPkg)
#endif // _OMINSTRUMENT

void TestPkg_initRelations() {
    {
        {
            theAlarmCtrl.setShouldDelete(false);
        }
    }
    {
        
        theAlarmCtrl.get_hwCtrl()->setItsILedCtrl(theHW.get_ctrl()->getItsILedCtrl());
        
        theAlarmCtrl.get_hwCtrl()->setItsILightCtrl(theHW.get_ctrl()->getItsILightCtrl());
        
        theAlarmCtrl.get_hwCtrl()->setItsISirenCtrl(theHW.get_ctrl()->getItsISirenCtrl());
        
    }
    {
        
        theHW.get_ctrl()->setItsIKeyListener(theAlarmCtrl.get_hwObserver()->getItsIKeyListener());
        
        theHW.get_ctrl()->setItsIMovementListener(theAlarmCtrl.get_hwObserver()->getItsIMovementListener());
        
        theHW.get_ctrl()->setItsIDoorListener(theAlarmCtrl.get_hwObserver()->getItsIDoorListener());
        
    }
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool TestPkg_startBehavior() {
    bool done = true;
    done &= theAlarmCtrl.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&theAlarmCtrl, AlarmController, "theAlarmCtrl", AOMNoMultiplicity);
    OM_SET_INSTANCE_NAME(&theHW, Hw, "theHW", AOMNoMultiplicity);
}
#endif // _OMINSTRUMENT

//#[ ignore
TestPkg_OMInitializer::TestPkg_OMInitializer() {
    TestPkg_initRelations();
    TestPkg_startBehavior();
}

TestPkg_OMInitializer::~TestPkg_OMInitializer() {
}
//#]

/*********************************************************************
	File Path	: Test/Debug/TestPkg.cpp
*********************************************************************/
