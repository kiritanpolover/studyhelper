
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug=-g
CPPCompileRelease=-O
LinkDebug=-g
LinkRelease=-O

ConfigurationCPPCompileSwitches=   -I. -I. -I$(OMROOT) -I$(OMROOT)/LangCpp -I$(OMROOT)/LangCpp/oxf $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) -DUSE_IOSTREAM $(CPPCompileDebug) -c   

#########################################
###### Predefined macros ################
RM=/bin/rm -rf
MD=/bin/mkdir -p
INCLUDE_QUALIFIER=-I
DEFINE_QUALIFIER=-D
CC=gcc -DUSE_IOSTREAM
LIB_CMD=ar
LINK_CMD=$(CC)
LIB_FLAGS=rvu
LINK_FLAGS=-lpthread -lstdc++ -lrt $(LinkDebug)  

#########################################
####### Context macros ##################

FLAGSFILE=
RULESFILE=
OMROOT="/media/sf_workspace/Share"
RHPROOT="C:/Program Files/IBM/Rational/Rhapsody/8.1.5"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=
LIB_EXT=.a

INSTRUMENTATION=Animation

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=Test

all : $(TARGET_NAME)$(EXE_EXT) Test.mak

TARGET_MAIN=MainTest

LIBS= \
  ../../AlarmCtrlLib_MSVC/Debug/AlarmCtrlLib_MSVC.lib \
  ../../HWAbsLib_MSVC/Debug/HWAbsLib_MSVC.lib \
  ../../AlarmCtrlLib_MSVC/Debug/AlarmCtrlLib_MSVC.lib \
  ../../HWAbsLib_MSVC/Debug/HWAbsLib_MSVC.lib

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/Linux \
  $(INCLUDE_QUALIFIER)../../AlarmCtrlLib_MSVC/Debug \
  $(INCLUDE_QUALIFIER)../../HWAbsLib_MSVC/Debug

ADDITIONAL_OBJS=

OBJS= \
  Hw.o \
  TestPkg.o \
  script.o \
  changeCode.o \
  Requirements.o \
  changeCode.o \
  changecode.o




#########################################
####### Predefined macros ###############
$(OBJS) :  $(INST_LIBS) $(OXF_LIBS)

OBJ_DIR=

ifeq ($(OBJ_DIR),)
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
else
CREATE_OBJ_DIR= $(MD) $(OBJ_DIR)
CLEAN_OBJ_DIR=  $(RM) $(OBJ_DIR)
endif


ifeq ($(INSTRUMENTATION),Animation)

INST_FLAGS=-DOMANIMATOR
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS= $(OMROOT)/LangCpp/lib/linuxaomanim$(LIB_EXT)
OXF_LIBS=$(OMROOT)/LangCpp/lib/linuxoxfinst$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxomcomappl$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxoxsiminst$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),Tracing)

INST_FLAGS=-DOMTRACER
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS=$(OMROOT)/LangCpp/lib/linuxtomtrace$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxaomtrace$(LIB_EXT)
OXF_LIBS= $(OMROOT)/LangCpp/lib/linuxoxfinst$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxomcomappl$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxoxsiminst$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),None)

INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(OMROOT)/LangCpp/lib/linuxoxf$(LIB_EXT) $(OMROOT)/LangCpp/lib/linuxoxsim$(LIB_EXT)
SOCK_LIB=

else
	@echo An invalid Instrumentation $(INSTRUMENTATION) is specified.
	exit
endif
endif
endif

.SUFFIXES: $(CPP_EXT)



#####################################################################
##################### Context dependencies and commands #############






Hw.o : Hw.cpp Hw.h    TestPkg.h 
	@echo Compiling Hw.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Hw.o Hw.cpp




TestPkg.o : TestPkg.cpp TestPkg.h    Hw.h 
	@echo Compiling TestPkg.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o TestPkg.o TestPkg.cpp




script.o : script.cfg.cpp     
	@echo Compiling script.cfg.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o script.o script.cfg.cpp




changeCode.o : changeCode.cfg.cpp     
	@echo Compiling changeCode.cfg.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o changeCode.o changeCode.cfg.cpp




Requirements.o : Requirements.txt.cpp     
	@echo Compiling Requirements.txt.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o Requirements.o Requirements.txt.cpp




changeCode.o : changeCode.ref.cpp     
	@echo Compiling changeCode.ref.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o changeCode.o changeCode.ref.cpp




changecode.o : changecode.log.cpp     
	@echo Compiling changecode.log.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o changecode.o changecode.log.cpp







$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
		@$(CC) $(ConfigurationCPPCompileSwitches) -o  $(TARGET_MAIN)$(OBJ_EXT) $(TARGET_MAIN)$(CPP_EXT)

####################################################################################
#                    Predefined linking instructions                               #
# INST_LIBS is included twice to solve bi-directional dependency between libraries #
####################################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) Test.mak ../../AlarmCtrlLib_MSVC/Debug/AlarmCtrlLib_MSVC.lib \
	../../HWAbsLib_MSVC/Debug/HWAbsLib_MSVC.lib
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	@$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(INST_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) Test.mak
	@echo Building library $@
	@$(LIB_CMD) $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)



clean:
	@echo Cleanup
	$(RM) Hw.o
	$(RM) TestPkg.o
	$(RM) script.o
	$(RM) changeCode.o
	$(RM) Requirements.o
	$(RM) changeCode.o
	$(RM) changecode.o
	$(RM) $(TARGET_MAIN)$(OBJ_EXT) $(ADDITIONAL_OBJS)
	$(RM) $(TARGET_NAME)$(LIB_EXT)
	$(RM) $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)
