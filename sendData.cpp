#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "appdev.h"
#include "main.cpp"
#include "x64/Debug/Appdev.exe/"

void send_data(rock r) {
    CURL* curl;
    CURLcode res;
    char poststr[100];
    sprintf(poststr, "min=%d&max=%d&user=%s", r.min, r.max, r.rname);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cc.puv.fi/~e2101097/appdev.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}