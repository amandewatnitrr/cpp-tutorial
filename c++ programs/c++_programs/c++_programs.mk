##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=c++_programs
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="E:/COURSES/C++ tutorials/c++ programs/c++ programs"
ProjectPath            :="E:/COURSES/C++ tutorials/c++ programs/c++ programs/c++_programs"
IntermediateDirectory  :=/COURSES/C++\ tutorials/c++\ programs/c++\ programs"/build-$(ConfigurationName)//COURSES/C++\ tutorials/c++\ programs/c++\ programs/c++_programs
OutDir                 :=/COURSES/C++\ tutorials/c++\ programs/c++\ programs"/build-$(ConfigurationName)//COURSES/C++\ tutorials/c++\ programs/c++\ programs/c++_programs
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Aman Kumar Dewangan
Date                   :=13/12/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/c++_programs/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/c++_programs/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\c++_programs" mkdir "..\build-$(ConfigurationName)\c++_programs"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\c++_programs" mkdir "..\build-$(ConfigurationName)\c++_programs"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/c++_programs/.d:
	@if not exist "..\build-$(ConfigurationName)\c++_programs" mkdir "..\build-$(ConfigurationName)\c++_programs"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/c++_programs/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/c++_programs/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/COURSES/C++ tutorials/c++ programs/c++ programs/c++_programs/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/c++_programs/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/c++_programs/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/c++_programs/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/c++_programs/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/c++_programs/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/c++_programs//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


