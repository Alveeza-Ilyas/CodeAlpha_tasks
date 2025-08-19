#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map<string, string> users; // Stores username:password pairs
const string USER_FILE = "users.txt";

// Load users from file at startup
void loadUsers() {
    ifstream file(USER_FILE);
    string user, pass;
    while (file >> user >> pass) {
        users[user] = pass;
    }
}

// Save users to file
void saveUsers() {
    ofstream file(USER_FILE);
    for (auto& [user, pass] : users) {
        file << user << " " << pass << "\n";
    }
}

void registerUser() {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    
    if (users.count(user)) {
        cout << "Username taken!\n" << endl;
        return;
    }
    
    cout << "Enter password: ";
    cin >> pass;
    users[user] = pass;
    saveUsers(); // Save to file
    cout << "Registered successfully!\n" << endl;
}

void loginUser() {
    string user, pass;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;
    
    if (users.count(user) && users[user] == pass) {
        cout << "Login successfully!\n" << endl;
    } else {
        cout << "Login failed!\n" << endl;
    }
}

void exitSystem(){
	cout<<"Exiting System, Goodbye!\n";
}
int main() {
    loadUsers(); // Load existing users
    cout<<"\n---------------------------------------------Login and Registration System----------------------------------------------\n\n";
    int choice;
    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        
        if (choice == 1) {
        	registerUser();
		}
        else if (choice == 2) {
        	loginUser();
		}
        else if (choice == 3) {
        	exitSystem();
			break; 
		}
        else 
		    cout << "Invalid choice!\n";
    }
    return 0;
}