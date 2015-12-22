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
        // book's code
//        static const GLchar* vertex_shader_source[] = {
//                "#version 410 core                          \n"
//                "                                           \n"
//                "void main(void)                            \n"
//                "{                                          \n"
//                "   gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n"
//                "}                                          \n"
//        };
//        static const GLchar* fragment_shader_source[] = {
//                "#version 410 core                          \n"
//                "                                           \n"
//                "out vec4 color;                            \n"
//                "void main(void)                            \n"
//                "{                                          \n"
//                "   color = vec4(0.0, 0.8, 1.0, 1.0);       \n"
//                "}                                          \n"
//        };
//        GLuint vertex_shader;
//        GLuint fragment_shader;
//        GLuint program;
//        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
//        glCompileShader(vertex_shader);
//
//        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
//        glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
//        glCompileShader(fragment_shader);
//
//        program = glCreateProgram();
//        glAttachShader(program, vertex_shader);
//        glAttachShader(program, fragment_shader);
//        glLinkProgram(program);
        const char* vertex_shader_path = "../chapter2/first_shader/vertex.glsl";
        const char* fragment_shader_path = "../chapter2/first_shader/fragment.glsl";
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

        glPointSize(40.0f);
        glUseProgram(this->m_rendering_program);
    }

    virtual void render(double currentTime) {
        const GLfloat color[] = {(float)sin(currentTime)*0.5f+0.5f,
                                 (float)cos(currentTime)*0.5f+0.5f,
                                 0.0f, 1.0f};
        // const GLfloat color[] = {1.0f, 1.0f, 1.0f, 1.0f};
        glClearBufferfv(GL_COLOR, 0, color);

        glDrawArrays(GL_POINTS, 0, 1);
    }
};

int main(int argc, char** argv)
{
    shared_ptr<FirstShaderApp> app = make_shared<FirstShaderApp>();
    app->run(app.get());

    return (0);
}
