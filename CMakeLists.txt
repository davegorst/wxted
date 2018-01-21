PROJECT (wxTED)

# For C++11 macro
CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)

MESSAGE (STATUS "Entered CMakeLists.txt")

SET (CMAKE_CXX_STANDARD 11)

IF (NOT CMAKE_BUILD_TYPE)
	SET (CMAKE_BUILD_TYPE "RelWithDebInfo")
ENDIF (NOT CMAKE_BUILD_TYPE)

#wxWidgets build related stuff
SET(WXW_USE_DEBUG ON)
SET(WXW_USE_UNICODE ON)
SET(WXW_USE_SHARED ON)
SET(WXW_USE_UNIV OFF)
SET(WXW_USE_MONO OFF)

# We need the Find package for wxWidgets to work
FIND_PACKAGE( wxWidgets COMPONENTS core base html net REQUIRED )

include( ${wxWidgets_USE_FILE} )

# Set the executable name.

SET(CurrentProject ${CMAKE_PROJECT_NAME})
SET(Executable "${CurrentProject}")
MESSAGE (STATUS "Setting executable as ${Executable}")

MESSAGE (STATUS "Linking with ${INCLUDED_LIBRARIES} and wxWidgets libraries ${wxWidgets_LIBRARIES}.")

link_libraries (
	${INCLUDED_LIBRARIES}
	${wxWidgets_LIBRARIES}
)

# Main build details.

SET(SRCS
	charchange.cpp
	HelpFrame.cpp
	mapchar.cpp
	PageSettingsDialog.cpp
	PublishSetupDialog.cpp
	tedevent.cpp
	teletext40.cpp
	ttxline.cpp
	ttxpage.cpp
	wxTEDApp.cpp
	wxTEDMain.cpp
	
	charchange.h
	hamm-tables.h
	HelpFrame.h
	mapchar.h
	PageSettingsDialog.h
	PublishSetupDialog.h
	tedevent.h
	teletext40.h
	ttxcodes.h
	ttxline.h
	ttxpage.h
	wxTEDApp.h
	wxTEDMain.h
)

ADD_EXECUTABLE(${Executable} WIN32 ${SRCS})

TARGET_LINK_LIBRARIES (
		${Executable}
		${INCLUDED_LIBRARIES}
	${wxWidgets_LIBRARIES}
)

