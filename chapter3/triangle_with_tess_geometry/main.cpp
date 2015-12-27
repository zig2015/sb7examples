#include <stdio.h>
#include <assert.h>

#include <memory>

#include <GL/gl3w.h>

#include <sb7.h>

#include "shader_loader.h"

using namespace std;

class FirstShaderApp : public sb7::application {
private:
    GLuint m_rendering_program;
    GLuint m_vao;
public:
    virtual void startup() {
        const char* vertex_shader_path = "../chapter3/triangle_with_tess_geometry/vertex.glsl";
        const char* tessellation_control_shader_path = "../chapter3/triangle_with_tess_geometry/tessellation_control.glsl";
        const char* tessellation_evaluation_shader_path = "../chapter3/triangle_with_tess_geometry/tessellation_evaluation.glsl";
        const char* geometry_shader_path = "../chapter3/triangle_with_tess_geometry/geometry.glsl";
        const char* fragment_shader_path = "../chapter3/triangle_with_tess_geometry/fragment.glsl";
        GLuint vertex_shader = shaw::ShaderLoader::loadFromFile(vertex_shader_path, GL_VERTEX_SHADER);
        assert(vertex_shader != 0);
        GLuint tessellation_control_shader = shaw::ShaderLoader::loadFromFile(tessellation_control_shader_path, GL_TESS_CONTROL_SHADER);
        assert(tessellation_control_shader != 0);
        GLuint tessellation_evaluation_shader = shaw::ShaderLoader::loadFromFile(tessellation_evaluation_shader_path, GL_TESS_EVALUATION_SHADER);
        assert(tessellation_evaluation_shader != 0);
        GLuint geometry_shader = shaw::ShaderLoader::loadFromFile(geometry_shader_path, GL_GEOMETRY_SHADER);
        assert(geometry_shader != 0);
        GLuint fragment_shader = shaw::ShaderLoader::loadFromFile(fragment_shader_path, GL_FRAGMENT_SHADER);
        assert(fragment_shader != 0);

        GLuint program = shaw::ShaderLoader::linkShaders(vertex_shader, tessellation_control_shader, tessellation_evaluation_shader, geometry_shader, fragment_shader, 0);
        assert(program != 0);
        this->m_rendering_program = program;
        glDeleteShader(vertex_shader);
        glDeleteShader(tessellation_control_shader);
        glDeleteShader(tessellation_evaluation_shader);
        glDeleteShader(geometry_shader);
        glDeleteShader(fragment_shader);

        glGenVertexArrays(1, &this->m_vao);
        glBindVertexArray(this->m_vao);

        glPatchParameteri(GL_PATCH_VERTICES, 3);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glPointSize(5.0);

        glUseProgram(this->m_rendering_program);
    }

    virtual void render(double currentTime) {
        const GLfloat cls_color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, cls_color);

        glDrawArrays(GL_PATCHES, 0, 3);
    }
};

int main(int argc, char** argv)
{
    shared_ptr<FirstShaderApp> app = make_shared<FirstShaderApp>();
    app->run(app.get());

    return (0);
}
