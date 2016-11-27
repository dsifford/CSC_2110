
pub struct Person<'a> {
    first_name: &'a str,
    middle_name: &'a str,
    last_name: &'a str,
}

impl<'a> Person<'a> {
    pub fn new(first: &'a str, middle: &'a str, last: &'a str) -> Person<'a> {
        Person {
            first_name: first,
            middle_name: middle,
            last_name: last,
        }
    }
    pub fn print(&self) {
        println!("{} {} {}",
                 self.first_name,
                 self.middle_name,
                 self.last_name);
    }
    pub fn set_name(&mut self, first: &'a str, middle: &'a str, last: &'a str) {
        self.first_name = first;
        self.middle_name = middle;
        self.last_name = last;
    }
    pub fn set_firstname(&mut self, first: &'a str) {
        self.first_name = first;
    }
    pub fn set_middlename(&mut self, middle: &'a str) {
        self.middle_name = middle;
    }
    pub fn set_lastname(&mut self, last: &'a str) {
        self.last_name = last;
    }
    pub fn get_firstname(&self) -> &'a str {
        self.first_name
    }
    pub fn get_middlename(&self) -> &'a str {
        self.middle_name
    }
    pub fn get_lastname(&self) -> &'a str {
        self.last_name
    }
    pub fn firstname_equals<'b>(&self, comparator: &'b str) -> bool {
        self.first_name == comparator
    }
    pub fn lastname_equals<'b>(&self, comparator: &'b str) -> bool {
        self.last_name == comparator
    }
}
