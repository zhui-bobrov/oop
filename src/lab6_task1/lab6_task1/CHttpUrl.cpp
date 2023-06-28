#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

CHttpUrl::CHttpUrl(std::string const& url)
{	
	try
	{
		ParseProtocol(url);
		ParseDomain(url);
		ParsePort(url);
		ParseDocument(url);
	}
	catch (std::exception& e)
	{
		throw std::invalid_argument(e.what());
	}
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
{
	m_protocol = protocol;
	try
	{
		InitDomain(domain);
		InitDocument(document);
		InitStandartPort();
	}
	catch (std::exception& e)
	{
		throw std::invalid_argument(e.what());
	}
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
{
	m_port = port;
	m_protocol = protocol;
	try
	{
		InitDomain(domain);
		InitDocument(document);
	}
	catch (std::exception& e)
	{
		throw std::invalid_argument(e.what());
	}
}

void CHttpUrl::ParseProtocol(const std::string& url)
{
	size_t protocolEnd = url.find("://");
	if (protocolEnd == std::string::npos)
	{
		throw CUrlParsingError("Missing protocol\n");
	}

	std::string protocolStr = url.substr(0, protocolEnd);
	InitProtocol(protocolStr);
}

void CHttpUrl::ParseDomain(const std::string& url)
{
	size_t domainStart = url.find("://") + 3; 

	size_t urlDelimiter1 = url.find("/", domainStart);
	size_t urlDelimiter2 = url.find(":", domainStart);
	size_t domainEnd = urlDelimiter1 < urlDelimiter2 ? urlDelimiter1 : urlDelimiter2;
	if (domainEnd != std::string::npos)
	{
		domainEnd -= domainStart;
	}

	std::string domainStr = url.substr(domainStart, domainEnd);
	InitDomain(domainStr);
}

void CHttpUrl::ParsePort(const std::string& url)
{
	size_t domainStart = url.find("://") + 3;
	size_t urlDelimiter1 = url.find("/", domainStart);
	size_t urlDelimiter2 = url.find(":", domainStart);
	size_t portStart = urlDelimiter2 != std::string::npos ? urlDelimiter2 + 1 : std::string::npos;
	size_t portEnd = urlDelimiter1 != std::string::npos ? urlDelimiter1 - portStart : std::string::npos;

	if (portStart == std::string::npos)
	{
		InitStandartPort();
	}
	else
	{
		std::string portStr = url.substr(portStart, portEnd);
		InitPort(portStr);
	}
}

void CHttpUrl::ParseDocument(const std::string& url)
{
	size_t domainStart = url.find("://") + 3;
	size_t documentStart = url.find("/", domainStart);

	if (documentStart == std::string::npos)
	{
		InitStandartDocument();
	}
	else
	{
		std::string documentStr = url.substr(documentStart);
		InitDocument(documentStr);
	}
}

void CHttpUrl::InitProtocol(const std::string& protocol)
{
	if (protocol == "http")
	{
		m_protocol = Protocol::HTTP;
	}
	else if (protocol == "https")
	{
		m_protocol = Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid protocol\n");
	}
}

void CHttpUrl::InitDomain(const std::string& domain)
{
//	if (domain.empty() || domain == "" || domain.find_first_of(INVALID_DOMAIN_SYMBLES))
	if (domain.empty() || domain == "")
	{
		throw CUrlParsingError("Invalid domain\n");
	}
	else
	{
		m_domain = domain;
	}
}

void CHttpUrl::InitDocument(const std::string& document)
{
	if (document.empty() || document == "")
	{
		InitStandartDocument();
	}
	else
	{
		m_document = document;
	}
}

void CHttpUrl::InitPort(std::string& port)
{
	int portTmp;
	try
	{
		portTmp = std::stoi(port);
	}
	catch (const std::exception&)
	{
		throw CUrlParsingError("Invalid port\n");
	}

	if (portTmp < 1 || portTmp > 65535)
	{
		throw CUrlParsingError("Invalid port range\n");
	}
	m_port = static_cast<unsigned short>(portTmp);
}

void CHttpUrl::InitStandartPort()
{	
	try
	{
		m_port = GetProtocol() == Protocol::HTTP ? 80 : 443;
	}
	catch (const std::exception&)
	{
		throw CUrlParsingError("Invalid URL: can't init port via protocol\n");
	}
}

void CHttpUrl::InitStandartDocument()
{
	m_document = "/";
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}
std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::GetUrl() const
{
	std::ostringstream url;

	url << (GetProtocol() == Protocol::HTTP ? "http" : "https") << "://"
		<< GetDomain()
		<< ":" << GetPort()
		<< GetDocument();

	return url.str();
}

void CHttpUrl::PrintUrl() const
{
	std::cout << "URL: " << GetUrl() << std::endl;
	std::cout << "Protocol: " << (GetProtocol() == Protocol::HTTP ? "http" : "https") << std::endl;
	std::cout << "Domain: " << GetDomain() << std::endl;
	std::cout << "Port: " << GetPort() << std::endl;
	std::cout << "Document: " << GetDocument() << std::endl;
	std::cout << "-----------------" << std::endl;
}