#include "ComponentHandler.h"

void ComponentHandler::render() {

	PushStyleColor(ImGuiCol_BorderShadow, (ImU32)ImColor::ImColor({ 251, 241, 199, 255 }));
	PushStyleColor(ImGuiCol_Border, (ImU32)ImColor::ImColor({ 251, 241, 199, 255 }));
	PushStyleColor(ImGuiCol_WindowBg, (ImU32)ImColor::ImColor({ 29, 32, 33, 245 }));
	PushStyleColor(ImGuiCol_FrameBg, (ImU32)ImColor::ImColor({ 60, 56, 54,255 }));
	PushStyleColor(ImGuiCol_FrameBgActive, (ImU32)ImColor::ImColor({ 60, 56, 54,255 }));
	PushStyleColor(ImGuiCol_FrameBgHovered, (ImU32)ImColor::ImColor({ 40, 40, 40,255 }));
	PushStyleColor(ImGuiCol_Button, (ImU32)ImColor::ImColor({ 131, 165, 152, 255}));
	PushStyleColor(ImGuiCol_ButtonHovered, (ImU32)ImColor::ImColor({ 69, 133, 136,255 }));
	PushStyleColor(ImGuiCol_ButtonActive, (ImU32)ImColor::ImColor({ 131, 165, 152,255 }));
	PushStyleColor(ImGuiCol_Text, (ImU32)ImColor::ImColor({ 249, 245, 215,255 }));
	PushStyleColor(ImGuiCol_HeaderActive, (ImU32)ImColor::ImColor({ 131, 165, 152, 255 }));
	PushStyleColor(ImGuiCol_Header, (ImU32)ImColor::ImColor({ 131, 165, 152, 255 }));
	PushStyleColor(ImGuiCol_HeaderHovered, (ImU32)ImColor::ImColor({ 69, 133, 136,255 }));
	PushStyleColor(ImGuiCol_Tab, (ImU32)ImColor::ImColor({ 60, 56, 54,255 }));
	PushStyleColor(ImGuiCol_TabActive, (ImU32)ImColor::ImColor({ 60, 56, 54,255 }));
	PushStyleColor(ImGuiCol_TabHovered, (ImU32)ImColor::ImColor({ 40, 40, 40,255 }));

	PushStyleVar(ImGuiStyleVar_FrameRounding, 5);
	PushStyleVar(ImGuiStyleVar_WindowRounding, 5);

	SetNextWindowSize({350, 1200});
	SetNextWindowPos({0,0});
	if (Begin("MainCreate", 0, flags)) {
		if (BeginTabBar(" ")) {
			if (BeginTabItem(u8"Выбор")) {
				if (CollapsingHeader(u8"Категории")) {
					for (int i = 0; i < config.getConfig()->data.categories.name.size(); i++) {
						if (TreeNode(config.getConfig()->data.categories.name[i].c_str())) {
							for (int j = 0; j < config.getConfig()->data.categories.text[i].size(); j++) {
								if (Selectable(config.getConfig()->data.categories.text[i][j].c_str())) {

								}
							}
							InputText("##inputAddText", buffer, IM_ARRAYSIZE(buffer));
							SameLine();
							if (Button(u8"+")) {
								config.getConfig()->data.categories.text[i].push_back(buffer);
								config.updateConfig();
								clearBuffer(buffer, IM_ARRAYSIZE(buffer));
							}
							SameLine();
							if (Button(u8"x")) {
								config.getConfig()->data.categories.name[i] = {};
								for (int j = 0; j < config.getConfig()->data.categories.text[i].size(); j++) {
									config.getConfig()->data.categories.text[i] = {};
								}
								config.updateConfig();
							}
							TreePop();
						}
					}
				}
				EndTabItem();
			}
			if (BeginTabItem(u8"Создание")) {
				InputText("##inputAddCategory", buffer, IM_ARRAYSIZE(buffer));
				SameLine();
				if (Button(u8"+")) {
					config.getConfig()->data.categories.name[config.getConfig()->data.categories.name.size()] = buffer;
					config.updateConfig();
					clearBuffer(buffer, IM_ARRAYSIZE(buffer));
				}
				EndTabItem();
			}
			EndTabBar();
		}
		End();
	}
	SetNextWindowSize({1700, 1200});
	SetNextWindowPos({350,0});
	if (Begin("MainRender",0,flags)) {
		if (BeginCombo(u8" ",u8"Выбор")) {
			for (int i = 0; i < config.getConfig()->data.categories.name.size(); i++) {
				if (Selectable(config.getConfig()->data.categories.name[i].c_str())) {
					id = i;
				} 
			}
			EndCombo();
		}
		if (Button(u8"Случайный выбор")) {
			if (config.getConfig()->data.categories.text[id].empty()){}
			else {
				int random = (rand() % config.getConfig()->data.categories.text[id].size());
				randomStr = config.getConfig()->data.categories.text[id][random];
			}
		}

		SetCursorPosX(725);
		SetCursorPosY(600);
		
			
		Text(randomStr.c_str());
		
		End();
	}

	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();
	PopStyleColor();

	PopStyleVar();
	PopStyleVar();
}

void ComponentHandler::clearBuffer(char buffer[],int size) {
	for (int i = 0; i < size; i++) {
		buffer[i] = {};
	}
}
