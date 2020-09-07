#pragma once

#include "GLShader.hpp"
#include "Mesh.hpp"

namespace Kernel {
	class Object {
	public:
		Object(Kernel::__OpenGL::GLShader&, Kernel::Mesh&);

		void draw() const;
		
	protected:
		Kernel::__OpenGL::GLShader& _shader;
		Kernel::Mesh& _mesh;
	};
}