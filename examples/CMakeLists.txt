file(GLOB examplesDirs
  ${CMAKE_CURRENT_LIST_DIR}/*
)

function(compileApp)
  get_filename_component(appName ${CMAKE_CURRENT_LIST_DIR} NAME)
  add_executable(${appName} ${CMAKE_CURRENT_LIST_DIR}/main.c)
  
  if(EXAMPLES_USE STREQUAL "Shared")
    target_compile_options(${appName} PRIVATE "-DAPI_SHARED_USE")
  endif()

  target_link_libraries(${appName} ${tel})

  add_subdirectory(extensions)
endfunction()

function(compileExtensions)
  file(GLOB extensionsSrc
    ${CMAKE_CURRENT_LIST_DIR}/*.c
  )

  foreach(extensionSrc ${extensionsSrc})
    get_filename_component(extensionName ${extensionSrc} NAME_WE)
    set(extensionName ${extensionName}.te)
    add_library(${extensionName} SHARED ${extensionSrc})

    target_compile_options(${extensionName} PRIVATE "-fPIC" "-DAPI_SHARED_BUILD")
    set_target_properties(${extensionName} PROPERTIES PREFIX "" SUFFIX "")
  endforeach()
endfunction()

foreach(exampleDir ${examplesDirs})
  if(IS_DIRECTORY ${exampleDir})
    add_subdirectory(${exampleDir})
  else()
    message("Is no directory")
  endif()
endforeach()
