#include <config/ConfigHandler.h>

config::ConfigHandler::ConfigHandler() {
	ifStream.open(path);
	std::string parseJson;

	if (!ifStream.is_open()) {
		std::cout << "Reading file is catched error" << std::endl;
	}
	else {
		std::string line;
		while (std::getline(ifStream, line)) {
			parseJson += line;
		}
	}

	ifStream.close();

	json treeObject = json::parse(parseJson);

	std::cout << treeObject << std::endl;

	jsonObject.name = treeObject["name"];
	jsonObject.version = treeObject["version"];
	std::cout << treeObject["data"]["categories"].size();

	for (int i = 0; i < treeObject["data"]["categories"].size(); i++) {
		jsonObject.data.categories.name[i] = treeObject["data"]["categories"][i]["name"];

		for (int j = 0; j < treeObject["data"]["categories"][i]["text"].size(); j++) {
			std::cout << treeObject << std::endl;
			jsonObject.data.categories.text[i].push_back(treeObject["data"]["categories"][i]["text"][j]);
		}
	}
}

void config::ConfigHandler::updateConfig() {
	json treeObject;

	treeObject["name"] = jsonObject.name;
	treeObject["version"] = jsonObject.version;

	for (int i = 0; i < jsonObject.data.categories.name.size(); i++) {
		for (int j = 0; j < jsonObject.data.categories.name[i].size(); j++) {
			treeObject["data"]["categories"][i]["name"] = jsonObject.data.categories.name[i];
		}
	}

	for (int i = 0; i < jsonObject.data.categories.text.size(); i++) {
		for (int j = 0; j < jsonObject.data.categories.text[i].size(); j++) {
			treeObject["data"]["categories"][i]["text"].push_back(jsonObject.data.categories.text[i][j]);
		}
	}

	std::cout << treeObject;

	ofStream.open(path);
	if (!ofStream.is_open()) {
		std::cout << "Writing file is catched error" << std::endl;
	}
	else {
		ofStream << treeObject;
	}
	ofStream.close();
}

config::ConfigHandler::JsonObject* config::ConfigHandler::getConfig() {
	return &jsonObject;
}
config::ConfigHandler::~ConfigHandler() {
	if (ofStream.is_open()) {
		ofStream.close();
	}
	else if (ifStream.is_open()) {
		ifStream.close();
	}
}
