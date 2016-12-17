/********************************************************************
	Rhapsody	: 8.1.5 
	Login		: waka
	Component	: Test 
	Configuration 	: Debug
	Model Element	: Debug
//!	Generated Date	: “y, 17, 12 2016  
	File Path	: Test/Debug/MainTest.cpp
*********************************************************************/

//## auto_generated
#include "MainTest.h"
//## auto_generated
#include "TestPkg.h"
Test::Test() {
    TestPkg_initRelations();
    TestPkg_startBehavior();
}

int main(int argc, char* argv[]) {
    int status = 0;
    if(OXF::initialize(argc, argv, 6423, "waka-PC"))
        {
            Test initializer_Test;
            //#[ configuration Test::Debug 
            //#]
            OXF::start();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: Test/Debug/MainTest.cpp
*********************************************************************/
