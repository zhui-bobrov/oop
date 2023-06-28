#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../lab6_task1/CHttpUrl.h"
#include "../lab6_task1/CUrlParsingError.h"

TEST_CASE("Protocol (http) Test")
{
	CHttpUrl httpUrl("http://ya.ru");
	REQUIRE(httpUrl.GetProtocol() == Protocol::HTTP);
}

TEST_CASE("Protocol (https) Test")
{
	CHttpUrl httpUrl("https://ya.ru");
	REQUIRE(httpUrl.GetProtocol() == Protocol::HTTPS);
}

TEST_CASE("Missing Protocol Tests", "[!throws]")
{
	CHECK_THROWS_WITH(CHttpUrl("ya.ru"), "Missing protocol\n");
}

TEST_CASE("Invalid Protocol Tests")
{
	CHECK_THROWS_WITH(CHttpUrl("://ya.ru"), "Invalid protocol\n");
	CHECK_THROWS_WITH(CHttpUrl("htt://ya.ru"), "Invalid protocol\n");
	CHECK_THROWS_WITH(CHttpUrl("fttp://ya.ru"), "Invalid protocol\n");
}

TEST_CASE("Domain Test")
{
	CHttpUrl httpUrl1("http://ya.ru");
	CHECK(httpUrl1.GetDomain() == "ya.ru");

	CHttpUrl httpUrl2("http://ya");
	CHECK(httpUrl2.GetDomain() == "ya");

	CHttpUrl httpUrl3("http://ya/");
	CHECK(httpUrl3.GetDomain() == "ya");

	CHttpUrl httpUrl4("http://ya:80/");
	CHECK(httpUrl4.GetDomain() == "ya");

	CHttpUrl httpUrl5("http://ya.zhiza:80/");
	CHECK(httpUrl5.GetDomain() == "ya.zhiza");
}

TEST_CASE("Invalid Domain Test")
{
	CHECK_THROWS_WITH(CHttpUrl("https://"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("https:///"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("http://:"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("http:///png.zhpg"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("http://:/png.zhpg"), "Invalid domain\n");
}
/*
TEST_CASE("Invalid Domain Symbols Test")
{
	CHECK_THROWS_WITH(CHttpUrl("https://ya?ru"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("https://:ya$ru"), "Invalid domain\n");
	CHECK_THROWS_WITH(CHttpUrl("https://'"), "Invalid domain\n");
}
*/
TEST_CASE("Port Test")
{
	CHttpUrl httpUrl1("http://ya.ru:1");
	CHECK(httpUrl1.GetPort() == 1);
	CHttpUrl httpUrl2("http://ya.ru:1/");
	CHECK(httpUrl2.GetPort() == 1);

	CHttpUrl httpUrl3("http://ya.ru:65535");
	CHECK(httpUrl3.GetPort() == 65535);
	CHttpUrl httpUrl4("http://ya.ru:65535/");
	CHECK(httpUrl4.GetPort() == 65535);

	CHttpUrl httpUrl5("http://ya.ru:69");
	CHECK(httpUrl5.GetPort() == 69);
	CHttpUrl httpUrl6("http://ya.ru:69/");
	CHECK(httpUrl6.GetPort() == 69);
}

TEST_CASE("Standart Port Test")
{
	CHttpUrl httpUrl1("http://ya.ru");
	CHECK(httpUrl1.GetPort() == 80);
	CHttpUrl httpUrl2("https://ya.ru");
	CHECK(httpUrl2.GetPort() == 443);

	CHttpUrl httpUrl3("http://ya.ru:443");
	CHECK(httpUrl3.GetPort() == 443);
	CHttpUrl httpUrl4("https://ya.ru:80");
	CHECK(httpUrl4.GetPort() == 80);
}

TEST_CASE("Invalid Port Test")
{
	CHECK_THROWS_WITH(CHttpUrl("http://ya:"), "Invalid port\n");
	CHECK_THROWS_WITH(CHttpUrl("https://ya:/"), "Invalid port\n");
	CHECK_THROWS_WITH(CHttpUrl("http://ya:port/"), "Invalid port\n");
	CHECK_THROWS_WITH(CHttpUrl("https://ya:port"), "Invalid port\n");
	CHECK_THROWS_WITH(CHttpUrl("https://ya:p0rt"), "Invalid port\n");
}
TEST_CASE("Invalid Port Range Test")
{
	CHECK_THROWS_WITH(CHttpUrl("http://ya:0"), "Invalid port range\n");
	CHECK_THROWS_WITH(CHttpUrl("https://ya:-1"), "Invalid port range\n");
	CHECK_THROWS_WITH(CHttpUrl("https://ya:65536/"), "Invalid port range\n");
}

TEST_CASE("Document Test")
{
	CHttpUrl httpUrl1("http://ya.ru/");
	CHECK(httpUrl1.GetDocument() == "/");
	CHttpUrl httpUrl2("https://ya.ru//");
	CHECK(httpUrl2.GetDocument() == "//");

	CHttpUrl httpUrl3("http://ya.ru:443/png.zhpg");
	CHECK(httpUrl3.GetDocument() == "/png.zhpg");
	CHttpUrl httpUrl4("https://ya.ru:80/pif-paf/");
	CHECK(httpUrl4.GetDocument() == "/pif-paf/");

	CHttpUrl httpUrl5("http://ya.ru/.");
	CHECK(httpUrl5.GetDocument() == "/.");
	CHttpUrl httpUrl6("https://ya.ru/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////s");
	CHECK(httpUrl6.GetDocument() == "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////s");
}

TEST_CASE("Standart Document Test")
{
	CHttpUrl httpUrl1("http://ya.ru");
	CHECK(httpUrl1.GetDocument() == "/");
	CHttpUrl httpUrl2("https://ya");
	CHECK(httpUrl2.GetDocument() == "/");
	CHttpUrl httpUrl3("https://y");
	CHECK(httpUrl3.GetDocument() == "/");
}
