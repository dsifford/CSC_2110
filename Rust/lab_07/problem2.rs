// Prints all and highest test scores for a fictional class

use std::io;
use std::io::BufRead;
use std::fs::File;

struct StudentType {
    first_name: String,
    last_name: String,
    test_score: u32,
    grade: char,
}

fn read_data(students: &mut Vec<StudentType>) {
    let file = match File::open("./students.txt") {
        Ok(f) => f,
        Err(_) => panic!("Error"),
    };
    let file = io::BufReader::new(file);
    for line in file.lines() {
        let mut parts = line.as_ref().unwrap().split_whitespace();
        let student = StudentType {
            last_name: parts.next().unwrap().to_string(),
            first_name: parts.next().unwrap().to_string(),
            test_score: parts.next().unwrap().parse().expect("Failed"),
            grade: 'U',
        };
        students.push(student);
    }
}

fn assign_grade(students: &mut Vec<StudentType>) {
    for student in students {
        student.grade = match student.test_score {
            score if score > 89 => 'A',
            score if score > 79 => 'B',
            score if score > 69 => 'C',
            score if score > 59 => 'D',
            _ => 'F',
        }
    }
}

fn find_highest_score(students: &Vec<StudentType>) -> u32 {
    let mut highest: u32 = 0;
    for student in students {
        if student.test_score > highest {
            highest = student.test_score;
        }
    }
    highest
}

fn print_data(students: &Vec<StudentType>, high_score: u32) {
    println!("The students with the highest score are:");
    for student in students {
        if student.test_score == high_score {
            println!("- {} {}", student.first_name, student.last_name);
        }
    }

    println!("\n\nStudent Grade Summary");
    for student in students {
        println!("{} {}, Score: {}, Grade: {}",
                 student.first_name,
                 student.last_name,
                 student.test_score,
                 student.grade);
    }
}

fn main() {
    let mut students: Vec<StudentType> = Vec::new();
    read_data(&mut students);
    assign_grade(&mut students);
    let highest = find_highest_score(&students);
    print_data(&students, highest);
}
