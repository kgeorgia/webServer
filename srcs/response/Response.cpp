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

std::map<std::string, void (Response::*)(const Request&)>   initAllowMethods(void) {
    std::map<std::string, void (Response::*)(const Request&)> res;

    res["GET"] = &Response::HandlerGetMethod;
    res["POST"] = &Response::HandlerPostMethod;
    res["HEAD"] = &Response::HandlerPostMethod;
    res["PUT"] = &Response::HandlerPostMethod;
    res["DELETE"] = &Response::HandlerPostMethod;
    res["OPTIONS"] = &Response::HandlerPostMethod;
    res["TRACE"] = &Response::HandlerPostMethod;

    return res;
}

std::map<int, std::string> initPossibleErrors(void) {
    std::map<int, std::string> res;

    res[100] = "Continue";
    res[200] = "OK";
    res[201] = "Created";
    res[204] = "No Content";
    res[400] = "Bad Request";
    res[403] = "Forbidden";
    res[404] = "Not Found";
    res[405] = "Method Not Allowed";
    res[413] = "Payload Too Large";
    res[500] = "Internal Server Error";

    return res;
}

std::map<int, std::string> Response::possibleErrors = initPossibleErrors();

std::map<std::string, void (Response::*)(const Request&)> Response::allowMethods = initAllowMethods();

// Response::Response(const char *filepath)
// {
//     int size_file;
//     std::string line;
//     std::ifstream infile(filepath);

//     while (getline(infile, line))
//         body += line;
    
//     size_file = body.size();
//     header = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
//     header += std::to_string(size_file);
//     header += "\n\n";
// }

Response::Response(const Request &request) {

    this->protocol = request->protocol;
    
}

const char    *Response::response()
{
    std::string tmp;

    // tmp = header + body;
    return (tmp.c_str());
}

Response::~Response()
{
}