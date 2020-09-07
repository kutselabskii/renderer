#pragma once
#include <glad/glad.h>

namespace Kernel {
	class Mesh {
	public:
		Mesh(float* vertices);

		void bind();

	protected:
		unsigned int _vao, _vbo;
	};
}
