file(GLOB testsFolders
  ${CMAKE_SOURCE_DIR}/examples/*
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall -Wextra")

foreach(testFolder ${testsFolders})
  if(IS_DIRECTORY ${testFolder})
    get_filename_component(DIRNAME ${testFolder} NAME)
    add_library(${DIRNAME}.te SHARED ${testFolder}/extension.c)
    target_compile_options(${DIRNAME}.te PRIVATE "-DAPI_SHARED_BUILD")
    
    set_target_properties(${DIRNAME}.te PROPERTIES SUFFIX "" PREFIX "")

    add_executable(${DIRNAME} ${testFolder}/main.c)
    target_compile_options(${DIRNAME} PRIVATE "-DAPI_SHARED_USE")
    target_link_libraries(${DIRNAME} tem)
  else()
    message("Is no directory")
  endif()
endforeach()
