mod person;
use person::*;

fn main() {
    let mut p = Person::new("Derek", "Paul", "Sifford");

    p.set_name("John", "Quincy", "Adams");
    assert_eq!(p.get_firstname(), "John");
    assert_eq!(p.get_middlename(), "Quincy");
    assert_eq!(p.get_lastname(), "Adams");

    p.set_firstname("Derek");
    p.set_middlename("Paul");
    p.set_lastname("Sifford");

    assert_eq!(p.firstname_equals("Derek"), true);
    assert_eq!(p.firstname_equals("John"), false);
    assert_eq!(p.lastname_equals("Sifford"), true);
    assert_eq!(p.lastname_equals("Adams"), false);

    println!("Next line should print my name");
    p.print();
}
