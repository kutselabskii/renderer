#include "Application.hpp"

int main() {
	auto app = new Kernel::Application(Kernel::RenderingBackend::OpenGL, "__OpenGL", { 1280, 600 });
	while (!app->context->ShouldTerminate()) {
		app->context->Update();
		app->input->update();
		if (app->input->WasReleased(Kernel::InputListener::Key::Escape)) app->context->Discard();
	}
	return 0; 
}