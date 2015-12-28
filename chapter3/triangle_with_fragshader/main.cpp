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
        const char* vertex_shader_path = "../chapter3/triangle_with_fragshader/vertex.glsl";
        const char* fragment_shader_path = "../chapter3/triangle_with_fragshader/fragment.glsl";
        GLuint vertex_shader = shaw::ShaderLoader::loadFromFile(vertex_shader_path, GL_VERTEX_SHADER);
        assert(vertex_shader != 0);
        GLuint fragment_shader = shaw::ShaderLoader::loadFromFile(fragment_shader_path, GL_FRAGMENT_SHADER);
        assert(fragment_shader != 0);
        GLuint program = shaw::ShaderLoader::linkShaders(vertex_shader, fragment_shader, 0);
        assert(program != 0);
        this->m_rendering_program = program;
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        glGenVertexArrays(1, &this->m_vao);
        glBindVertexArray(this->m_vao);

        glUseProgram(this->m_rendering_program);
    }

    virtual void render(double currentTime) {
        const GLfloat color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, color);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};

int main(int argc, char** argv)
{
    shared_ptr<FirstShaderApp> app = make_shared<FirstShaderApp>();
    app->run(app.get());

    return (0);
}
