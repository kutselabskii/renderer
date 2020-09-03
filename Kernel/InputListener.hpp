#pragma once
#include <string>
#include <unordered_set>
#include "Utils.hpp"
#include <unordered_map>
#include "ContextWrapper.hpp"

namespace Kernel {
	using namespace Utils;

	class InputListener {
	public:
		enum class Key {
			None,
			Escape,
		};

		InputListener(GLFWwindow* window) : _window(window) {
			glfwSetKeyCallback(window, key_callback);
		}
		~InputListener() = default;

		void update();

		[[nodiscard]] bool IsPressed(Key);
		[[nodiscard]] bool IsReleased(Key);
		[[nodiscard]] bool WasPressed(Key);
		[[nodiscard]] bool WasReleased(Key);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	protected:
		static std::unordered_map<Key, int> _keyBindings;
		static std::unordered_set<int> _last_update_keys;
		static std::unordered_set<int> _current_update_keys;

		GLFWwindow* _window;
	};
}