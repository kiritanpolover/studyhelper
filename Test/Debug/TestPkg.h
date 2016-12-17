/*********************************************************************
	Rhapsody	: 8.1.5 
	Login		: waka
	Component	: Test 
	Configuration 	: Debug
	Model Element	: TestPkg
//!	Generated Date	: “y, 17, 12 2016  
	File Path	: Test/Debug/TestPkg.h
*********************************************************************/

#ifndef TestPkg_H
#define TestPkg_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <aom/aom.h>
//## auto_generated
#include "assert.h"
//## classInstance theAlarmCtrl
class AlarmController;

//## auto_generated
class Hw;

//## package TestPkg


//## classInstance theAlarmCtrl
extern AlarmController theAlarmCtrl;

//## classInstance theHW
extern Hw theHW;

//## auto_generated
void TestPkg_initRelations();

//## auto_generated
bool TestPkg_startBehavior();

//#[ ignore
class TestPkg_OMInitializer {
    ////    Constructors and destructors    ////
    
public :

    //## auto_generated
    TestPkg_OMInitializer();
    
    //## auto_generated
    ~TestPkg_OMInitializer();
};
//#]

#endif
/*********************************************************************
	File Path	: Test/Debug/TestPkg.h
*********************************************************************/
