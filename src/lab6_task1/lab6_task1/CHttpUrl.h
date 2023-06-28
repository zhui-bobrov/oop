#pragma once

const std::string INVALID_DOMAIN_SYMBLES = "<>\"\':?$#!&\\";

enum class Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP);

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	Protocol GetProtocol() const;
	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	unsigned short GetPort() const;
	void PrintUrl() const;

private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	void ParseProtocol(const std::string& url);
	void ParseDomain(const std::string& url);
	void ParsePort(const std::string& url);
	void ParseDocument(const std::string& url);

	void InitProtocol(const std::string& protocol);
	void InitDomain(const std::string& domain);
	void InitDocument(const std::string& document);
	void InitPort(std::string& port);
	void InitStandartPort();
	void InitStandartDocument();
};