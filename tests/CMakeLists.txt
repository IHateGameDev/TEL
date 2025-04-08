file(GLOB testsFolders
  ${CMAKE_SOURCE_DIR}/tests/*
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

foreach(testFolder ${testsFolders})
  if(IS_DIRECTORY ${testFolder})
    get_filename_component(DIRNAME ${testFolder} NAME)
    add_library(${DIRNAME}.te SHARED ${testFolder}/extension.c)
    target_compile_options(${DIRNAME}.te PRIVATE "-DAPI_SHARED_BUILD")

    add_executable(${DIRNAME} ${testFolder}/main.c)
    target_compile_options(${DIRNAME} PRIVATE "-DAPI_SHARED_USE")
    target_link_libraries(${DIRNAME} tem)
  else()
    message("Is no directory")
  endif()
endforeach()
