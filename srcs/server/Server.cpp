/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:07:22 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/13 18:13:05 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() {
    server_fd = -1;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    memset(address.sin_zero, 0, sizeof(address.sin_zero));
}

Server::Server(Server &other) {
    server_fd = other.server_fd;
    address.sin_family =AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    memset(address.sin_zero, 0, sizeof(address.sin_zero));
}

Server::~Server() {
    ::close(server_fd);
}

void    Server::start(void) {
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << RED << "Failed to create socket. errno: " << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) < 0) {
        std::cerr << RED << "Failed to bind to port. errno: " << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        std::cerr << RED << "Failed to listen on socket. errno" << errno << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
}


void    Server::accept(void) {
    long socket;

    socket = accept(server_fd, NULL, NULL);
    if (socket = -1) {
        std::cerr << RED << "Could not create socket. " << strerror(errno) << RESET << '\n';
    }
    else {
        fcntl(socket, F_SETFL, O_NONBLOCK);
        requests[socket] = "";
    }
}

int    Server::readRequest(long socket) {
    char    buffer[65536] = {0};
    int     ret;

    ret = recv(socket, buffer, 65535, 0);
    if (ret == 0 || ret == -1) {
        close(socket);
        return -1;
    }

    requests[socket] += std::string(buffer);
}

void    Server::process(void) {
    int ret;
    int tmp_socket;
    int addr_len = sizeof(address);
    Response res("./test/index.html");

    while(42) {
        std::cout << std::endl << "-------------| Waiting new connection |-------------" << std::endl;
        if ((tmp_socket = accept(server_fd, reinterpret_cast<sockaddr *>(&address),
            reinterpret_cast<socklen_t*>(&addr_len))) < 0) {
            std::cerr << "Error in accept" << std::endl;
            exit(EXIT_FAILURE);
        }

        while (42) {
            char buffer[65536] = {0};
            ret = recv( tmp_socket, buffer, sizeof(buffer), 0);
            std::string tmp_string(buffer);
            if (tmp_string != "") {
                Request tmp(tmp_string);
                tmp.printAll();
                if (ret > 0) {
                    send(tmp_socket, res.response(), strlen(res.response()), 0);
                }
                if (ret == 0 || ret == -1) {
                    ::close(tmp_socket);
                    break;
                }
                    
            }
            
            std::cout << "flag\n";
        }
        ::close(tmp_socket);
    }
    ::close(server_fd);
}