#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Request {
public:
    int id;
    std::string location;
    std::string problem;
    int urgency;
};

// priority_queue uses this rule to decide which request comes first.
class CompareRequests {
public:
    bool operator()(const Request &a, const Request &b) const {
        if (a.urgency == b.urgency) {
            return a.id > b.id;
        }
        return a.urgency > b.urgency;
    }
};

class Maintenance {
private:
    std::priority_queue<Request, std::vector<Request>, CompareRequests> requests;
    int nextId;

public:
    Maintenance() {
        nextId = 1;
    }

    void addRequest(std::string location, std::string problem, int urgency) {
        if (location.empty() || problem.empty() || urgency < 1 || urgency > 3) {
            std::cout << "Invalid request. Use a location, problem, and urgency 1-3."
                      << std::endl;
            return;
        }

        Request request;
        request.id = nextId;
        request.location = location;
        request.problem = problem;
        request.urgency = urgency;
        requests.push(request);
        nextId++;

        std::cout << "Added request #" << request.id << std::endl;
    }

    void showNext() const {
        if (requests.empty()) {
            std::cout << "No pending requests." << std::endl;
            return;
        }

        Request request = requests.top();
        std::cout << "Request #" << request.id << std::endl;
        std::cout << "Location: " << request.location << std::endl;
        std::cout << "Problem: " << request.problem << std::endl;
        std::cout << "Urgency: " << request.urgency << std::endl;
    }

    void completeNext() {
        if (requests.empty()) {
            std::cout << "No pending requests." << std::endl;
            return;
        }

        std::cout << "Completed request #" << requests.top().id << std::endl;
        requests.pop();
    }
};

#endif
