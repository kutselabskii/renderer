#include "InputListener.hpp"

std::unordered_map<Kernel::InputListener::Key, int> Kernel::InputListener::_keyBindings({
	{ Kernel::InputListener::Key::Escape, GLFW_KEY_ESCAPE },
});

bool Kernel::InputListener::IsPressed(Key key) {
	auto iter = _keyBindings.find(key);
	return (iter != _keyBindings.end() && glfwGetKey(_window, iter->second) == GLFW_PRESS);
}

bool Kernel::InputListener::IsReleased(Key key) {
	auto iter = _keyBindings.find(key);
	return (iter != _keyBindings.end() && glfwGetKey(_window, iter->second) == GLFW_RELEASE);
}

bool Kernel::InputListener::WasPressed(Key key) {
	return !InputListener::IsPressed(key) && _lastUpdateKey == key;
}

bool Kernel::InputListener::WasReleased(Key key) {
	return !InputListener::IsReleased(key) && _lastUpdateKey == key;
}
