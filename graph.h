#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

class HotelGraph {
private:
    std::map<std::string, std::vector<std::string>> locations;

public:
    void addLocation(std::string name) {
        if (name.empty() || locations.count(name) > 0) {
            std::cout << "Invalid or duplicate location." << std::endl;
            return;
        }

        locations[name] = std::vector<std::string>();
    }

    void addConnection(std::string first, std::string second) {
        if (locations.count(first) == 0 ||
            locations.count(second) == 0 || first == second) {
            std::cout << "Invalid connection." << std::endl;
            return;
        }

        for (const std::string& neighbor : locations[first]) {
            if (neighbor == second) {
                std::cout << "Connection already exists." << std::endl;
                return;
            }
        }

        locations[first].push_back(second);
        locations[second].push_back(first);
    }

    void showLocations() const {
        for (const auto& location : locations) {
            std::cout << location.first << ":";

            for (const std::string& neighbor : location.second) {
                std::cout << " [" << neighbor << "]";
            }

            if (location.second.empty()) {
                std::cout << " No connections";
            }

            std::cout << std::endl;
        }
    }
};

#endif