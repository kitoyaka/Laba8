#include <iostream>
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int callBack(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    std::string ip;
    std::cout << "enter your ip: ";
    std::cin >> ip;

    CURL* curl;
    CURLcode res;
    std::string acceptionFromServer;
    json jsonData;

    std::string apiKey = "f8813025c0ba4cedaffa4848c058db35";
    std::string url = "https://api.ipgeolocation.io/ipgeo?apiKey=" + apiKey + "&ip=" + ip;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &acceptionFromServer);


        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cerr << "unable request: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            jsonData = json::parse(acceptionFromServer);
            std::cout << "Time zone: : " << jsonData["time_zone"]["name"] << std::endl;
            std::cout << "Date time: " << jsonData["time_zone"]["current_time"] << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    system("pause");
    return 0;
}
