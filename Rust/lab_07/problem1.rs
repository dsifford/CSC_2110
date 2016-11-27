// Program to find the "last largest index" of an i32 array

fn last_largest_index(arr: &[i32]) -> i32 {
    let mut index: i32 = 0;
    let mut largest: i32 = arr[0];
    for (i, n) in arr.iter().enumerate() {
        if n >= &largest {
            index = i as i32;
            largest = *n;
        }
    }
    index
}

fn main() {
    let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    println!("last largest index = {}", last_largest_index(&arr)); // 9

    let arr = [23, 5, 26, 46, 2, 24, 7, 2, 5];
    println!("last largest index = {}", last_largest_index(&arr)); // 3
}
