#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Kernel::__OpenGL {
    class GLShader {
    public:
        unsigned int id;

        GLShader(const char* vertex_path, const char* fragment_path);

        void use() const;

        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;

    private:
        static void checkCompileErrors(unsigned int shader, const std::string& type);
    };
}

