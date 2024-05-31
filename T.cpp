#include <iostream>
#include <vector>
#include <string>

class Candidate {
public:
    std::string name;
    int votes;

    Candidate(std::string name) : name(name), votes(0) {}
};

void displayCandidates(const std::vector<Candidate>& candidates) {
    std::cout << "Candidates:\n";
    for (size_t i = 0; i < candidates.size(); ++i) {
        std::cout << i + 1 << ". " << candidates[i].name << "\n";
    }
}

void castVote(std::vector<Candidate>& candidates) {
    int choice;
    std::cout << "Enter the number of the candidate you want to vote for: ";
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(candidates.size())) {
        candidates[choice - 1].votes++;
        std::cout << "Vote casted for " << candidates[choice - 1].name << "\n";
    } else {
        std::cout << "Invalid choice. Please try again.\n";
    }
}

void displayResults(const std::vector<Candidate>& candidates) {
    std::cout << "\nVote Results:\n";
    for (const auto& candidate : candidates) {
        std::cout << candidate.name << ": " << candidate.votes << " votes\n";
    }
}

int main() {
    int numCandidates;
    std::cout << "Enter the number of candidates: ";
    std::cin >> numCandidates;

    std::vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; ++i) {
        std::string name;
        std::cout << "Enter the name of candidate " << i + 1 << ": ";
        std::cin >> name;
        candidates.emplace_back(name);
    }

    char continueVoting;
    do {
        displayCandidates(candidates);
        castVote(candidates);

        std::cout << "Do you want to cast another vote? (y/n): ";
        std::cin >> continueVoting;
    } while (continueVoting == 'y' || continueVoting == 'Y');

    displayResults(candidates);

    return 0;
}