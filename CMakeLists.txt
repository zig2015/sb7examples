project(sb7exercise)
cmake_minimum_required(VERSION 2.8)
add_definitions(-D__gl_h_ -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -D_DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework CoreFoundation")
# first app
set(FIRST_APP_SRC first_app/main.cpp)
add_executable(first_app ${FIRST_APP_SRC})
target_link_libraries(first_app -lsb7 -lglfw3 -lgl3w)
# first shader
set(FIRST_SHADER_SRC first_shader/shader_loader.cpp first_shader/main.cpp)
add_executable(first_shader ${FIRST_SHADER_SRC})
target_link_libraries(first_shader -lsb7 -lglfw3 -lgl3w)
# first triangle
set(FIRST_TRIANGLE_SRC first_triangle/shader_loader.cpp first_triangle/main.cpp)
add_executable(first_triangle ${FIRST_TRIANGLE_SRC})
target_link_libraries(first_triangle -lsb7 -lglfw3 -lgl3w)
