/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:08:43 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/12/16 16:48:00 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

Response::mapMethods   InitAllowMethods(void) {
	Response::mapMethods res;

	res["GET"] = &Response::HandlerGetMethod;
	res["POST"] = &Response::HandlerPostMethod;
	res["HEAD"] = &Response::HandlerPostMethod;
	res["PUT"] = &Response::HandlerPostMethod;
	res["DELETE"] = &Response::HandlerPostMethod;
	res["OPTIONS"] = &Response::HandlerPostMethod;
	res["TRACE"] = &Response::HandlerPostMethod;

	return res;
}

std::map<int, std::string> InitPossibleErrors(void) {
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

void    Response::InitHeaders(void) {
	headers["Allow"] = "";
	headers["Content-Language"] = "";
	headers["Content-Length"] = "";
	headers["Content-Location"] = "";
	headers["Content-Type"] = "";
	headers["Date"] = "";
	headers["Last-Modified"] = "";
	headers["Location"] = "";
	headers["Retry-After"] = "";
	headers["Server"] = "WebServer/1.0.0 kegeorgia";
	headers["Transfer-Encoding"] = "identity";
	headers["WWW-Authenticate"] = "";	

}

std::map<int, std::string> Response::possibleErrors = initPossibleErrors();
Response::mapMethods Response::allowMethods = initAllowMethods();

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

	InitHeaders();
	this->protocol = request->protocol;
	auto method = this->allowMethods.find(request.getMethod());
	if (method != this->allowMethods.end()) {
		auto ret = method->second(request);
		statusCode = std::to_string(ret);
		statusText = possibleErrors[ret];
	}
	else {
		statusCode = std::to_string(405);
		statusText = possibleErrors[405];
	}
	SetHeaders(request);
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