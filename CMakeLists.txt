cmake_minimum_required(VERSION 3.16)
project(ACES VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(ACES WIN32 MACOSX_BUNDLE
    ACES.cpp ACES.h ACES.ui
    differenceItem.cpp differenceItem.h
    differenceLocations.cpp differenceLocations.h
    endForm.cpp endForm.h endForm.ui
    main.cpp
    readyForm.cpp readyForm.h readyForm.ui
    spotTheDiff.cpp spotTheDiff.h spotTheDiff.ui
)
target_link_libraries(ACES PRIVATE
    Qt::Core
    Qt::Gui
)


# Resources:
set(resources_resource_files
    "images/balloons.jpg"
    "images/balloonsDiff.jpg"
    "images/bananaBread.jpg"
    "images/bananaBreadDiff.jpg"
    "images/beach.jpg"
    "images/beachDiff.jpg"
    "images/cupcakes.jpg"
    "images/cupcakesDiff.jpg"
    "images/donut.jpg"
    "images/donutDiff.jpg"
    "images/honey.jpg"
    "images/honeyDiff.jpg"
    "images/laptop.jpg"
    "images/laptopDiff.jpg"
    "images/sushi.jpg"
    "images/sushiDiff.jpg"
    "images/twine.jpg"
    "images/twineDiff.jpg"
    "images/vegetable.jpg"
    "images/vegetableDiff.jpg"
)

qt_add_resources(ACES "resources"
    PREFIX
        "/"
    FILES
        ${resources_resource_files}
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(ACES PRIVATE
        Qt::Widgets
    )
endif()

install(TARGETS ACES
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET ACES
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
