#include "Client.h"

Client::Client()
{
}

Client::Client(std::string ip, int port)
{
	this->_ip = ip;
	this->_port = port;
}

Client::~Client()
{
	delete _logger;
}

void Client::Connect()
{
	tcp::endpoint endpoint(address::from_string(_ip), _port);
	tcp::socket socket(_service);

	try
	{
		socket.connect(endpoint);

		Write(socket, "hello");

		socket.close();
	}
	catch (std::exception& ex)
	{
		_logger->WriteFile("Something get wrong while connecting to local server. Src: Clent.hpp Connect(). Error is: " + std::string(ex.what()));
	}
}

void Client::Disconnect()
{
}

void Client::BeginMessaging()
{
}

void Client::Write(tcp::socket& socket, std::string message)
{
	boost::array<char, 256> buf;
	std::copy(message.begin(), message.end(), buf.begin());
	boost::system::error_code error;
	socket.write_some(buffer(buf, message.size()), error);

	if (!error) 
	{
		//Logger::GetInstanse().WriteNormal("no errors when writing");
	}
	else 
	{
		//Logger::GetInstanse().WriteNormal("some errors when writing " +  error.message());
	}
}

void Client::Read(tcp::socket& socket, std::string message)
{
	boost::system::error_code error;

	streambuf receiveBuf;
	read(socket, receiveBuf, transfer_all(), error);

	if (error && error != boost::asio::error::eof) 
	{
		//std::cout << "receive failed: " << error.message() << endl;
		//Logger::GetInstanse().WriteNormal("some errors when reading" + error.message());
	}
	else 
	{
		//const char* data = boost::asio::buffer_cast<const char*>(receiveBuf.data());
		//Logger::GetInstanse().WriteNormal("message from server: " + std::string(data));
		//cout << data << endl;
	}

}
