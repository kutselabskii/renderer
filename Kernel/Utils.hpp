#pragma once
#include <algorithm>

namespace Kernel {
	namespace Utils {
		struct ufloat {
			float value;

			ufloat() : value(0) {};
			ufloat(float value) : value(std::clamp(value, 0.0f, std::numeric_limits<float>::max())) {};
		};

		struct udouble {
			double value;

			udouble() : value(0) {};
			udouble(double value) : value(std::clamp(value, 0.0, std::numeric_limits<double>::max())) {};
		};

		template <typename T>
		struct Vector2 {
			T x, y;

			Vector2() : x(T), y(T) {};
			Vector2(T x, T y) : x(x), y(y) {};
		};

		template <typename T>
		struct Vector3 {
			T x, y, z;

			Vector3() : x(T), y(T), z(T) {};
			Vector3(T x, T y) : x(x), y(y), z(z) {};
		};
	}
}