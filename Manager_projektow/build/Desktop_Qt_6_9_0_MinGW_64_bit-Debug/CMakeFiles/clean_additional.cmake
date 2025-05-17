# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BusinessLogic\\BusinessLogic_autogen"
  "BusinessLogic\\CMakeFiles\\BusinessLogic_autogen.dir\\AutogenUsed.txt"
  "BusinessLogic\\CMakeFiles\\BusinessLogic_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\Manager_projektow_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Manager_projektow_autogen.dir\\ParseCache.txt"
  "Manager_projektow_autogen"
  )
endif()
