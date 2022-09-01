#pragma once

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <string>
#include <exception>

#include "Logger.hpp"

using namespace boost::asio;
using namespace boost::asio::ip;
using boost::asio::ip::tcp;

class Client
{
public:
	Client();
	Client(std::string ip, int port);
	~Client();

	void Connect();
	void Disconnect();
	void BeginMessaging();

private:
	std::string _ip;
	int _port;;

	io_service _service;

	void Write(tcp::socket& socket, std::string message);
	void Read(tcp::socket& socket, std::string message);

	Logger* _logger = new Logger();
};

