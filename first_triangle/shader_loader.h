#pragma once

#include <GL/glcorearb.h>

namespace shaw {
    class ShaderLoader {
    private:
    public:
        /**
         * @return the compiled shader object, 0 for error
         */
        static GLuint loadFromFile(const char* file_path, const GLenum shader_type);

        static GLuint linkShaders(GLuint shader, ...);
    };
}
