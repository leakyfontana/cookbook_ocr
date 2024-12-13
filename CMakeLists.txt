cmake_minimum_required(VERSION 3.10)
project(CookbookOCR)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)

pkg_check_modules(tesseract REQUIRED IMPORTED_TARGET tesseract)
pkg_check_modules(leptonica REQUIRED IMPORTED_TARGET lept)
pkg_check_moduleS(libcurl REQUIRED IMPORTED_TARGET libcurl)

set_property(TARGET PkgConfig::tesseract APPEND PROPERTY INTERFACE_LINK_LIBRARIES curl)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp src/ocr_handler.cpp)

# Link libraries
target_link_libraries(CookbookOCR PUBLIC PkgConfig::leptonica PkgConfig::tesseract -lcurl)
