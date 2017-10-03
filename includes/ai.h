#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/filestream.h>
#include <string>
#include <thread>
#include <vector>

#include "utils.h"
#include "DataStructures.h"

using namespace std;
using namespace utility;
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
using namespace web::json;                  // JSON API
using namespace web::http::experimental::listener;

class AI {

public:

    AI(string playerName_);
    void run();
    int saveState();
    void requestHandler(http_request req);
    vector<vector<Tile>> deserializeMap(string serializedMap);

private:

    std::string playerName;
    std::string stateFilePath = "/tmp/state.phx";
    http_listener listener;

};
