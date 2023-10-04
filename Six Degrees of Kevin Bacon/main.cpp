#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stdexcept>
#include <fstream>
#include <array>
#include <sstream>
#include <cstring>
#include <unordered_map>
#include <set>
#include <crow.h>
#define CROW_MAIN

using namespace std;

// Node structure representing an actor or a movie
struct Node {
    string name;
    std::vector<struct Node*> adj;
};

// Function to create a new node
Node* createNode(string n) {
    Node* node = new Node();
    node->name = n;
    return node;
}

// Function to delete a node
void deleteNode(Node* todelete) {
    todelete->name.clear();
    todelete->adj.clear();
    delete(todelete);
}

// Breadth First Search function to find the shortest path between two actors
string BFS(Node* start, Node* end) {
    unordered_map<string, string> pred;
    unordered_map<string, bool> visited;
    visited.insert({start->name, true});
    queue<Node*> q;
    q.push(start);
    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        for (unsigned int i = 0; i < u->adj.size(); i++) {
            Node* movie = u->adj.at(i);
            for (unsigned int j = 0; j < movie->adj.size(); j++) {
                Node* actorc = movie->adj.at(j);
                if (visited.count(actorc->name) == 0) {
                    if (pred.count(movie->name) == 0) {
                        pred.insert({movie->name, u->name});
                    } else {
                        pred[movie->name] = u->name;
                    }
                    if (pred.count(actorc->name) == 0) {
                        pred.insert({actorc->name, movie->name});
                    } else {
                        pred[actorc->name] = movie->name;
                    }
                    if (actorc->name == end->name) {
                        vector<string> path;
                        string at = end->name;
                        path.push_back(at);
                        while (at != start->name) {
                            string adding = pred[at];
                            path.push_back(adding);
                            at = adding;
                        }
                        int n = path.size();
                        reverse(path.begin(), path.end());
                        string out = "";
                        for (unsigned int i = 0; i < n; i++) {
                            if (isspace(path.at(i).back())) {
                                path.at(i).pop_back();
                            }
                            string input = path.at(i);
                            input = input.substr(0, input.find(" "));
                            out += input;
                            if (i % 2 == 0 && i < n - 1) {
                                out += " -(";
                            } else if (i < n - 1) {
                                out += ")- ";
                            }
                        }
                        pred.clear();
                        visited.clear();
                        queue<Node*> empty;
                        swap(q, empty);
                        return out;
                    }
                    visited.insert({actorc->name, true});
                    q.push(actorc);
                }
            }
        }
    }
    pred.clear();
    visited.clear();
    return "Not Present";
}

int main(int argc, char** argv) {
    ifstream text;
    text.open("cleaned_movielist.txt");
    if (!text.is_open()) {
        cout << "Failed to open cleaned_movielist.txt" << endl;
    }
    std::unordered_map<string, Node*> actors;
    std::set<string> movie_list;
    string command;
    char* com;
    Node* actor;
    Node* movie;

    // Parse the file and populate the data structures
    while (getline(text, command)) {
        if (isspace(command.back())) {
            command.pop_back();
        }
        string temp = "";
        string mov = "";
        int counter = 0;
        com = strdup(command.c_str());
        for (unsigned int i = 0; i < command.length(); i++) {
            temp += com[i];
            counter++;
            if (isspace(com[i])) {
                mov = temp;
                break;
            }
        }
        movie = new Node();
        string check = mov;
        while (movie_list.count(check) == 1) {
            check += " *";
        }
        mov = check;
        movie_list.insert(mov);
        movie->name = mov;
        int k = counter;
        temp = "";
        for (unsigned int i = k; i < command.length(); i++) {
            if (!isspace(command.at(i))) {
                temp += command.at(i);
            } else {
                if (actors.count(temp) == 1) {
                    (actors[temp]->adj).push_back(movie);
                } else if (actors.count(temp) == 0) {
                    actor = new Node();
                    actor->name = temp;
                    (actor->adj).push_back(movie);
                    actors.insert({temp, actor});
                }
                movie->adj.push_back(actors.at(temp));
                temp = "";
            }
        }
        if (actors.count(temp) == 1) {
            (actors[temp]->adj).push_back(movie);
        } else if (actors.count(temp) == 0) {
            actor = new Node();
            actor->name = temp;
            (actor->adj).push_back(movie);
            actors.insert({temp, actor});
        }
        movie->adj.push_back(actors.at(temp));
    }

    // Initialize Crow app
    crow::SimpleApp app;

    // Define the route for the Crow app
    CROW_ROUTE(app, "/getDegrees")
    ([&](const crow::request& req) -> crow::response {
        string actor1_name = req.url_params.get("actor1");
        string actor2_name = req.url_params.get("actor2");

        if (actor1_name.empty() || actor2_name.empty()) {
            return crow::response(400, "Missing actor parameters");
        }

        string result;
        if (actors.count(actor1_name) == 0 || actors.count(actor2_name) == 0) {
            result = "Not present";
        } else if (actor1_name == actor2_name) {
            result = actor1_name;
        } else {
            Node* actor1 = actors[actor1_name];
            Node* actor2 = actors[actor2_name];
            result = BFS(actor1, actor2);
        }

        crow::json::wvalue x;
        x["result"] = result;

        crow::response res = crow::response(x);
        res.set_header("Access-Control-Allow-Origin", "*"); // Allow any origin
        return res;
    });

    app.port(18080).multithreaded().run();

    // Clean up
    for (auto it = actors.cbegin(); it != actors.cend(); ++it) {
        Node* temp = (*it).second;
        delete temp;
    }
    actors.clear();
}
