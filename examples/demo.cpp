// #define MAHI_GUI_NO_CONSOLE

#include <mahi/gui.hpp>
#include <iostream>

using namespace mahi::gui;

class Demo : public Application {
public:
    
    Demo() : Application(500,500,"Demo") {
        onFileDrop.connect(this, &Demo::fileDrop);
    }

    virtual void update() override {
        // Official ImGui demo (see imgui_demo.cpp for full example)
        ImGui::ShowDemoWindow();
        // A custom Window
        ImGui::Begin("My ImGui Window");
        if (ImGui::Button(ICON_FA_HOME))
            System::openUrl("https://mahilab.rice.edu/");
        ImGui::End();
    }

    void fileDrop(int count, const char** paths) {
        for (int i = 0;  i < count;  i++)
         std::cout << paths[i] << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Demo demo;
    demo.run();
    return 0;
}