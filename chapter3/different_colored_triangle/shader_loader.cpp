#include "shader_loader.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <GL/gl3w.h>

#include <memory>

using namespace std;

GLuint shaw::ShaderLoader::loadFromFile(const char *file_path, const GLenum shader_type) {
    GLuint shader = 0;
    shader = glCreateShader(shader_type);
    assert(shader > 0);
    int file = open(file_path, O_RDONLY);
    assert(file > 0);

    struct stat file_stat = {0};
    int statret = fstat(file, &file_stat);
    assert(statret == 0);

    shared_ptr<char> file_buf = shared_ptr<char>((char*)calloc(1, file_stat.st_size + 1), free); // last for '\0'
    assert(file_buf);
    ssize_t bytes_read = read(file, file_buf.get(), file_stat.st_size);
    assert(bytes_read == file_stat.st_size);

    char* sources[] = {file_buf.get()};
    glShaderSource(shader, 1, sources, NULL);
    glCompileShader(shader);

    return (shader);
}

GLuint shaw::ShaderLoader::linkShaders(GLuint shader, ...) {
    GLuint program = 0;
    program = glCreateProgram();
    assert(program != 0);
    glAttachShader(program, shader);

    va_list shaderp;
    va_start(shaderp, shader);

    while (1) {
        shader = va_arg(shaderp, GLuint);
        if (shader == 0) {
            break;
        }
        glAttachShader(program, shader);
    }

    va_end(shaderp);

    glLinkProgram(program);
    return (program);
}
