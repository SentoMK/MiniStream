#pragma once

#include <SDL3/SDL.h>

#include <iostream>
#include <string>

class Player {
public:
  Player()  = default;
  ~Player() = default;
  // 初始化 SDL 窗口和渲染器
  bool init(const std::string &title, int w, int h) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
      std::cerr << "SDL_Init Error: " << SDL_GetError() << '\n';
      return false;
    }

    // SDL3: SDL_CreateWindow(title, width, height, flags)
    window = SDL_CreateWindow(title.c_str(),
                              w,
                              h,
                              0 // 普通可见窗口，若要全屏用 SDL_WINDOW_FULLSCREEN
    );
    if (!window) {
      std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << '\n';
      cleanup();
      return false;
    }
    SDL_ShowWindow(window);

    // SDL3: SDL_CreateRenderer(window, driver_name)
    // 传 nullptr 让 SDL 自动选择最佳渲染驱动
    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
      std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << '\n';
      cleanup();
      return false;
    }
    std::cout << "[Info] SDL initialized and window shown successfully.\n";
    return true;
  }

  // 主循环：处理退出事件并清屏
  void run() {
    SDL_Event e;
    bool      running = true;
    while (running) {
      while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT) {
          running = false;
        }
      }
      // 清屏为黑色
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      // TODO: 在这里绘制视频帧

      SDL_RenderPresent(renderer);
    }
  }

  // 清理资源
  void cleanup() {
    if (renderer)
      SDL_DestroyRenderer(renderer);
    if (window)
      SDL_DestroyWindow(window);
    SDL_Quit();
  }

private:
  SDL_Window   *window   = nullptr;
  SDL_Renderer *renderer = nullptr;
};
