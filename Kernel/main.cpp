#include "Application.hpp"

int main() {
	auto app = new Kernel::Application(Kernel::RenderingBackend::OpenGL, "__OpenGL", { 1280, 600 });
	while (!app->context->ShouldTerminate()) {
		app->context->Update();
		if (app->input->IsPressed(Kernel::InputListener::Key::Escape)) app->context->Discard();
	}
	return 0; 
}