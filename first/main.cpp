#include <stdio.h>

#include "sb7.h"

class FirstApp : public sb7::application
{
public:
    virtual void render(double curTime) {
        const GLfloat color[] = {(float)sin(curTime) * 0.5f + 0.5f,
                                 (float)cos(curTime) * 0.5f + 0.5f,
                                 0.0f, 1.0f};
        printf("color: %lf, %lf, %f, %f\r\n", color[0], color[1], color[2], color[3]);
        glClearBufferfv(GL_COLOR, 0, color);
    }
};

int main(int argc, char* argv[])
{
    FirstApp* app = new FirstApp();
    app->run(app);
    delete app;

    return (0);
}
