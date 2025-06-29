#define ASIO_STANDALONE
#define ASIO_DISABLE_THREADS

#include "tcp_server.hpp"
#include<iostream>

int main() {
    try {
        asio::io_context io_context;
        TcpServer server(io_context, 8080);
        server.start();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
