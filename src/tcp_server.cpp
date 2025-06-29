#define ASIO_STANDALONE
#define ASIO_DISABLE_THREADS

#include "tcp_server.hpp"
#include <iostream>

using asio::ip::tcp;

TcpServer::TcpServer(asio::io_context& io_context, int port)
    : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {}

void TcpServer::start() {
    std::cout << "Server listening on port "
              << acceptor_.local_endpoint().port() << "...\n";
    accept_and_respond();
}

void TcpServer::accept_and_respond() {
    for (;;) {
        tcp::socket socket(io_context_);
        acceptor_.accept(socket);

        std::string message = "Hello from standalone Asio TCP server!\n";
        asio::write(socket, asio::buffer(message));

        std::cout << "Responded to a client.\n";
    }
}
