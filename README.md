README

Gibber is intended to be an example implementation of the cURL library which can connect to
a target url through a proxy of your choice. This code reads configuration settings
from a text file (i.e. the target url and proxy address) and then uses 
curl_easy_perform() to connect to the target.

Programmers, experienced and not, are encouraged to experiment with this code. Please be 
advised that the author accepts no liability whatsoever should you choose to 
misuse or abuse this code.

CONFIG

The configuration file, "CONFIG.TXT", should be placed in the same folder as the compiled 
executable. The file currently consists of two lines as follows:

https://check.torproject.org/
socks5h://Localhost:9150

The first line is the target url and the second is the proxy address. The default 
configuration provided will return the html source for "https://check.torproject.org/".
The proxy chosen by default is the address of the tor proxy server. In order to connect 
to this address tor.exe must be running. Other proxy addresses should always be entered 
according to the specifications laid out here: 
https://curl.haxx.se/libcurl/c/CURLOPT_PROXY.html. 

Using the default configuration, the program output should contain the following 
line: <p>Your IP address appears to be:   <strong>xxx.xxx.xxx.xxx</strong></p>

You may then confirm that this IP address is a tor node by searching for the address
on the Tor Atlas

COMPILING

In order to compile Gibber you must download libcurl library which may be
found at: https://curl.haxx.se/download.html and link it to your project.

NOTICE

Gibber contains example code provided by cURL and consequently may contain pieces of
source that is subject to Copyright. You may find cURL examples at:
https://curl.haxx.se/libcurl/c/example.html. 


