
#include <input/input.hpp>
#include <render/render.hpp>
#include <window/window.hpp>

// WinMain
int main(int argc, char const *argv[]) {
    window::init();
    auto window = window::createWindow(1000, 1000, "try1");
    render::init();
    auto renderer = render::CreateRenderer(window);
    auto input = input::createInputSystem();
    input->init();

    bool close = false;
    input->getEmitter()->On(
        input::kEventQuit,
        std::function([&](int i) { close = true; }));
    while (!close) {
        input->poll();
        render::ClearRender(renderer);
        render::SetDrawColor(renderer, 155, 0, 0, 255);

        render::RenderFrame(renderer);
    }
    input->terminate();
    input->shutdown();
    render::terminate(renderer);
    window::terminate(window);
    render::shutdown();
    window::shutdown();
}