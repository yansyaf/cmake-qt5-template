#####################################################
## PROJECT SETTING 
#####################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.9)

IF(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

PROJECT("MyQtApplication")

SET(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.0.2\\5.0.2\\msvc2010\\")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets)

SET(CMAKE_BUILD_TYPE Release)

###############################################
## OUTPUT DIRECTORY SETUP
###############################################
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/bin
	CACHE PATH
	"Single directory for all libraries"
	)
   
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/bin
	CACHE PATH
	"Single directory for all executable and dll"
	)

SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/lib
	CACHE PATH
	"Single directory for all static libraries"
	)
	
#####################################################
## CPP COMPILER
#####################################################
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})

ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

SET(MAIN_UI_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/mainui.cpp
)

SET(MAIN_UI_MOC_HDRS 
	${CMAKE_CURRENT_SOURCE_DIR}/src/mainui.h
)

ADD_EXECUTABLE(
	${PROJECT_NAME} 
	WIN32
	${MAIN_UI_SOURCES}
	${MAIN_UI_RC_SRCS}
	${MAIN_UI_MOC_SRCS}
	${WIN_RESOURCE_FILE})

QT5_USE_MODULES(${PROJECT_NAME} Widgets Sql Network Xml)	
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE_DEBUG 0)

#####################################################
## PACKAGE 
#####################################################
SET(CPACK_PACKAGE_NAME ${PROJECT_NAME})
SET(CPACK_PACKAGE_VENDOR ${PROJECT_NAME})
SET(CPACK_PACKAGE_EXECUTABLES ${PROJECT_NAME};${PROJECT_NAME})

SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "${PROJECT_NAME} 1.0.0")
SET(CPACK_PACKAGE_VERSION "1.0.0")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

IF(WIN32 AND NOT UNIX)
  SET(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\${PROJECT_NAME}.exe")
  SET(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY}${PROJECT_NAME}")
  SET(CPACK_NSIS_MODIFY_PATH ON)
ENDIF(WIN32 AND NOT UNIX)

INCLUDE(InstallRequiredSystemLibraries)

IF(WIN32)
    INSTALL(TARGETS ${PROJECT_NAME}
        DESTINATION bin
    )
	
	##THIS IS CURRENTLY HARD CODED
    INSTALL(FILES
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Core.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Gui.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Widgets.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Sql.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Network.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/Qt5Xml.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/icudt49.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/icuin49.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/icuuc49.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/libEGL.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/libGLESv2.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/bin/D3DCompiler_43.dll" 
        DESTINATION bin
    )

    INSTALL(FILES
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/plugins/platforms/qminimal.dll" 
        "C:/Qt/Qt5.0.2/5.0.2/msvc2010/plugins/platforms/qwindows.dll" 
		DESTINATION bin/platforms
	)	
	
ENDIF(WIN32)

INCLUDE(CPack)