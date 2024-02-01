cmake_minimum_required(VERSION 3.16)

project(appWithIcon VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Gui Widgets Core)

qt_standard_project_setup()

qt_add_executable(appappWithIcon
    main.cpp
)


qt_add_qml_module(appappWithIcon
    URI appWithIcon
    RESOURCE_PREFIX "/"
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES avator-slicer.png siho128.png
)

set_target_properties(appappWithIcon PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appappWithIcon
    PRIVATE Qt6::Quick Qt6::Gui Qt::Core Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS appappWithIcon
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
