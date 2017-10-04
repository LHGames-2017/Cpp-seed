#include "ai.h"

AI::AI(string playerName_) {
        playerName = playerName_;
        uri serverURI("http://0.0.0.0:5046/");
        uri_builder builder;
        listener = http_listener(serverURI);
        listener.open().wait();
}

vector<vector<Tile>> AI::deserializeMap(string serializedMap) {

    serializedMap = serializedMap.substr(1, serializedMap.length() - 1);
    vector<string> rows = split(serializedMap, '[');
    vector<string> column = split(rows[1], '{');
    vector<vector<Tile>> map;

    for (int i = 0; i < rows.size() - 1; i++) {
        column = split(rows[i + 1], '{');
        for (int j = 0; j < column.size() - 1; j++)
        {
            vector<string> infos = split(column[j + 1], ',');
            map[i].push_back(Tile(atoi(infos[0].c_str()), atoi(infos[1].c_str()), atoi(infos[2].substr(0, infos[2].find('}')).c_str())));
        }
    }
    return map;

}

void AI::requestHandler(http_request request) {

    json::value body;

    request.extract_json().get();

    cout << body[U("Map")] << endl;

    request.reply(status_codes::OK, U("ALLO SIMON"));

}

void AI::run() {

    listener.support(methods::POST, bind(&AI::requestHandler, this, std::placeholders::_1));


}

int main(int argc, char* argv[]) {

    string playerName;

    std::cout << "Enter your player name: " << std::endl;

    std::cin >> playerName;

    AI* bot = new AI(playerName);

    bot->run();

    while (true) {
        this_thread::sleep_for(chrono::milliseconds(1));
    };

}
