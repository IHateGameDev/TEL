file(GLOB testsFolders *)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

foreach(testFolder ${testFolders})
  if(IS_DIRECTORY ${testFolder})
    add_library(${testFolder}.te SHARED ${CMAKE_SOURCE_DIR}/${testFolder}/extension.c)
    target_compile_options(${testFolder}.te "-DAPI_SHARED_BUILD")

    add_executable(${testFolder} ${CMAKE_SOURCE_DIR}/${testFolder}/main.c)
    target_compile_options(${testFolder} "-DAPI_SHARED_USE")
  endif()
endforeach()
