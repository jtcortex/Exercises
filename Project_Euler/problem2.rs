/*
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

fn main(){
    let mut i = 0;
    let mut j = 1;
    let mut k = 2;
    let mut total = 2;

    while i < 4000000 {
        i = j + k;
        if i % 2 == 0 {
            total = total + i;
        }
        j = k;
        k = i;
    }
    println!("{}", total);
}