# Compatibility
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# Project name
PROJECT (sp-tests)

GET_FILENAME_COMPONENT(RESULT "./bin" ABSOLUTE)
SET(BIN_PATH ${RESULT} CACHE INTERNAL "Directory for the binaries" FORCE)

ADD_SUBDIRECTORY("${PROJECT_SOURCE_DIR}/general" general)
ADD_SUBDIRECTORY("${PROJECT_SOURCE_DIR}/memory" memory)
