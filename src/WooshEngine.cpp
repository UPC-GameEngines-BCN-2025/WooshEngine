#include "WooshEngine.h"

int main()
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create window
    SDL_Window* window = SDL_CreateWindow("WooshEngine", 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Initialize Open GL
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);

    // Initialize GLAD
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplSDL3_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 150");

    // Engine main loop
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);

            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE){
                running = false;
            }
        }

        // ImGui Update
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        // Open ImGui window
        ImGui::Begin("Inspector"); // Name
        ImGui::Text("This is the inspector."); // Content
        ImGui::End();

        // ImGui Render
        ImGui::Render();
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}