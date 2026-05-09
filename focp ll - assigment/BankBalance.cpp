
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
using namespace std;

class Bank {
    // userID -> balance
    unordered_map<string, long long> accounts;

public:
    // CREATE X Y
    bool CREATE(const string& userID, long long amount) {
        if (accounts.count(userID)) {
            // User exists: add to balance, return false
            accounts[userID] += amount;
            return false;
        }
        // New account
        accounts[userID] = amount;
        return true;
    }

    // DEBIT X Y
    bool DEBIT(const string& userID, long long amount) {
        if (!accounts.count(userID))        return false; // user not found
        if (accounts[userID] < amount)      return false; // insufficient balance
        accounts[userID] -= amount;
        return true;
    }

    // CREDIT X Y
    bool CREDIT(const string& userID, long long amount) {
        if (!accounts.count(userID)) return false; // user not found
        accounts[userID] += amount;
        return true;
    }

    // BALANCE X
    long long BALANCE(const string& userID) {
        if (!accounts.count(userID)) return -1;
        return accounts[userID];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    while (Q--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        string query;
        iss >> query;

        if (query == "CREATE") {
            string userID;
            long long amount;
            iss >> userID >> amount;
            cout << (bank.CREATE(userID, amount) ? "true" : "false") << "\n";

        } else if (query == "DEBIT") {
            string userID;
            long long amount;
            iss >> userID >> amount;
            cout << (bank.DEBIT(userID, amount) ? "true" : "false") << "\n";

        } else if (query == "CREDIT") {
            string userID;
            long long amount;
            iss >> userID >> amount;
            cout << (bank.CREDIT(userID, amount) ? "true" : "false") << "\n";

        } else if (query == "BALANCE") {
            string userID;
            iss >> userID;
            cout << bank.BALANCE(userID) << "\n";
        }
    }

    return 0;
}
