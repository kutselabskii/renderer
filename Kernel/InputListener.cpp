#include "InputListener.hpp"

std::unordered_map<Kernel::InputListener::Key, int> Kernel::InputListener::_keyBindings({
	{ Kernel::InputListener::Key::Unknown,			GLFW_KEY_UNKNOWN	   },
	{ Kernel::InputListener::Key::Apostrophe,		GLFW_KEY_APOSTROPHE	   },
	{ Kernel::InputListener::Key::Minus,			GLFW_KEY_MINUS		   },
	{ Kernel::InputListener::Key::Period,			GLFW_KEY_PERIOD		   },
	{ Kernel::InputListener::Key::Slash,			GLFW_KEY_SLASH		   },
	{ Kernel::InputListener::Key::Num0,				GLFW_KEY_0			   },
	{ Kernel::InputListener::Key::Num1,				GLFW_KEY_1			   },
	{ Kernel::InputListener::Key::Num2,				GLFW_KEY_2			   },
	{ Kernel::InputListener::Key::Num3,				GLFW_KEY_3			   },
	{ Kernel::InputListener::Key::Num4,				GLFW_KEY_4			   },
	{ Kernel::InputListener::Key::Num5,				GLFW_KEY_5			   },
	{ Kernel::InputListener::Key::Num6,				GLFW_KEY_6			   },
	{ Kernel::InputListener::Key::Num7,				GLFW_KEY_7			   },
	{ Kernel::InputListener::Key::Num8,				GLFW_KEY_8			   },
	{ Kernel::InputListener::Key::Num9,				GLFW_KEY_9			   },
	{ Kernel::InputListener::Key::Semicolon,		GLFW_KEY_SEMICOLON	   },
	{ Kernel::InputListener::Key::Equal,			GLFW_KEY_EQUAL		   },
	{ Kernel::InputListener::Key::A,				GLFW_KEY_A			   },
	{ Kernel::InputListener::Key::B,				GLFW_KEY_B			   },
	{ Kernel::InputListener::Key::C,				GLFW_KEY_C			   },
	{ Kernel::InputListener::Key::D,				GLFW_KEY_D			   },
	{ Kernel::InputListener::Key::E,				GLFW_KEY_E			   },
	{ Kernel::InputListener::Key::F,				GLFW_KEY_F			   },
	{ Kernel::InputListener::Key::G,				GLFW_KEY_G			   },
	{ Kernel::InputListener::Key::H,				GLFW_KEY_H			   },
	{ Kernel::InputListener::Key::I,				GLFW_KEY_I			   },
	{ Kernel::InputListener::Key::J,				GLFW_KEY_J			   },
	{ Kernel::InputListener::Key::K,				GLFW_KEY_K			   },
	{ Kernel::InputListener::Key::L,				GLFW_KEY_L			   },
	{ Kernel::InputListener::Key::M,				GLFW_KEY_M			   },
	{ Kernel::InputListener::Key::N,				GLFW_KEY_N			   },
	{ Kernel::InputListener::Key::O,				GLFW_KEY_O			   },
	{ Kernel::InputListener::Key::P,				GLFW_KEY_P			   },
	{ Kernel::InputListener::Key::Q,				GLFW_KEY_Q			   },
	{ Kernel::InputListener::Key::R,				GLFW_KEY_R			   },
	{ Kernel::InputListener::Key::S,				GLFW_KEY_S			   },
	{ Kernel::InputListener::Key::T,				GLFW_KEY_T			   },
	{ Kernel::InputListener::Key::U,				GLFW_KEY_U			   },
	{ Kernel::InputListener::Key::V,				GLFW_KEY_V			   },
	{ Kernel::InputListener::Key::W,				GLFW_KEY_W			   },
	{ Kernel::InputListener::Key::X,				GLFW_KEY_X			   },
	{ Kernel::InputListener::Key::Y,				GLFW_KEY_Y			   },
	{ Kernel::InputListener::Key::Z,				GLFW_KEY_Z			   },
	{ Kernel::InputListener::Key::LeftBracket,		GLFW_KEY_LEFT_BRACKET  },
	{ Kernel::InputListener::Key::Backslash,		GLFW_KEY_BACKSLASH	   },
	{ Kernel::InputListener::Key::RightBracket,		GLFW_KEY_RIGHT_BRACKET },
	{ Kernel::InputListener::Key::GraveAccent,		GLFW_KEY_GRAVE_ACCENT  },
	{ Kernel::InputListener::Key::World1,			GLFW_KEY_WORLD_1	   },
	{ Kernel::InputListener::Key::World2,			GLFW_KEY_WORLD_2	   },
	{ Kernel::InputListener::Key::Escape,			GLFW_KEY_ESCAPE		   },
	{ Kernel::InputListener::Key::Enter,			GLFW_KEY_ENTER		   },
	{ Kernel::InputListener::Key::Tab,				GLFW_KEY_TAB		   },
	{ Kernel::InputListener::Key::Backspace,		GLFW_KEY_BACKSPACE	   },
	{ Kernel::InputListener::Key::Insert,			GLFW_KEY_INSERT		   },
	{ Kernel::InputListener::Key::Delete,			GLFW_KEY_DELETE		   },
	{ Kernel::InputListener::Key::Right,			GLFW_KEY_RIGHT		   },
	{ Kernel::InputListener::Key::Left,				GLFW_KEY_LEFT		   },
	{ Kernel::InputListener::Key::Down,				GLFW_KEY_DOWN		   },
	{ Kernel::InputListener::Key::Up,				GLFW_KEY_UP			   },
	{ Kernel::InputListener::Key::PageUp,			GLFW_KEY_PAGE_UP	   },
	{ Kernel::InputListener::Key::PageDown,			GLFW_KEY_PAGE_DOWN	   },
	{ Kernel::InputListener::Key::Home,				GLFW_KEY_HOME		   },
	{ Kernel::InputListener::Key::End,				GLFW_KEY_END		   },
	{ Kernel::InputListener::Key::CapsLock,			GLFW_KEY_CAPS_LOCK	   },
	{ Kernel::InputListener::Key::ScrollLock,		GLFW_KEY_SCROLL_LOCK   },
	{ Kernel::InputListener::Key::NumLock,			GLFW_KEY_NUM_LOCK	   },
	{ Kernel::InputListener::Key::PrintScreen,		GLFW_KEY_PRINT_SCREEN  },
	{ Kernel::InputListener::Key::Pause,			GLFW_KEY_PAUSE		   },
	{ Kernel::InputListener::Key::F1,				GLFW_KEY_F1			   },
	{ Kernel::InputListener::Key::F2,				GLFW_KEY_F2			   },
	{ Kernel::InputListener::Key::F3,				GLFW_KEY_F3			   },
	{ Kernel::InputListener::Key::F4,				GLFW_KEY_F4			   },
	{ Kernel::InputListener::Key::F5,				GLFW_KEY_F5			   },
	{ Kernel::InputListener::Key::F6,				GLFW_KEY_F6			   },
	{ Kernel::InputListener::Key::F7,				GLFW_KEY_F7			   },
	{ Kernel::InputListener::Key::F8,				GLFW_KEY_F8			   },
	{ Kernel::InputListener::Key::F9,				GLFW_KEY_F9			   },
	{ Kernel::InputListener::Key::F10,				GLFW_KEY_F10		   },
	{ Kernel::InputListener::Key::F11,				GLFW_KEY_F11		   },
	{ Kernel::InputListener::Key::F12,				GLFW_KEY_F12		   },
	{ Kernel::InputListener::Key::F13,				GLFW_KEY_F13		   },
	{ Kernel::InputListener::Key::F14,				GLFW_KEY_F14		   },
	{ Kernel::InputListener::Key::F16,				GLFW_KEY_F16		   },
	{ Kernel::InputListener::Key::F17,				GLFW_KEY_F17		   },
	{ Kernel::InputListener::Key::F18,				GLFW_KEY_F18		   },
	{ Kernel::InputListener::Key::F19,				GLFW_KEY_F19		   },
	{ Kernel::InputListener::Key::F20,				GLFW_KEY_F20		   },
	{ Kernel::InputListener::Key::F21,				GLFW_KEY_F21		   },
	{ Kernel::InputListener::Key::F22,				GLFW_KEY_F22		   },
	{ Kernel::InputListener::Key::F23,				GLFW_KEY_F23		   },
	{ Kernel::InputListener::Key::F24,				GLFW_KEY_F24		   },
	{ Kernel::InputListener::Key::F25,				GLFW_KEY_F25		   },
	{ Kernel::InputListener::Key::Numpad0,			GLFW_KEY_KP_0		   },
	{ Kernel::InputListener::Key::Numpad1,			GLFW_KEY_KP_1		   },
	{ Kernel::InputListener::Key::Numpad2,			GLFW_KEY_KP_2		   },
	{ Kernel::InputListener::Key::Numpad3,			GLFW_KEY_KP_3		   },
	{ Kernel::InputListener::Key::Numpad4,			GLFW_KEY_KP_4		   },
	{ Kernel::InputListener::Key::Numpad5,			GLFW_KEY_KP_5		   },
	{ Kernel::InputListener::Key::Numpad6,			GLFW_KEY_KP_6		   },
	{ Kernel::InputListener::Key::Numpad7,			GLFW_KEY_KP_7		   },
	{ Kernel::InputListener::Key::Numpad8,			GLFW_KEY_KP_8		   },
	{ Kernel::InputListener::Key::Numpad9,			GLFW_KEY_KP_9		   },
	{ Kernel::InputListener::Key::NumpadDecimal,	GLFW_KEY_KP_DECIMAL	   },
	{ Kernel::InputListener::Key::NumpadDivide,		GLFW_KEY_KP_DIVIDE	   },
	{ Kernel::InputListener::Key::NumpadMultiply,	GLFW_KEY_KP_MULTIPLY   },
	{ Kernel::InputListener::Key::NumpadSubtract,	GLFW_KEY_KP_SUBTRACT   },
	{ Kernel::InputListener::Key::NumpadAdd,		GLFW_KEY_KP_ADD		   },
	{ Kernel::InputListener::Key::NumpadEnter,		GLFW_KEY_KP_ENTER	   },
	{ Kernel::InputListener::Key::NumpadEqual,		GLFW_KEY_KP_EQUAL	   },
	{ Kernel::InputListener::Key::LeftShift,		GLFW_KEY_LEFT_SHIFT	   },
	{ Kernel::InputListener::Key::LeftControl,		GLFW_KEY_LEFT_CONTROL  },
	{ Kernel::InputListener::Key::LeftAlt,			GLFW_KEY_LEFT_ALT	   },
	{ Kernel::InputListener::Key::LeftSuper,		GLFW_KEY_LEFT_SUPER	   },
	{ Kernel::InputListener::Key::RightShift,		GLFW_KEY_RIGHT_SHIFT   },
	{ Kernel::InputListener::Key::RightControl,		GLFW_KEY_RIGHT_CONTROL },
	{ Kernel::InputListener::Key::RightSuper,		GLFW_KEY_RIGHT_SUPER   },
});

std::unordered_map<int, int> Kernel::InputListener::_keyStatusesBackBuffer{};
std::unordered_map<int, int> Kernel::InputListener::_keyStatusesFrontBuffer{};

Kernel::InputListener::InputListener(GLFWwindow* window) : _window(window) {
	glfwSetKeyCallback(window, key_callback);
};

void Kernel::InputListener::swap_buffers() {
	_keyStatusesBackBuffer = _keyStatusesFrontBuffer;
	for (auto& i : _keyStatusesFrontBuffer)
		if (i.second == GLFW_RELEASE || i.second == GLFW_PRESS)
			i.second = -1;
}

bool Kernel::InputListener::IsPressed(Key key) {
	auto iter = _keyBindings.find(key);
	if (iter == _keyBindings.end()) return false;
	auto status = _keyStatusesFrontBuffer.find(iter->second);
	if (status == _keyStatusesFrontBuffer.end()) return false;
	return _keyStatusesFrontBuffer[iter->second] == GLFW_REPEAT;
}

bool Kernel::InputListener::WasPressed(Key key) {
	auto iter = _keyBindings.find(key);
	if (iter == _keyBindings.end()) return false;
	auto status = _keyStatusesBackBuffer.find(iter->second);
	if (status == _keyStatusesBackBuffer.end()) return false;
	return _keyStatusesBackBuffer[iter->second] == GLFW_PRESS;
}

bool Kernel::InputListener::WasReleased(Key key) {
	auto iter = _keyBindings.find(key);
	if (iter == _keyBindings.end()) return false;
	auto status = _keyStatusesBackBuffer.find(iter->second);
	if (status == _keyStatusesBackBuffer.end()) return false;
	return _keyStatusesBackBuffer[iter->second] == GLFW_RELEASE;
}

void Kernel::InputListener::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	_keyStatusesFrontBuffer[key] = action;
}
