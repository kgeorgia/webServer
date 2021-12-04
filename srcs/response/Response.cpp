/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:08:43 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/11/21 19:27:02 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

Response::Response(const char *filepath)
{
    int size_file;
    std::string line;
    std::ifstream infile(filepath);

    while (getline(infile, line))
        body += line;
    
    size_file = body.size();
    header = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
    header += std::to_string(size_file);
    header += "\n\n";
}

const char    *Response::response()
{
    std::string tmp;

    tmp = header + body;
    return (tmp.c_str());
}

Response::~Response()
{
}