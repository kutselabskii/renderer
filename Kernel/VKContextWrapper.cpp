#include "VKContextWrapper.hpp"

bool Kernel::__Vulkan::ContextWrapper::TryInstantiate() {
	return false;
}

bool Kernel::__Vulkan::ContextWrapper::ShouldTerminate() {
	return true;
}

void Kernel::__Vulkan::ContextWrapper::InvokeEmptyEvent() {
}

void Kernel::__Vulkan::ContextWrapper::Update() {
}

void Kernel::__Vulkan::ContextWrapper::Discard() {
}