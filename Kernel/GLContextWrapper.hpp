#pragma once
#include "ContextWrapper.hpp"

namespace Kernel {
	namespace __OpenGL {
		class ContextWrapper : public Kernel::ContextWrapper {
		public:
			ContextWrapper(std::string title, Vector2<int> size, EventProcessingBehavior epb, udouble timeout = 0)
				: Kernel::ContextWrapper(title, size, epb, timeout = 0) {}
			~ContextWrapper() override;

			[[nodiscard]] bool TryInstantiate() override;
			[[nodiscard]] bool ShouldTerminate() override;
			void InvokeEmptyEvent() override;
			void Update() override;
			void Discard() override;
		};
	}
}