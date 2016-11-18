/**
 * Program Name: main.cpp
 * Developer: Derek P Sifford
 * Date: 03.11.2016
 * Description: Program to calculate the winner of some election using dyanmic arrays
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
int parseVotes(Candidate[], int len);
Candidate parseVotes(Candidate[], int len, bool getWinner);

int main() {
    int numCandidates;

    cout << "Enter number of candidates: ";
    cin >> numCandidates;

    Candidate *candidateList = new Candidate[numCandidates];

    for (int i = 0; i < numCandidates; i++) {
        candidateList[i] = getCandidate();
    }

    int totalVotes = parseVotes(candidateList, numCandidates);
    Candidate winner = parseVotes(candidateList, numCandidates, true);

    cout << "\nHere's the Results:" << endl;

    cout << fixed << setprecision(1);

    for (size_t i = 0; i < numCandidates; i++) {
        double total = (static_cast<double>(candidateList[i].votes) / static_cast<double>(totalVotes)) * 100;
        printf(
            "%s received %d votes (%.1f%%)\n",
            candidateList[i].lastName.c_str(),
            candidateList[i].votes,
            total
        );
    }

    cout << "-----------------------------------" << endl;
    cout << "The winner is " << winner.lastName << endl;

    return 0;
}

/**
 * Helper function to create a single Candidate from data recieved from stdin
 * @return Candidate
 */
Candidate getCandidate() {
    Candidate input;

    cout << "Enter the candidate's last name." << endl;
    cin >> input.lastName;

    cout << "Enter his/her number of votes" << endl;
    cin >> input.votes;

    return input;
}

/**
 * Counts the total number of votes received for all candidates
 * @param  candidateList Array of candidates
 * @param  len           length of array
 * @return               total number of votes cast
 */
int parseVotes(Candidate candidateList[], int len) {
    int totalVotes = 0;

    for (int i = 0; i < len; i++) {
        totalVotes += candidateList[i].votes;
    }

    return totalVotes;
}

/**
 * Takes an array of Candidate and returns the candidate that received the
 *   greatest number of votes
 * @param  candidateList Array of Candidate
 * @param  len           length of array
 * @param  getWinner     boolean used to trigger the overload method
 * @return               Candidate with the greatest number of votes
 */
Candidate parseVotes(Candidate candidateList[], int len, bool getWinner) {
    Candidate winner;

    for (int i = 0; i < len; i++) {
        if (candidateList[i].votes > winner.votes)
            winner = candidateList[i];
    }

    return winner;
}