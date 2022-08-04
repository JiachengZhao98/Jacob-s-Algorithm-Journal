#include "unordered_map"
#include "string"
#include "unordered_set"
#include "map"
#include "iostream"
using namespace std;

class Solution {
public:
    unordered_map<string, string> user;
    unordered_map<string, string> login;

    void Register(string username, string password) {
        if (user.find(username) != user.end()) {
            cout<<"Username already exists";
        }
        else {
            user.insert(pair<string, string>(username, password));
            cout<<"Registered Succcessfully";
        }
    }

    void Login(string username, string password) {
        auto iter = user.find(username);
        if (iter == user.end() || iter->second != password) {    // users have not registered, or users enter their username incorrectly
                                                                 // or users enter their password incorrectly
            cout<<"Login Unsuccessful";
            return;
        }
        else {
            if (login.find(iter->first) != login.end()) {        // users have already logged in
                cout<<"Login Unsuccessful";
            }
            else {
                login.insert(pair<string, string>(username, password));
                cout<<"Logged In Successfully";
            }
        }
    }

    void Logout(string username) {
        auto iter = login.find(username);
        if (iter == login.end()) {
            cout<<"Logout Unsuccessful";
        }
        else {
            login.erase(iter);
            cout<<"Logged Out Successfully";
        }
    }
};



int main() {
    Solution sol;
    sol.Register("Jacobzhao98", "zjczjc666");
    cout<<endl;
    sol.Logout("Jacobzhao98");
    cout<<endl;
    sol.Login("Jacobzhao98", "zjczjc666");
    cout<<endl;
    sol.Login("Jacobzhao98", "zjczjc666");
    cout<<endl;
}