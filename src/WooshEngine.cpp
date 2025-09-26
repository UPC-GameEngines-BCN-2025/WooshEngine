#include "WooshEngine.h"

void SetImGuiTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // ---- COLORS ----
    // Borders
    colors[ImGuiCol_WindowBg] = ImVec4(0.08f, 0.05f, 0.12f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.06f, 0.14f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.12f, 0.07f, 0.16f, 0.95f);
    colors[ImGuiCol_Border] = ImVec4(0.35f, 0.35f, 0.45f, 0.60f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

    // Frames
    colors[ImGuiCol_FrameBg] = ImVec4(0.18f, 0.10f, 0.26f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.35f, 0.18f, 0.50f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.45f, 0.22f, 0.60f, 1.00f);

    // Titles
    colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.00f, 0.35f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.50f, 0.00f, 0.65f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.15f, 0.00f, 0.20f, 0.75f);

    // Scroll
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.12f, 0.08f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.05f, 0.10f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.50f, 0.60f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.50f, 0.50f, 0.60f, 0.80f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);

    // Chechkmark & Slider
    colors[ImGuiCol_CheckMark] = ImVec4(0.85f, 0.85f, 0.95f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.60f, 0.90f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.80f, 1.00f, 1.00f);

    // Button
    colors[ImGuiCol_Button] = ImVec4(0.30f, 0.10f, 0.50f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.20f, 0.75f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.65f, 0.30f, 0.90f, 1.00f);

    // Header
    colors[ImGuiCol_Header] = ImVec4(0.30f, 0.15f, 0.45f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.25f, 0.60f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.60f, 0.30f, 0.75f, 1.00f);

    // Separator & Resizer
    colors[ImGuiCol_Separator] = ImVec4(0.45f, 0.45f, 0.55f, 0.60f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.60f, 0.60f, 0.70f, 0.50f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.75f, 0.75f, 0.85f, 0.75f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.90f, 0.90f, 1.00f, 1.00f);

    // Text
    colors[ImGuiCol_Text] = ImVec4(0.90f, 0.88f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.65f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.85f, 0.85f, 0.95f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.70f, 0.60f, 0.90f, 1.00f);

    // Window & Others Rounding
    style.WindowRounding = 8.0f;
    style.FrameRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.ScrollbarRounding = 8.0f;
    style.TabRounding = 4.0f;
}

void HeaderMenu(bool &running, bool &show_window_test0, bool &show_window_test1, bool &show_window_imGuiDemo, bool &show_window_about) // WIP G.- Would like to store all show_ variables in an array, don't know how yet.
{
    // ---- MAIN MENU BAR (TOP LEFT) ----
    if (ImGui::BeginMainMenuBar()){
        // File 
        if (ImGui::BeginMenu("File")){
            if (ImGui::MenuItem("Exit")) { running = false; }
            ImGui::EndMenu();
        }

        // View
        if (ImGui::BeginMenu("View")){
            if (ImGui::MenuItem("Show Window Test 0", nullptr, show_window_test0)) { show_window_test0 = !show_window_test0; }
            if (ImGui::MenuItem("Show Window Test 1", nullptr, show_window_test1)) { show_window_test1 = !show_window_test1; }
            if (ImGui::MenuItem("Show ImGui Demo", nullptr, show_window_imGuiDemo)) { show_window_imGuiDemo = !show_window_imGuiDemo; }
            ImGui::EndMenu();
        }

        // Help
        if (ImGui::BeginMenu("Help")){
            if (ImGui::MenuItem("Github Documentation")) { OpenLink("https://www.cultofpedagogy.com/wp-content/uploads/2020/03/IDK-Featured.png"); } // WIP G.- We need documentation to update this link.
            if (ImGui::MenuItem("Report a Bug")) { OpenLink("https://github.com/UPC-GameEngines-BCN-2025/WooshEngine/issues"); }
            if (ImGui::MenuItem("Download Latest")) { OpenLink("https://github.com/UPC-GameEngines-BCN-2025/WooshEngine/releases"); }
            if (ImGui::MenuItem("About")) { show_window_about = !show_window_about; }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void OpenLink(const char* url) {
#if defined(_WIN32) // For Windows
    std::string command = "start " + std::string(url);
    std::system(command.c_str());
#elif defined(__APPLE__) // For Mac
    std::string command = "open " + std::string(url);
    std::system(command.c_str());
#else // For Linux
    std::string command = "xdg-open " + std::string(url);
    std::system(command.c_str());
#endif
}

int main()
{
    // ---- INITIALISE SDL ----
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("WooshEngine",
        800, 600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    // ---- INITIALISE ImGui ----
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;     // Uncomment in case we want to have windows outside the main window, creating other viewports

    // Change ImGui Style
    SetImGuiTheme();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL3_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 150");

    // ---- GAME LOOP ----
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event); // Forward your event to backend
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
                running = false;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport();

        // Windows
        if (show_window_test0){
            ImGui::Begin("Test 0");
            ImGui::Text("Working Correctly");
            ImGui::ArrowButton("Arrow", ImGuiDir_Down);
            ImGui::End();
        }
        if (show_window_test1){
            ImGui::Begin("Test 1");
            ImGui::Text("Working Correctly");
            ImGui::Button("Press me", { 80,20 });
            ImGui::End();
        }
        if (show_window_imGuiDemo){
            ImGui::ShowDemoWindow();
        }
        if (show_window_about)
        {
            ImGui::SetNextWindowSize(ImVec2(400, 300));
            ImGui::Begin("About");
            ImGui::Text("Text I do not want to write."); // WIP G. - Write text, obviously
            if (ImGui::Button("Exit", { 80,20 })) { show_window_about = !show_window_about; }
            ImGui::End();
        }
        
        HeaderMenu(running, show_window_test0, show_window_test1, show_window_imGuiDemo, show_window_about);

        // ---- RENDERING ----
        ImGui::Render();
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT); // Clear OpenGl Color and Depth buffers
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window); // Swapping the images in Frontbuffer and backbuffer
    }

    // ---- CLEANUP ----
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}