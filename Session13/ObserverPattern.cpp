#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class ILogObserver {
public:
    virtual void onLogMessage(const std::string& message) = 0;
    virtual ~ILogObserver() = default;
};

class LoggerSubject {
public:
    void attach(std::shared_ptr<ILogObserver> observer) {
        observers.push_back(observer);
    }

    void log(const std::string& message) {
        std::cout << "[LoggerSubject] Logging: " << message << "\n";
        for (const auto& observer : observers) {
            observer->onLogMessage(message);
        }
    }

private:
    std::vector<std::shared_ptr<ILogObserver>> observers;
};

// Define ConsoleLogger class

// Define FileLogger class

// Define NetworkLogger class

int main() {
    LoggerSubject logger;

    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>("log.txt");
    auto networkLogger = std::make_shared<NetworkLogger>();

    logger.attach(consoleLogger);
    logger.attach(fileLogger);
    logger.attach(networkLogger);

    logger.log("Error: Disk space low.");
    logger.log("Warning: High memory usage.");

    return 0;
}
