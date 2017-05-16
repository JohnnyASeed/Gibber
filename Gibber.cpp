#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>

using namespace std;

struct CONFIG {
	string target;
	string proxy;
};

string CONFIG_PATH = "CONFIG.txt";

int CONFIG_ERROR = 0;

CONFIG Load_Config();
int Connect(string target, string proxy);

int main(void)
{
	CONFIG session_config = Load_Config();

	if (CONFIG_ERROR == 0)
	{
		Connect(session_config.target, session_config.proxy);
	}

	system("PAUSE");
	return 0;
}

CONFIG Load_Config()
{
	ifstream CONFIG_FILE;
	CONFIG_FILE.open(CONFIG_PATH);

	string TARGET;
	string PROXY;

	CONFIG temp_config;

	if (CONFIG_FILE.is_open())
	{
		getline(CONFIG_FILE, TARGET);
		getline(CONFIG_FILE, PROXY);

		temp_config.target = TARGET.c_str();
		temp_config.proxy = PROXY.c_str();
	}

	else
	{
		CONFIG_ERROR = 1;
		cout << "ERROR: UNABLE TO OPEN CONFIG FILE" << endl;
	}
	return temp_config;
}

int Connect(string target, string proxy)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_PROXY, proxy.c_str());
		curl_easy_setopt(curl, CURLOPT_URL, target.c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L);
		
		/*
		PUT OTHER CURL_EASY_SETOPT FUNCTIONS HERE
		MORE INFO AT: https://curl.haxx.se/libcurl/c/curl_easy_setopt.html 		
		*/

		res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);

		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
			curl_easy_cleanup(curl);
		}
		curl_global_cleanup();
	}

	return 0;
}
