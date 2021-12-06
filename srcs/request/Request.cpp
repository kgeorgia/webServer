#include "Request.hpp"

Request::Request(const std::string &input) {
	this->initHeaders();
	this->parsing(input);
}

void    Request::initHeaders() {
	this->headers.clear();

	this->headers["Accept-Charsets"] = "";
	this->headers["Accept-Language"] = "";
	this->headers["Allow"] = "";
	this->headers["Auth-Scheme"] = "";
	this->headers["Authorization"] = "";
	this->headers["Content-Language"] = "";
	this->headers["Content-Length"] = "";
	this->headers["Content-Location"] = "";
	this->headers["Content-Type"] = "";
	this->headers["Date"] = "";
	this->headers["Host"] = "";
	this->headers["Last-Modified"] = "";
	this->headers["Location"] = "";
	this->headers["Referer"] = "";
	this->headers["Retry-After"] = "";
	this->headers["Server"] = "";
	this->headers["Transfer-Encoding"] = "";
	this->headers["User-Agent"] = "";
	this->headers["Www-Authenticate"] = "";
	this->headers["Connection"] = "Keep-Alive";
}

void    Request::parsing(const std::string &input) {
	size_t idx = 0;
	std::string line;

	line = this->nextLine(input, idx);
	this->parseFirstLine(line);

	while ((line = this->nextLine(input, idx)) != "\r" && line != "") {
		std::string key;
		key = this->parseKey(line);
		if (this->headers.count(key))
			this->headers[key] = this->parseValue(line);	
	}

	// this->body = input.substr(idx);
}

std::string Request::parseValue(const std::string &line) {
	size_t idx;
	std::string result;

	idx = line.find_first_of(": ");
	if (idx == std::string::npos)
		return "";
	result = line.substr(idx + 2);

	return result;
}

std::string Request::parseKey(const std::string &line) {
	size_t idx;
	std::string result;

	idx = line.find_first_of(": ");
	if (idx == std::string::npos)
		return "";
	result = line.substr(0, idx);
	return result;
}

void    Request::parseFirstLine(const std::string &line) {
	size_t idx = 0;
	size_t idxEnd = 0;
	
	idxEnd = line.find_first_of(' ', idx);
	if (idxEnd == std::string::npos)
		return;
	this->method = line.substr(idx, idxEnd - idx);

	idx = idxEnd + 1;
	idxEnd = line.find_first_of(' ', idx);
	if (idxEnd == std::string::npos)
		return;
	this->url = line.substr(idx, idxEnd - idx);

	idx = idxEnd + 1;
	if (idx == std::string::npos)
		return;
	this->protocol = line.substr(idx);
}

std::string    Request::nextLine(const std::string &input, size_t &idx) {
	size_t idxEnd;
	std::string result;
	
	if (idx == std::string::npos)
		return "";
	idxEnd = input.find_first_of('\n', idx);
	result = input.substr(idx, idxEnd - idx);
	if (idxEnd == std::string::npos)
		idx = idxEnd;
	else
		idx = idxEnd + 1;

	return result;
}

void	Request::printAll() {
	std::map<std::string, std::string>::iterator it;
	std::cout << "-----> Method <-----\n" << this->method << std::endl;
	std::cout << "-----> URL <-----\n" << this->url << std::endl;
	std::cout << "-----> Protocol <-----\n" << this->protocol << std::endl;
	
	for (it = this->headers.begin(); it != this->headers.end(); it++)
		std::cout << it->first << ": " << it->second << std::endl;

	std::cout << body << std::endl;
}

Request::~Request() {}