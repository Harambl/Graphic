# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Graphica_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Graphica_autogen.dir\\ParseCache.txt"
  "Graphica_autogen"
  )
endif()
