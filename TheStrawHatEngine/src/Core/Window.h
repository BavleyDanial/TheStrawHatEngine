#pragma once
#include <GLFW/glfw3.h>

#include <string>

namespace TSH {

    struct WindowProperties
    {
        std::string title = "StrawHatTitle";
        uint32_t width = 1280;
        uint32_t height = 720;
        // TODO: Make the next values into a bit flags variable to save memory
        bool isFullScreen = false;
        bool isVsync = true;
    };

    class Window
    {
    public:
        Window() = default;

        void CreateWindow(const WindowProperties& windowProps);
        void DestroyWindow();

        void UpdateWindow();

        uint32_t GetWidth() { return mWindowProps.width; }
        uint32_t GetHeight() { return mWindowProps.height; }

        bool IsVSync() { return mWindowProps.isVsync; }
        bool IsFullScreen() { return mWindowProps.isFullScreen; }

    private:
        GLFWwindow* mpWindowHandle = nullptr; // TODO: make this a vector allocation, as there might be more than one window open at a time.
        WindowProperties mWindowProps;
    };

}