#include "Object.hpp"

Kernel::Object::Object(Kernel::__OpenGL::GLShader& shader, Kernel::Mesh& mesh) : _shader(shader), _mesh(mesh) {
	
}

void Kernel::Object::draw() const {
	_shader.use();
	_mesh.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

