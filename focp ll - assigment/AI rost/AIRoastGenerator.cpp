// Name: Your Name
// Roll No: XXXXXX
// Problem: AI Roast Generator
// Assignment 4 - FOCP II (Vibe Coding)

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to replace {name} placeholder with actual name
string replaceName(string roast, const string& name) {
    string placeholder = "{name}";
    size_t pos = roast.find(placeholder);
    while (pos != string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos = roast.find(placeholder, pos + name.length());
    }
    return roast;
}

int main() {
    // Seed random number generator so roasts change every run
    srand(time(0));

    // Store at least 10 roast templates
    vector<string> roastTemplates = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} asked AI to write their code and still got errors.",
        "Scientists studied {name}'s code and classified it as a natural disaster.",
        "{name} types so slowly, the compiler falls asleep waiting.",
        "The only thing {name} compiles successfully is excuses.",
        "{name}'s GitHub has more errors than commits.",
        "Even Stack Overflow gave up on {name}'s questions.",
        "{name} once tried to fix a bug and accidentally created three more.",
        "They say code never lies — but {name}'s code doesn't even make sense.",
        "If confusion had a face, it would look exactly like {name}'s code."
    };

    // Get user's name
    string name;
    cout << "=============================\n";
    cout << "   Welcome to Roast Generator\n";
    cout << "=============================\n";
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Name cannot be empty! Please enter a valid name.\n";
        return 1;
    }

    // Randomly select a roast
    int randomIndex = rand() % roastTemplates.size();
    string selectedRoast = replaceName(roastTemplates[randomIndex], name);

    // Display the roast
    cout << "\n🔥 Here is your roast, " << name << ":\n";
    cout << "------------------------------\n";
    cout << selectedRoast << "\n";
    cout << "------------------------------\n";
    cout << "\nRun the program again for a different roast!\n";

    return 0;
}
