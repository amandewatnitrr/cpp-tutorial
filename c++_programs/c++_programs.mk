##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=c++_programs
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="E:/COURSES/C++ tutorials/c++ programs"
ProjectPath            :="E:/COURSES/C++ tutorials/c++ programs/c++_programs"
IntermediateDirectory  :=/COURSES/C++\ tutorials/c++\ programs"/build-$(ConfigurationName)//COURSES/C++\ tutorials/c++\ programs/c++_programs
OutDir                 :=/COURSES/C++\ tutorials/c++\ programs"/build-$(ConfigurationName)//COURSES/C++\ tutorials/c++\ programs/c++_programs
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
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
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
CXXFLAGS :=  -g -Wall -O0 $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/c++_programs/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(ObjectSuffix) 



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
../build-$(ConfigurationName)/c++_programs/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/c++_programs/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/COURSES/C++ tutorials/c++ programs/c++_programs/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/c++_programs/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/c++_programs/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/c++_programs/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/c++_programs/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/c++_programs/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(ObjectSuffix): mainwindow.cpp ../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/COURSES/C++ tutorials/c++ programs/c++_programs/mainwindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(DependSuffix): mainwindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(DependSuffix) -MM mainwindow.cpp

../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(PreprocessSuffix): mainwindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/c++_programs/mainwindow.cpp$(PreprocessSuffix) mainwindow.cpp


-include ../build-$(ConfigurationName)/c++_programs//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


