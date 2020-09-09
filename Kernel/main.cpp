#include "Application.hpp"

// Guess I'm doing it wrong
#include "GLShader.hpp"
#include "Mesh.hpp"
#include "vertices.hpp"
#include "Object.hpp"

int main() {
	auto app = new Kernel::Application(Kernel::RenderingBackend::OpenGL, "__OpenGL", { 1280, 600 });
	
	Kernel::__OpenGL::GLShader shader("Default.vert", "Default.frag");
	Kernel::Mesh mesh(Kernel::VerticesTemplates::triangle_vertices, sizeof(Kernel::VerticesTemplates::triangle_vertices));
	const Kernel::Object triangle(shader, mesh);

	while (!app->context->ShouldTerminate()) {
		app->context->preDraw();
		
		triangle.draw();
		
		app->input->swap_buffers();
		app->context->Update();
		
		if (app->input->WasReleased(Kernel::InputListener::Key::Escape)) app->context->Discard();
	}
	return 0; 
}
