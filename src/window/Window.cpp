#include <window/Window.h>

Window::Window() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE,sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
}

int Window::init() {

    ImGuiIO& io = ImGui::GetIO();
    ImGuiStyle style = ImGui::GetStyle();

    sf::Clock deltaClock;

    sf::Texture texture;
    texture.loadFromFile("image\\backgroundImage.png");
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        io.Fonts->Clear();
        io.Fonts->AddFontFromFileTTF("fonts\\Roboto-Bold.ttf",18,0,io.Fonts->GetGlyphRangesCyrillic());
        ImGui::SFML::UpdateFontTexture();
        ImGui::SFML::Update(window, deltaClock.restart());
        componentHandler.render();
        window.clear(CLEAR_COLOR);
        window.draw(sprite);
        ImGui::SFML::Render(window);
        window.display();
    }
    return 0;
}

void Window::render() {

}

Window::~Window() {
    ImGui::SFML::Shutdown();
}
