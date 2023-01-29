#pragma once
#include <config/include.h>

using namespace nlohmann;

namespace config {
	class ConfigHandler
	{
	private:
		std::string path = "src\\config.json";

		struct JsonObject {
			std::string version;
			std::string name;

			struct Data {
				struct Categories {
					std::map<unsigned int, std::string> name;
					std::map<unsigned int, std::vector<std::string>> text;
				};
				Categories categories;
			};
			Data data;
		};

		JsonObject jsonObject;

		std::ofstream ofStream;
		std::ifstream ifStream;

		void updateJsonClass();

	public:
		ConfigHandler();

		void updateConfig();

		JsonObject* getConfig();

		~ConfigHandler();
	};
}

