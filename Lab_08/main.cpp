/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 23.10.2016
 * Description: Program to calculate the winner of some election
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct Candidate {
    string lastName;
    int votes;
};


Candidate getCandidate();
int parseVotes(Candidate[5]);
Candidate parseVotes(Candidate[5], bool getWinner);


int main() {

    Candidate candidateList[5];

    for (int i = 0; i < 5; i++) {
        candidateList[i] = getCandidate();
    }

    int totalVotes = parseVotes(candidateList);
    Candidate winner = parseVotes(candidateList, true);

    cout << "\nHere's the Results:" << endl;

    cout << fixed << setprecision(1);

    for (Candidate i : candidateList) {
        printf("%s received %d votes (%.1f%%)\n", i.lastName.c_str(), i.votes,
            ( (static_cast<double>(i.votes) / static_cast<double>(totalVotes)) * 100 )
        );
    }

    cout << "-----------------------------------" << endl;
    cout << "The winner is " << winner.lastName << endl;

    return 0;
}


Candidate getCandidate() {

    Candidate input;

    cout << "Enter the candidate's last name." << endl;
    cin >> input.lastName;

    cout << "Enter his/her number of votes" << endl;
    cin >> input.votes;

    return input;

}

int parseVotes(Candidate candidateList[5]) {

    int totalVotes = 0;

    for (int i = 0; i < 5; i++) {
        totalVotes += candidateList[i].votes;
    }

    return totalVotes;
}

Candidate parseVotes(Candidate candidateList[5], bool getWinner) {

    Candidate winner;

    for (int i = 0; i < 5; i++) {
        if (candidateList[i].votes > winner.votes)
            winner = candidateList[i];
    }

    return winner;
}