find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(INCLUDE_DIRS "")
file(GLOB childdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(child ${childdirs})
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    list(APPEND INCLUDE_DIRS ${child})
  endif()
endforeach()

file(GLOB_RECURSE RESOURCE_FILES "${PROJECT_SOURCE_DIR}/assets/*.qrc")
qt5_add_resources(ASSET_SOURCE ${RESOURCE_FILES})
file(GLOB_RECURSE DESIGNER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/forms/*.ui")
qt5_wrap_ui(FORM_SOURCES ${DESIGNER_FILES})
file(GLOB_RECURSE QOBJECT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/forms/*.hpp")
qt5_wrap_cpp(QOBJECT_SOURCES ${QOBJECT_FILES})

file(GLOB_RECURSE CXX_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.[hc]pp")

add_executable(Forge ${FORM_SOURCES} ${ASSET_SOURCE} ${QOBJECT_SOURCES} ${CXX_SOURCES})
target_link_libraries(
    Forge

    PRIVATE
        Qt5::Core
        Qt5::Widgets

        Mnemonics
        Wallet
        NodeRpcProxy
        Transfers
        Rpc
        Http
        CryptoNoteCore
        System
        Logging
        Common
        ${Boost_LIBRARIES}
)
target_include_directories(Forge PRIVATE ${INCLUDE_DIRS})
