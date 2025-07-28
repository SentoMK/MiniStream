#include "Player.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "[DBG] main() entered" << std::endl;
    Player player;
    std::cout << "[DBG] about to init()" << std::endl;
    if (!player.init("MiniStream Demo", 800, 600))
    {
        std::cerr << "[DBG] init() failed" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "[DBG] init() succeeded, entering run()" << std::endl;
    player.run();
    std::cout << "[DBG] run() returned, cleaning up" << std::endl;
    player.cleanup();
    std::cout << "[DBG] exiting normally" << std::endl;
    return EXIT_SUCCESS;
}
