#include <imgui.h>

#include "menu.hpp"

#include "core/helpers/input.hpp"

#include "context/dota.hpp"
#include "context/config.hpp"
#include <customgui.h>
#include "customfont.h"

namespace Menu
{
	bool bIsVisible = false;

	ImGuiIO* pIO = nullptr;

	void Setup( )
	{
		pIO = &ImGui::GetIO( );
		pIO->ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

        pIO->Fonts->AddFontFromMemoryCompressedTTF(light_compressed_data, light_compressed_size, 14);

		CustomGUI::fonts::SFUIlight_default = pIO->Fonts->AddFontFromMemoryCompressedTTF(light_compressed_data, light_compressed_size, 14);
		CustomGUI::fonts::SFUIlight_big = pIO->Fonts->AddFontFromMemoryCompressedTTF(light_compressed_data, light_compressed_size, 18);

		CustomGUI::fonts::SFUIbold_default = pIO->Fonts->AddFontFromMemoryCompressedTTF(bold_compressed_data, bold_compressed_size, 12);
		CustomGUI::fonts::SFUIbold_big = pIO->Fonts->AddFontFromMemoryCompressedTTF(bold_compressed_data, bold_compressed_size, 18);
		CustomGUI::fonts::SFUIbold_bigger = pIO->Fonts->AddFontFromMemoryCompressedTTF(bold_compressed_data, bold_compressed_size, 20);

		CustomGUI::fonts::ICONS_default = pIO->Fonts->AddFontFromMemoryCompressedTTF(icons_compressed_data, icons_compressed_size, 14);
		CustomGUI::fonts::ICONS_big = pIO->Fonts->AddFontFromMemoryCompressedTTF(icons_compressed_data, icons_compressed_size, 32);

		ImGui::StyleColorsDark();

		Input::RegisterCallback( VK_INSERT, Toggle );
	}

	void Render( )
	{
		if ( !bIsVisible )
			return;

        ImVec2 position;
        ImDrawList* draw;

        static int tab = 0;
        static int subtab = 0;

        // FLAGS
        auto window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;

        // ATRIBUTES
        ImGui::SetNextWindowSize({ 800,550 });

        // STYLES
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 4);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, 1);

        // COLORS
        ImGui::PushStyleColor(ImGuiCol_WindowBg, { 235 / 255.f,235 / 255.f,235 / 255.f,255 / 255.f });
        ImGui::PushStyleColor(ImGuiCol_Text, { 70 / 255.f,70 / 255.f,70 / 255.f,255.f / 255.f });
        ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, { 35.f / 255.f,35.f / 255.f,35.f / 255.f,0 / 255.f });

        ImGui::Begin(PROJECT_NAME, nullptr, window_flags);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        {
            position = ImGui::GetWindowPos();
            draw = ImGui::GetWindowDrawList();

            draw->AddRectFilled(ImVec2{ position.x + 180,position.y + 50 }, ImVec2{ position.x + 800,position.y + 550 }, ImColor(229 / 255.f, 229 / 255.f, 231 / 255.f, 255 / 255.f), 4, ImDrawFlags_RoundCornersBottomRight);
            draw->AddLine(ImVec2{ position.x + 180,position.y }, ImVec2{ position.x + 180,position.y + 550 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 70.f / 255.f));
            draw->AddLine(ImVec2{ position.x,position.y + 50 }, ImVec2{ position.x + 800,position.y + 50 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 70.f / 255.f));


            draw->AddLine(ImVec2{ position.x + 200,position.y + 90 }, ImVec2{ position.x + 780,position.y + 90 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 100.f / 255.f));

            ImGui::PushFont(CustomGUI::fonts::SFUIlight_default);
            draw->AddText({ position.x + 20,position.y + 70 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "FEATURES");
            draw->AddText({ position.x + 20,position.y + 210 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "INFORMATION");
            ImGui::PopFont();

            ImGui::PushFont(CustomGUI::fonts::SFUIlight_default);
            draw->AddText({ position.x + 20,position.y + 50 / 2 - ImGui::CalcTextSize("SCALUX").y / 2 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "SCALUX");
            ImGui::PopFont();

            {
                ImGui::SetCursorPos({ 20, 90 });
                if (CustomGUI::Tab("Combat", "1", tab == 0, { 140,25 }))
                    tab = 0;

                ImGui::SetCursorPos({ 20, 120 });
                if (CustomGUI::Tab("Visuals", "2", tab == 1, { 140,25 }))
                    tab = 1;

                ImGui::SetCursorPos({ 20, 150 });
                if (CustomGUI::Tab("Misc", "3", tab == 2, { 140,25 }))
                    tab = 2;

                ImGui::SetCursorPos({ 20, 180 });
                if (CustomGUI::Tab("Settings", "4", tab == 3, { 140,25 }))
                    tab = 3;

                ImGui::SetCursorPos({ 20, 230 });
                if (CustomGUI::Tab("Dashboard", "a", tab == 4, { 140,25 }))
                    tab = 4;
            }
            {
                if (tab == 0)
                {
                    ImGui::SetCursorPos({ 200, 66 });
                    if (CustomGUI::SubTab("Main", subtab == 0, { 63,25 }))
                        subtab = 0;

                    ImGui::SetCursorPos({ 270, 66 });
                    if (CustomGUI::SubTab("Heroes", subtab == 1, { 77,25 }))
                        subtab = 1;
                }
                if (tab == 1)
                {
                    ImGui::SetCursorPos({ 200, 66 });
                    if (CustomGUI::SubTab("ESP", subtab == 0, { 41,25 }))
                        subtab = 0;

                    //ImGui::SetCursorPos({ 246, 66 });
                    //if (CustomGUI::SubTab("CHAMS", subtab == 1, { 62,25 }))
                    //    subtab = 1;


                    //ImGui::SetCursorPos({ 246 + 62 + 5, 66 });
                    //if (CustomGUI::SubTab("GLOW", subtab == 2, { 55,25 }))
                    //    subtab = 2;
                }
                if (tab == 4)
                {
                    ImGui::SetCursorPos({ 200, 66 });
                    if (CustomGUI::SubTab("NEWS", subtab == 0, { 55,25 }))
                        subtab = 0;
                }
            }
            {
                ImGui::SetCursorPos({ 200, 100 });
                ImGui::BeginChild("", ImVec2(580, 440));
                {
                    if (tab == 1)
                    {
                        if (subtab == 0)
                        {
                            CustomGUI::Checkbox("Recolor illusions", &CTX::Config->Visuals.m_bHighlighIllusions);
                            ImGui::SameLine();
                            CustomGUI::ColorEdit("##color", CTX::Config->Visuals.m_fIllusionCol);
                            CustomGUI::Checkbox("Show illusions", &CTX::Config->Visuals.m_bHighlighIllusions);
                            //ImGui::SameLine();
                            //CustomGUI::Checkbox("Auto-Shot", &checkbox);

                            //CustomGUI::Combo("Combo", &combo, ("DEFAULT\0\rSOMETHING\0\0"));
                            //ImGui::SameLine();
                            //CustomGUI::Combo("Combo 2", &combo, ("DEFAULT\0\rSOMETHING\0\0"));

                            //CustomGUI::SliderInt("Slider Int", &slider, 0, 1000, "%.3f");
                            //ImGui::SameLine(294);
                            //CustomGUI::SliderInt("Slider In 2t", &slider, 0, 1000, "%.3f");
                        }

                    }

                    if (tab == 4)
                    {
                        if (subtab == 0)
                        {
                            CustomGUI::News("Release", "Yeah");
                        }
                    }
                }
                ImGui::EndChild();
            }
        }
        ImGui::End();

        // STYLES
        ImGui::PopStyleVar(4);

        // COLORS
        ImGui::PopStyleColor(3);

	}

	void Toggle( )
	{
		bIsVisible = !bIsVisible;
	}

	bool IsVisible( )
	{
		return bIsVisible;
	}
}