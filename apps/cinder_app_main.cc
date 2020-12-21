#include <visualizer/game_app.h>

using game::visualizer::GameApp;

void prepareSettings(GameApp::Settings *settings) {
  settings->setResizable(true);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(GameApp, ci::app::RendererGl, prepareSettings);
