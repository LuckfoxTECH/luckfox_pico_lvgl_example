# Whether the utils lib was build.
set(CJSON_UTILS_FOUND On)

# The include directories used by cJSON
set(CJSON_INCLUDE_DIRS "/home/cro/doc/cjson/cJSON-1.7.15/install/include")
set(CJSON_INCLUDE_DIR "/home/cro/doc/cjson/cJSON-1.7.15/install/include")

get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)

# The cJSON library
set(CJSON_LIBRARY "cjson")
if(ON)
  # Include the target
  include("${_dir}/cjson.cmake")
endif()

if(CJSON_UTILS_FOUND)
  # The cJSON utils library
  set(CJSON_UTILS_LIBRARY cjson_utils)
  # All cJSON libraries
  set(CJSON_LIBRARIES "cjson_utils" "cjson")
  if(ON)
    # Include the target
    include("${_dir}/cjson_utils.cmake")
  endif()
else()
  # All cJSON libraries
  set(CJSON_LIBRARIES "cjson")
endif()
