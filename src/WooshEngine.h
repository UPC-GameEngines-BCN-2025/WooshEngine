#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <imgui.h>
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

#include <cstdlib> 

void SetImGuiTheme();
void HeaderMenu(bool &running, bool &show_window_test0, bool &show_window_test1, bool &show_window_ImGuiDemo, bool &show_window_about);

void OpenLink(const char* url);

int main();

bool show_window_test0 = true;
bool show_window_test1 = true;
bool show_window_imGuiDemo = true;
bool show_window_about = false;