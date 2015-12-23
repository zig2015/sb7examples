project(sb7exercise)
cmake_minimum_required(VERSION 2.8)
add_definitions(-D__gl_h_ -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -D_DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework CoreFoundation")
# chapter2
## first app
set(FIRST_APP_SRC chapter2/first_app/main.cpp)
add_executable(first_app ${FIRST_APP_SRC})
target_link_libraries(first_app -lsb7 -lglfw3 -lgl3w)
## first shader
set(FIRST_SHADER_SRC chapter2/first_shader/shader_loader.cpp chapter2/first_shader/main.cpp)
add_executable(first_shader ${FIRST_SHADER_SRC})
target_link_libraries(first_shader -lsb7 -lglfw3 -lgl3w)
## first triangle
set(FIRST_TRIANGLE_SRC chapter2/first_triangle/shader_loader.cpp chapter2/first_triangle/main.cpp)
add_executable(first_triangle ${FIRST_TRIANGLE_SRC})
target_link_libraries(first_triangle -lsb7 -lglfw3 -lgl3w)

# chapter3
## update vertex attribute
set(UPDATE_VERTEX_ATTRIBUTE_SRC chapter3/update_vertex_attribute/shader_loader.cpp chapter3/update_vertex_attribute/main.cpp)
add_executable(update_vertex_attribute ${UPDATE_VERTEX_ATTRIBUTE_SRC})
target_link_libraries(update_vertex_attribute -lsb7 -lglfw3 -lgl3w)
## different colored triangle
set(DIFFERENT_COLORED_TRIANGLE_SRC chapter3/different_colored_triangle/shader_loader.cpp chapter3/different_colored_triangle/main.cpp)
add_executable(different_colored_triangle ${DIFFERENT_COLORED_TRIANGLE_SRC})
target_link_libraries(different_colored_triangle -lsb7 -lglfw3 -lgl3w)
## interface block triangle
set(INTERFACE_BLOCK_TRIANGLE_SRC chapter3/interface_block_triangle/shader_loader.cpp chapter3/interface_block_triangle/main.cpp)
add_executable(interface_block_triangle ${INTERFACE_BLOCK_TRIANGLE_SRC})
target_link_libraries(interface_block_triangle -lsb7 -lglfw3 -lgl3w)
