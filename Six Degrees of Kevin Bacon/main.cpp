//
//  main.cpp
//  Seven Degrees of Kevin Bacon
//
//  Created by Ashwin on 9/29/23.
//

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
#include <list>
#include <crow.h>
#define CROW_MAIN

using namespace std;
struct Node {
    string name;
    std::vector<struct Node*> adj;
    //bool isMovie;
};
Node* createNode(string n){
  Node* node = new Node();
  node->name = n;
  //node->isMovie = is;
  return node;
}
void deleteNode(Node* todelete){
  todelete->name.clear();
  todelete->adj.clear();
  delete(todelete);
}
/*
void insertActor(std::map <string,Node*> a, string act, Node* mov){

}



vector<Node*> BFS(Node* start){
  vector<Node*> vopen;
  vopen.push_back(start);
  vector<Node*> vclosed;
  while (!vopen.empty()){
    //cout << "going thru vopen" << endl;
    Node* u = vopen.back();
    vopen.pop_back();
    vclosed.push_back(u);
    vector<Node*> exploring;
    exploring = u->adj;
    for(unsigned int i =0; i<exploring.size();i++){
      cout << "exploring item" << exploring.at(i)->name << endl;
      if(find(vclosed.begin(), vclosed.end(), exploring.at(i)) == vclosed.end()){
        if(find(vopen.begin(), vopen.end(), exploring.at(i)) == vopen.end()){
          vopen.push_back(exploring.at(i));
        }
      }
    }
  }

  return vclosed;
}
*/

string BFS(Node* start, Node* end){
  unordered_map<string,string> pred;
  unordered_map<string,bool> visited;
  visited.insert({start->name,true});
  queue<Node*> q;
  q.push(start);
  while(!q.empty()){
    Node* u = q.front();
    q.pop();
    for(unsigned int i = 0; i < u->adj.size();i++){
      Node* movie = u->adj.at(i);
      //cout << "checking movie" << u->adj.at(i)->name << endl;
      for(unsigned int j = 0; j < movie->adj.size();j++){
        //cout << "exploring item" << movie->adj.at(j)->name << endl;
        Node* actorc = movie->adj.at(j);
        if(visited.count(actorc->name)==0){
          //cout << "not visited" << endl;
          if(pred.count(movie->name) == 0){
            pred.insert({movie->name,u->name});
          }
          else{
            pred[movie->name] = u->name;
          }
          if(pred.count(actorc->name) == 0){
            pred.insert({actorc->name,movie->name});
          }
          else{
            pred[actorc->name] = movie->name;
          }
          if(actorc->name == end->name){
            //output << "-------------------PRED----------------------" << endl;
            /*
            for (auto it = pred.cbegin(); it != pred.cend(); ++it) {
                output << (*it).first << ": ";
                output << pred[(*it).first] << " ";
                output << endl;
            }
             */
            /*
            output << pred["Giovanni_Savoia"] << endl;
            output << pred["The_Audition"] << endl;
            output << pred["Darrin_Giossi"] << endl;
            output << pred["Unusual_People"] << endl;
            output << pred["April_Elizabeth"] << endl;
            output << pred["Sally_&_Wayne"] << endl;
            output << pred["William_Frederick_Knight"] << endl;
            output << pred["Small_Things"] << endl;
            output << pred["Holgie_Forrester"] << endl;
            output << pred["As_Evil_Does"] << endl;
            output << pred["Bill_Cobbs"] << endl;
            output << pred["Stroll"] << endl;
            output << pred["Michael_Epp"] << endl;
            output << pred["Behind_Locked_Doors:_The_Triangle_Fire"] << endl;
            output << pred["Beth_Adler"] << endl;
            output << pred["The_Evil_Eyes"] << endl;
            output << pred["Gyda_Arber"] << endl;
            output << pred["Small_Time"] << endl;
            output << pred["Jason_Godbey"] << endl;
            output << pred["The_Auteur"] << endl;
            output << pred["Brianna_Hansen"] << endl;
            output << pred["Singularity"] << endl;
            output << pred["Eric_Engleman"] << endl;
            output << pred["Some_Guy_Called_Toby"] << endl;
             */
            vector<string> path;
            string at = end->name;
            path.push_back(at);
            //cout << "added:" << at << endl;
            while(at != start->name){
              string adding = pred[at];
              //cout << "added: " << adding << endl;
              path.push_back(adding);
              at = adding;
            }
            //cout << "found" << endl;
            int n = path.size();
            reverse(path.begin(),path.end());
            string out = "";
            for(unsigned int i = 0;i < n;i++){
              if (isspace(path.at(i).back())){
              path.at(i).pop_back();
              }
              string input = path.at(i);
              input = input.substr(0, input.find(" "));
            out += input;
            if(i%2 == 0 && i < n-1){
              out += " -(";
            }
            else if(i < n-1){
              out += ")- ";
            }
            }
            //cout << out;
            pred.clear();
            visited.clear();
            queue<Node*> empty;
            swap(q,empty);
            return out;
          }
          visited.insert({actorc->name,true});
          q.push(actorc);
        }
      }
    }
  }
  pred.clear();
  visited.clear();
  return "Not Present";

}


//string BFS(Node* start, Node* end, std::unordered_map<string,Node*> actor){
  /*list<string> path;
  string first_actor = start->name;
  path.push_back(first_actor);
  unordered_map<string,bool> visited;
  visited[first_actor] = true;
  list<pair<string,list<string>>> q;
  q.push_back({first_actor, path});
  while(!q.empty()){
      path = q.front().second;
      first_actor = q.front().first;
      q.pop_front();
      if(path.back() == end->name){
          auto current = path.cbegin();
          auto last = path.cend();
          string ref;
          while (current != last)
          {
             ref = *current;   // take a reference   // modify the copy

            // prove that modifying the copy does not change the string
            // in the list
            std::cout << ref << std::endl;

            // move the iterator to the next in the list
            current = std::next(current, 1);
            // or simply ++current;
          }
          return ref;
      }
      else{
          auto itr = actor[first_actor]->adj.front();
          while(itr != actor[first_actor]->adj.back()){
              if(!visited[itr->name]){
                  list <string> temp = path;
                  visited[itr->name] = true;
                  path.push_back(itr->name);
                  q.push_back({itr->name,path});
                  path = temp;
              }
              itr++;
          }
      }

  }
  return "Not Present";
  
  q.push_back({first_actor,path});
    queue<Node*> q;
    q.push(start);
    while(!q.empty()){
      Node* actori = q.front();
      q.pop();
      for (unsigned int i = 0; i < actori->adj.size();i++){
        Node* movie = actori->adj.at(i);
        for(unsigned int j = 0; j < movie->adj.size();j++){
          Node* actorc = movie->adj.at(i);
          if (visited[actorc->name] == false){
            if(pred.count(movie->name) == 0){
              pred.insert({movie->name,actori->name});
            }
            else{
              pred[movie->name] = actori->name;
            }
            if(pred.count(actorc->name) == 0){
              pred.insert({actorc->name,movie->name});
            }
            else{
              pred[actorc->name] = movie->name;
            }
            if (actorc->name == end->name){
              vector<string> path;
              string at = end->name;
              path.push_back(at);
              cout << "added:" << at << endl;
              while(at != start->name){
                string adding = pred[at];
                cout << "added: " << adding << endl;
                path.push_back(adding);
                at = adding;
            }
            //cout << "found" << endl;
              int n = path.size();
              reverse(path.begin(),path.end());
              string out = "";
              for(unsigned int i = 0;i < n;i++){
              if (isspace(path.at(i).back())){
                path.at(i).pop_back();
              }
              out += path.at(i);
              if(i%2 == 0 && i < n-1){
                out += " -(";
              }
              else if(i < n-1){
                out += ")- ";
              }
              }
            //cout << out;
              pred.clear();
              visited.clear();
              queue<Node*> empty;
              swap(q,empty);
              return out;
            }
            visited[actori->name] = true;
            q.push(actori);
              }

        }
      }
    }
    return "Not Present";

}
*/
/*
vector<Node*> pathFinder(Node* start, Node* end, vector<Node*> vclosed){
  vector<Node*> path;
  for(Node* at = end; at != NULL; at = vclosed[at]){
    path.push_back(at);
  }
  reverse(path.begin(),path.end());
}
*/


int main(int argc, char** argv)
{
    cout << "running";
    // Initialize Crow app
    ifstream text;
    text.open("/Users/ashwin/Downloads/Six Degrees of Kevin Bacon/Six Degrees of Kevin Bacon/cleaned_movielist.txt");
    if (!text.is_open()) {
        cout << "Failed to open cleaned_movielist.txt" << endl;
    }
    std::unordered_map<string,Node*> actors;
    std::set<string> movie_list;
    //setting all values to NULL
    string command;
    char* com;
    Node* actor;
    Node* movie;
    cout << "starting parse";
    //reading file and placing it into the respective LL
    while(getline(text,command)){
    cout << "readin" << endl;
        if (isspace(command.back())){
            command.pop_back();
        }
        string temp = "";
        string mov = "";
        int counter = 0;
        com = strdup(command.c_str());
        cout << com << endl;
        for(unsigned int i = 0; i<command.length(); i++){
            temp += com[i];
            counter++;
            if(isspace(com[i])){
                mov = temp;
                break;
            }
        }
        //cout << mov << endl;
        movie =  new Node();
        string check = mov;
        while(movie_list.count(check) == 1){
            check += " *";
        }
        mov = check;
        movie_list.insert(mov);
        movie->name = mov;
        //output << mov << endl;
        int k = counter;
        temp = "";
        for(unsigned int i = k; i < command.length(); i++){
            //cout << "i" << i << endl;
            if(!isspace(command.at(i))){
                temp += command.at(i);
            }
            else{
                //cout << temp << endl;
                //cout << "inserting actor: " << temp;
                if(actors.count(temp)==1){
                    //cout << "node exists" << endl;
                    (actors[temp]->adj).push_back(movie);
                    /*
                     for(unsigned int i = 0;i < actors[temp]->adj.size();i++){
                     //cout << actors[temp]->adj.at(i)->name << " ";
                     }
                     */
                    //(movie->adj).push_back(actors[temp]);
                }
                else if(actors.count(temp)==0){
                    //cout << "making new node" << endl;
                    actor =  new Node();
                    actor->name = temp;
                    (actor->adj).push_back(movie);
                    //cout << " acted in ";
                    /*
                     for(unsigned int i = 0;i <actor->adj.size();i++){
                     //cout << actor->adj.at(i)->name;
                     }
                     */
                    
                    //(movie->adj).insert(actor);
                    /*
                     for(unsigned int i = 0;i < movie->adj.size();i++){
                     cout << movie->adj.at(i)->name;
                     }
                     */
                    //cout << endl;
                    actors.insert({temp,actor});
                    //delete(actor);
                    //deleteNode(actor);
                }
                //Node* tnode =  actors[temp];
                movie->adj.push_back(actors.at(temp));
                //cout << "just inserted: " << (movie->adj).back()->name << endl;
                temp = "";
                
            }
        }
        //cout << movie->name << endl;;
        //std::cout << "inserting actor: " << temp;
        if(actors.count(temp)==1){
            //cout << "node exists" << endl;
            (actors[temp]->adj).push_back(movie);
            /*
             for(unsigned int i = 0;i < actors[temp]->adj.size();i++){
             //cout << actors[temp]->adj.at(i)->name << " ";
             }
             */
            //cout << endl;
            //(movie->adj).push_back(actors[temp]);
        }
        else if(actors.count(temp)==0){
            //cout << "making new node" << endl;
            actor =  new Node();
            actor->name = temp;
            (actor->adj).push_back(movie);
            //cout << " acted in ";
            /*
             for(unsigned int i = 0;i <actor->adj.size();i++){
             //cout << actor->adj.at(i)->name;
             }
             */
            //(movie->adj).insert(actor);
            /*
             for(unsigned int i = 0;i < movie->adj.size();i++){
             cout << movie->adj.at(i)->name;
             }
             */
            //cout << endl;
            actors.insert({temp,actor});
            //cout << "just inserted to map: " << actors[temp]->name << endl;
            //delete(actor);
            //deleteNode(actor);
        }
        //Node* tnode = actors[temp];
        movie->adj.push_back(actors.at(temp));
        //deleteNode(movie);
        //delete(movie);
        //delete(com);
        //cout << "just inserted: " << (movie->adj).back()->name << endl;
        //cout << "adj list for " << mov << ": ";
        /*
         for(unsigned int i = 0;i < movie->adj.size();i++){
         cout << movie->adj.at(i)->name;
         }
         cout << endl;
         
         for(unsigned int i = 0;i < (movie->adj).size();i++){
         cout << (movie->adj).at(i)->name << " ";
         }
         cout << endl;
         */
    }
    /*
    cout << "printing actors" << endl;
    for (auto it = actors.cbegin(); it != actors.cend(); ++it) {
            cout << (*it).first << ": ";
            for(unsigned int i = 0;i < (*it).second->adj.size();i++){
                    cout << (*it).second->adj.at(i)->name << " ";
            }
            cout << endl;
        }
     */
    crow::SimpleApp app;

    CROW_ROUTE(app, "/getDegrees")
    ([&](const crow::request& req) -> crow::response {
        string actor1_name = req.url_params.get("actor1");
        string actor2_name = req.url_params.get("actor2");
        
        if(actor1_name.empty() || actor2_name.empty()) {
            return crow::response(400, "Missing actor parameters");
        }
        
        string result;
        if(actors.count(actor1_name)==0 || actors.count(actor2_name)==0) {
            result = "Not present";
        } else if(actor1_name == actor2_name) {
            result = actor1_name;
        } else {
            Node* actor1 = actors[actor1_name];
            Node* actor2 = actors[actor2_name];
            result = BFS(actor1, actor2);
        }
        cout << result;
        crow::json::wvalue x;
        x["result"] = result;
        
        crow::response res = crow::response(x);
        res.set_header("Access-Control-Allow-Origin", "*"); // Allow any origin
        return res;
    });

        app.port(18080).multithreaded().run();
        for (auto it = actors.cbegin(); it != actors.cend(); ++it) {
            Node* temp = (*it).second;
            delete temp;
        }
        actors.clear();
           
        }
