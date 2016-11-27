// Program to calculate the winner of some election

use std::io;

struct Candidate {
    lastname: String,
    votes: u32,
}

fn get_candidate() -> Candidate {
    let mut lastname = String::new();
    let mut votes = String::new();

    println!("Enter the candidate's last name.");
    io::stdin().read_line(&mut lastname).expect("Failed");

    println!("Enter his/her number of votes");
    io::stdin().read_line(&mut votes).expect("Failed");

    Candidate {
        lastname: lastname.trim().parse().expect("Failed to parse string"),
        votes: votes.trim().parse().expect("Failed to parse u32"),
    }
}

fn count_votes(candidates: &Vec<Candidate>) -> u32 {
    let mut total: u32 = 0;
    for c in candidates {
        total += c.votes;
    }
    total
}

fn get_winner_index(candidates: &Vec<Candidate>) -> usize {
    let mut index: usize = 0;
    let mut highest_votes: u32 = 0;
    for (i, candidate) in candidates.iter().enumerate() {
        if candidate.votes > highest_votes {
            highest_votes = candidate.votes;
            index = i;
        }
    }
    index
}

fn main() {
    let mut candidate_list: Vec<Candidate> = Vec::new();

    for _ in 1..6 {
        candidate_list.push(get_candidate());
    }

    let vote_count = count_votes(&candidate_list);
    let winner_index = get_winner_index(&candidate_list);

    println!("Results:");
    for c in &candidate_list {
        println!("{} received {} votes", c.lastname, c.votes);
    }

    println!("-----------------------------");
    println!("The winner is {}", candidate_list[winner_index].lastname);
}
