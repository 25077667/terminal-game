#ifndef NETWORKING_HPP
#define NETWORKING_HPP

#include "crow_all.h"
#include "role.hpp"

enum BattleMode { single,
                  battle,
                  teamWork };
void init() {
    int selectMode;
    std::cout << "Which mode do you want to play? (1. single, 2. battle, 3. teamwork)" << std::endl;
    std::cin >> selectMode;
    BattleMode battleMode;
    switch (selectMode) {
        case 1:
            battleMode = single;
            break;
        case 2:
            battleMode = battle;
            break;
        case 3:
            battleMode = teamWork;
            break;
        default:
            battleMode = single;
            break;
    }
}
void syncTeammate(std::map<unsigned int, Object::Teammate>& team) {
    using namespace std;
    crow::SimpleApp app;

    CROW_ROUTE(app, "/syncTeammate")
        .methods("POST"_method)([](const crow::request& req) {
            auto x = crow::json::load(req.body);
            if (!x)
                return crow::response(400);

            if(team.find(x["id"]) == team.end()){
                team[x["id"]] = Object::Teammate()
            }else{
                team[x["id"]].setCorrdinates(x["row"], x["column"]);
                team[x["id"]].setHP(x["hp"]);
                team[x["id"]].setATK(x["attack"]);
                team[x["id"]].setDEF(x["defense"]);
                team[x["id"]].setAttribite(x["attribute"]);
                team[x["id"]].setCorrdinates(x["row"], x["column"]);
            }

            return crow::response(200);
        });

    app.port(3001).multithreaded().run();
}
void syncMe() {}
void handleSync() {}

#endif