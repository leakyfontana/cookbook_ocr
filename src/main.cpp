#include "crow.h"
#include "ocr_handler.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/ocr").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || body["imagePath"].s().size() == 0) {
            return crow::response(400, "Invalid request");
        }

        try {
            std::string result = processImage(body["imagePath"].s());
            return crow::response(result);
        } catch (const std::exception& e) {
            return crow::response(500, e.what());
        }
    });

    app.port(8081).multithreaded().run();
}
