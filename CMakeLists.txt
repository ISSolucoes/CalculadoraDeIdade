cmake_minimum_required(VERSION 3.16)

project(MinhaIdadeDetalhada2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appMinhaIdadeDetalhada2
    main.cpp utilitarios.cpp utilitarios.h
)

qt_add_qml_module(appMinhaIdadeDetalhada2
    URI MinhaIdadeDetalhada2
    VERSION 1.0
    QML_FILES main.qml PageIdade.qml
)

set_target_properties(appMinhaIdadeDetalhada2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMinhaIdadeDetalhada2
    PRIVATE Qt6::Quick)

install(TARGETS appMinhaIdadeDetalhada2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
