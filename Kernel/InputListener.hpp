#pragma once
#include <string>
#include <unordered_map>
#include "Utils.hpp"
#include "ContextWrapper.hpp"

namespace Kernel {
	using namespace Utils;

	class InputListener {
	public:
		enum class Key {
			Unknown,
			Apostrophe,
			Minus,
			Period,
			Slash,
			Num0,
			Num1,
			Num2,
			Num3,
			Num4,
			Num5,
			Num6,
			Num7,
			Num8,
			Num9,
			Semicolon,
			Equal,
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			LeftBracket,
			Backslash,
			RightBracket,
			GraveAccent,
			World1,
			World2,
			Escape,
			Enter,
			Tab,
			Backspace,
			Insert,
			Delete,
			Right,
			Left,
			Down,
			Up,
			PageUp,
			PageDown,
			Home,
			End,
			CapsLock,
			ScrollLock,
			NumLock,
			PrintScreen,
			Pause,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F16,
			F17,
			F18,
			F19,
			F20,
			F21,
			F22,
			F23,
			F24,
			F25,
			Numpad0,
			Numpad1,
			Numpad2,
			Numpad3,
			Numpad4,
			Numpad5,
			Numpad6,
			Numpad7,
			Numpad8,
			Numpad9,
			NumpadDecimal,
			NumpadDivide,
			NumpadMultiply,
			NumpadSubtract,
			NumpadAdd,
			NumpadEnter,
			NumpadEqual,
			LeftShift,
			LeftControl,
			LeftAlt,
			LeftSuper,
			RightShift,
			RightControl,
			RightSuper,
		};

		InputListener(GLFWwindow* window);
		~InputListener() = default;

		void swap_buffers();

		[[nodiscard]] bool IsPressed(Key);
		[[nodiscard]] bool WasPressed(Key);
		[[nodiscard]] bool WasReleased(Key);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	protected:
		static std::unordered_map<Key, int> _keyBindings;
		static std::unordered_map<int, int> _keyStatusesBackBuffer;
		static std::unordered_map<int, int> _keyStatusesFrontBuffer;

		GLFWwindow* _window;
	};
}