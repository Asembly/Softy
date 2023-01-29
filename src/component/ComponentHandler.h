#pragma once
#include <component/include.h>

using namespace ImGui;

class ComponentHandler
{
private:
	config::ConfigHandler config;

	std::string randomStr;

	unsigned int id = 0;

	char buffer[CHAR_MAX] = "";

	ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;
	
public:
	void render();
	void clearBuffer(char buffer[],int size);
};

