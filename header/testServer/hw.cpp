#include "../crow_all.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/helloworld")
    ([] {
        crow::json::wvalue x;
        x["message"] = "Hello, World!";
        return x;
    });

    app.port(3000).multithreaded().run();
}