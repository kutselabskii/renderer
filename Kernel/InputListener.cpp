#include "InputListener.hpp"

std::unordered_map<Kernel::InputListener::Key, int> Kernel::InputListener::_keyBindings({
	{ Kernel::InputListener::Key::Escape, GLFW_KEY_ESCAPE },
});

std::unordered_set<int> Kernel::InputListener::_current_update_keys;
std::unordered_set<int> Kernel::InputListener::_last_update_keys;

void Kernel::InputListener::update() {
	_last_update_keys = _current_update_keys;
}

bool Kernel::InputListener::IsPressed(Key key) {
	auto iter = _keyBindings.find(key);
	return (iter != _keyBindings.end() && glfwGetKey(_window, iter->second) == GLFW_PRESS);
}

bool Kernel::InputListener::IsReleased(Key key) {
	auto iter = _keyBindings.find(key);
	return (iter != _keyBindings.end() && glfwGetKey(_window, iter->second) == GLFW_RELEASE);
}

bool Kernel::InputListener::WasPressed(Key key) {
	auto iter = _keyBindings.find(key);
	return InputListener::IsPressed(key) && _last_update_keys.find(iter->second) == _last_update_keys.end();
}

bool Kernel::InputListener::WasReleased(Key key) {
	auto iter = _keyBindings.find(key);
	return InputListener::IsReleased(key) && _last_update_keys.find(iter->second) != _last_update_keys.end();	// Doesn't work
}

void Kernel::InputListener::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch (action) {
	case GLFW_PRESS:
		_current_update_keys.insert(key);
		break;
	case GLFW_RELEASE:
		_current_update_keys.erase(key);
	}
}