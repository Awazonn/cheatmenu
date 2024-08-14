#include <imgui.h>
#include <Windows.h>

bool show_menu = false;
const int TOGGLE_KEY = VK_INSERT; // Insert key to toggle menu

bool IsKeyPressed(int key)
{
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

void HandleKeybinds()
{
    static bool key_pressed = false;

    if (IsKeyPressed(TOGGLE_KEY))
    {
        if (!key_pressed)
        {
            show_menu = !show_menu;
            key_pressed = true;
        }
    }
    else
    {
        key_pressed = false;
    }
}

void RenderUI()
{
    HandleKeybinds();

    if (!show_menu)
        return;

    ImGui::SetNextWindowSize(ImVec2(300, 400), ImGuiCond_FirstUseEver);
    ImGui::Begin("Awazon Cheat", &show_menu);

    if (ImGui::CollapsingHeader("Aimbot"))
    {
    }

    if (ImGui::CollapsingHeader("ESP"))
    {
    }

    if (ImGui::CollapsingHeader("GUI Color"))
    {
    }

    ImGui::End();
}

void Update()
{

    RenderUI();

}
